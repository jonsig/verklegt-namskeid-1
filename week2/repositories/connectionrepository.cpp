#include "repositories/connectionrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <fstream>
#include <cstdlib>
#include <QtSql>

using namespace std;

ConnectionRepository::ConnectionRepository()
{
    db = QSqlDatabase::addDatabase(QString(constants::DATA_BASE.c_str()), "connect");
    db.setDatabaseName(QString(constants::FILE_NAME.c_str()));
}

bool ConnectionRepository::connectThe(Scientist scientist, Computer computer)
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
