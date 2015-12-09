#include "repositories/relationrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"


#include <cstdlib>
#include <QtSql>

using namespace std;

RelationRepository::RelationRepository()
{
    db = QSqlDatabase::addDatabase(QString(constants::DATA_BASE.c_str()), "connect");
    db.setDatabaseName(QString(constants::FILE_NAME.c_str()));
}


bool RelationRepository::addConnection(string compName, string sciName)
{
    if(db.open())
    {
        QSqlQuery query(db);
        string queryInsert = "CREATE TABLE IF NOT EXISTS compSciRelation("
                "com_id INTEGER,"
                "sci_id INTEGER,"
                "FOREIGN KEY (com_id) REFERENCES computers(com_id),"
                "FOREIGN KEY (sci_id) REFERENCES scientists(sci_id)"
                "PRIMARY KEY (com_id, sci_id)"
                ")";
        query.exec(QString(queryInsert.c_str()));

        queryInsert = "SELECT com_id FROM computers WHERE name = '" + compName + "'";
        query.exec(QString(queryInsert.c_str()));
        int compId = query.value("com_id").toInt();

        queryInsert = "SELECT sci_id FROM scientists WHERE name = '" + sciName + "'";
        query.exec(QString(queryInsert.c_str()));
        int sciId = query.value("sci_id").toInt();

        queryInsert = "INSERT INTO compSciRelation VALUES (?1,?2)";
        query.prepare(QString(queryInsert.c_str()));
        query.bindValue(1,compId);
        query.bindValue(2,sciId);
        if(query.exec())
        {
            db.close();
            return true;
        }
    }
    db.close();
    return false;
}

bool RelationRepository::connectThe(Scientist scientist, Computer computer)
{
    if(db.open())
    {
        QSqlQuery query(db);

        string tableCreation = "CREATE TABLE IF NOT EXISTS connections(CREATE TABLE connection(sciName VARCHAR, compName VARCHAR, ";
               tableCreation += "FOREIGN KEY sciName REFERENCES scientists(name), FOREIGN KEY compName REFERENCES computers(name) ";
               tableCreation += "PRIMARY KEY (sciName, compName)";
        query.exec(QString(tableCreation.c_str()));

        string queryInsert = "INSERT INTO connection(sciName,compName)VALUES('"+scientist.getName()+"','"+computer.getName()+"')";
        if(query.exec(QString(queryInsert.c_str()))==false)    //exec returns true if it is successful
        {
            db.close();
            return false;
        }
        db.close();
    }
    else    //file open failed
        return false;
    return true;
}
