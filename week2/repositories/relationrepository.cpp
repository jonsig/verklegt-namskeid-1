#include "repositories/relationrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"


#include <cstdlib>
#include <QtSql>

using namespace std;

RelationRepository::RelationRepository()
{
    db = QSqlDatabase::addDatabase(QString(constants::DATA_BASE.c_str()), "relation");
    db.setDatabaseName(QString(constants::FILE_NAME.c_str()));
}

vector<string> RelationRepository::findSciRelation(string name)
{
    vector<string> results;
    results.push_back(name);

    if(db.open())
    {
        QSqlQuery query(db);

        string queryInsert = "SELECT c.name"
                             " FROM compSciRelation sic"
                             " JOIN computers c"
                             " ON c.com_id = sic.com_id"
                             " JOIN scientists s"
                             " ON s.sci_id = sic.sci_id"
                             " WHERE s.name LIKE '" + name +"'";

        query.exec(QString(queryInsert.c_str()));
        while(query.next())
        {
            printf("\nchecking next\n");
            results.push_back(query.value("name").toString().toStdString());
        }

        db.close();
    }
    return results;
}

vector<string> RelationRepository::findCompRelation(string name)
{
    vector<string> results;
    results.push_back(name);

    if(db.open())
    {
        QSqlQuery query(db);

        string queryInsert = "SELECT s.name"
                             " FROM compSciRelation sic"
                             " JOIN computers c"
                             " ON c.com_id = sic.com_id"
                             " JOIN scientists s"
                             " ON s.sci_id = sic.sci_id"
                             " WHERE c.name LIKE '" + name +"'";

        query.exec(QString(queryInsert.c_str()));
        while(query.next())
        {
            results.push_back(query.value("name").toString().toStdString());
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
        string compId = query.value("com_id").toString().toStdString();

        queryInsert = "SELECT sci_id FROM scientists WHERE name LIKE '" + sciName + "'";
        if(!query.exec(QString(queryInsert.c_str())))
        {
            db.close();
            return false;
        }
        query.next();
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
