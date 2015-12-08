#include "repositories/scientistrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <fstream>
#include <cstdlib>
#include <QtSql>


using namespace std;

ScientistRepository::ScientistRepository()
{
    db = QSqlDatabase::addDatabase(QString(constants::DATA_BASE.c_str()));
    db.setDatabaseName(QString(constants::SCIENTISTS_FILE_NAME.c_str()));
}

vector<Scientist> ScientistRepository::getScientists(string filter)
{
    vector<Scientist> scientists;
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec(QString(filter.c_str())))
        {
            while(query.next())
            {
                string name = query.value("name").toString().toStdString();
                enum sexType sex = utils::intToSex(query.value("sex").toInt());
                int yearBorn = query.value("yearBorn").toInt();
                if(query.isNull("yearDied"))    //checks if person is alive
                    scientists.push_back(Scientist(name,sex,yearBorn));
                else
                {
                    int yearDied = query.value("yearDied").toInt();
                    scientists.push_back(Scientist(name,sex,yearBorn,yearDied));
                }
            }
        }
        db.close();
    }
    return scientists;
}

bool ScientistRepository::addScientist(Scientist scientist)
{
    if(db.open())
    {
        QSqlQuery query(db);

        string tableCreation ="CREATE TABLE IF NOT EXISTS scientists(sci_id INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , name VARCHAR, sex INTEGER, yearBorn INTEGER, yearDied INTEGER)";
        query.exec(QString(tableCreation.c_str()));

        string sSex = utils::intToString(scientist.getSex());
        string sYearBorn = utils::intToString(scientist.getYearBorn());
        string queryInsert = "INSERT INTO scientists(name,sex,yearBorn)VALUES('"+scientist.getName()+"','"+sSex+"','"+sYearBorn+"')";
        if(query.exec(QString(queryInsert.c_str())))    //exec returns true if it is successful
        {
            if(scientist.getYearDied() != constants::YEAR_DIED_DEFAULT_VALUE)
            {
                string sYearDied = utils::intToString(scientist.getYearDied());
                queryInsert = "UPDATE scientists SET yearDied = '" + sYearDied + "' WHERE sci_id = (SELECT MAX(sci_id) FROM scientists)";
                query.exec(QString(queryInsert.c_str()));
            }
        }
        else{   //first query failed
            db.close();
            return false;
        }
        db.close();
    }
    else    //file open failed
        return false;
    return true;
}