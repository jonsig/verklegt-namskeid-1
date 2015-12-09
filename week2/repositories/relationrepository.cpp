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

#include <iostream>
bool RelationRepository::addRelation(string compName, string sciName)
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

        queryInsert = "SELECT com_id FROM computers WHERE name LIKE '" + compName + "'";
        if(query.exec(QString(queryInsert.c_str())))
            return false;
        query.next();
        string compId = query.value("com_id").toString().toStdString();

        queryInsert = "SELECT sci_id FROM scientists WHERE name LIKE '" + sciName + "'";
        if(query.exec(QString(queryInsert.c_str())))
            return false;
        query.next();
        string sciId = query.value("sci_id").toString().toStdString();

        cout << endl << compId << " " << sciId << endl;
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
