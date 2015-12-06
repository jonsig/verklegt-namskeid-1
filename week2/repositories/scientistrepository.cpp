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
vector<Scientist> ScientistRepository::getAllScientists()
{       //Örugglega til betri leiðir en þetta virkar
    vector<Scientist> scientists;
    if(db.open()) //Opens db and returns true if it worked
    {
        QSqlQuery query;                                //er rangt að kalla þetta query og query insert?
        string queryInsert = "SELECT name,sex,yearBorn,yearDied FROM scientists";
        if(query.exec(QString(queryInsert.c_str())))
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

vector<Scientist> ScientistRepository::searchForScientists(string searchTerm)
{
    vector<Scientist> allScientists = getAllScientists();
    vector<Scientist> filteredScientists;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        if (allScientists.at(i).contains(searchTerm))
        {
            filteredScientists.push_back(allScientists.at(i));
        }
    }

    return filteredScientists;
}


bool ScientistRepository::addScientist(Scientist scientist)
{
    if(db.open())
    {
        QSqlQuery query(db);
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
