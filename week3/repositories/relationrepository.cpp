#include "repositories/relationrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <cstdlib>
#include <QtSql>

using namespace std;

RelationRepository::RelationRepository()
{
    db = utils::getDatabaseConnection();
}

vector<namePair> RelationRepository::findRelations(string name, string relateTo)
{
    cleanRelations();
    vector<namePair> results;

    if(db.open())
    {
        QSqlQuery query(db);

        string queryInsert = "SELECT c.name AS compName, s.name AS sciName"
                             " FROM compSciRelation sic"
                             " JOIN computers c"
                             " ON c.com_id = sic.com_id"
                             " JOIN scientists s"
                             " ON s.sci_id = sic.sci_id";

        if(relateTo == "Computers")
        {
            queryInsert += " WHERE compName LIKE '%" + name + "%'";
        }
        else if (relateTo == "Scientists")
        {
            queryInsert += " WHERE sciName LIKE '%" + name + "%'";
        }
        else
        {
            queryInsert += " WHERE compName LIKE '%" + name + "%' OR sciName LIKE '%" + name + "%'";
        }

        query.exec(QString(queryInsert.c_str()));
        while(query.next())
        {
            namePair relation;
            string compName = query.value("compName").toString().toStdString();
            string sciName = query.value("sciName").toString().toStdString();
            relation.compName = compName;
            relation.sciName = sciName;
            results.push_back(relation);
        }

        db.close();
    }
    return results;
}

bool RelationRepository::addRelation(string compName, string sciName)
{
    if(db.open())
    {
        QSqlQuery query(db);
        string queryInsert = "CREATE TABLE IF NOT EXISTS compSciRelation("
                "com_id INTEGER,"
                "sci_id INTEGER,"
                "FOREIGN KEY (com_id) REFERENCES computers(com_id),"
                "FOREIGN KEY (sci_id) REFERENCES scientists(sci_id),"
                "PRIMARY KEY (com_id, sci_id)"
                ")";
        query.exec(QString(queryInsert.c_str()));

        queryInsert = "SELECT com_id FROM computers WHERE name LIKE '" + compName + "'";
        if(!query.exec(QString(queryInsert.c_str())))
        {
            db.close();
            return false;
        }
        query.next();
        if(query.isNull("com_id"))
        {
            db.close();
            return false;
        }
        string compId = query.value("com_id").toString().toStdString();

        queryInsert = "SELECT sci_id FROM scientists WHERE name LIKE '" + sciName + "'";
        if(!query.exec(QString(queryInsert.c_str())))
        {
            db.close();
            return false;
        }
        query.next();
        if(query.isNull("sci_id"))
        {
            db.close();
            return false;
        }
        string sciId = query.value("sci_id").toString().toStdString();

        queryInsert = "INSERT INTO compSciRelation VALUES ('" + compId + "','" + sciId + "')";
        if(query.exec(QString(queryInsert.c_str())))
        {
            db.close();
            return true;
        }
    }
    db.close();
    return false;
}

bool RelationRepository::removeRelation(string compName, string sciName)
{
    if(db.open())
    {
        QSqlQuery query(db);

        string queryInsert = "DELETE FROM compSciRelation"
                             " WHERE sci_id ="
                             " (SELECT sci_id FROM scientists WHERE name LIKE '" + sciName + "')"
                             " AND com_id ="
                             " (SELECT com_id FROM computers WHERE name LIKE '" + compName + "')";      //LIKE is used for case insensitive search
        if(!query.exec(QString(queryInsert.c_str())))
        {   //removal failed, connection probably didn't exist
            db.close();
            return false;
        }
        db.close();
    }
    else
    {   //database couldn't open
        return false;
    }
    return true;
}

void RelationRepository::cleanRelations()
{
    if(db.open())
    {
        QSqlQuery query(db);

        string queryInsert = "DELETE FROM compSciRelation"
                             " WHERE sci_id NOT IN"
                             " (SELECT sci_id FROM scientists)"
                             " OR com_id NOT IN"
                             " (SELECT com_id FROM computers)";
        query.exec(QString(queryInsert.c_str()));
    }
}
