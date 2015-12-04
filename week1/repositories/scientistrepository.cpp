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
    fileName = constants::DATA_FILE_NAME;
}

std::vector<Scientist> ScientistRepository::getAllScientists()
{
    ifstream file;

    file.open(fileName.c_str());

    vector<Scientist> scientists;

    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            vector<string> fields = utils::splitString(line, constants::FILE_DELIMETER);

            if (fields.size() >= 3)
            {
                string name = fields.at(0);
                enum sexType sex = utils::stringToSex(fields.at(1));
                int yearBorn = utils::stringToInt(fields.at(2));

                if (fields.size() == 3)
                {
                    scientists.push_back(Scientist(name, sex, yearBorn));
                }
                else
                {
                    int yearDied = utils::stringToInt(fields.at(3));

                    scientists.push_back(Scientist(name, sex, yearBorn, yearDied));
                }
            }
        }
    }

    file.close();

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
    db.setDatabaseName(QString(fileName.c_str()));
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
                if(query.exec(QString(queryInsert.c_str())))
                    return true;
                return false;
            }
            return true;
        }
    }
    db.close();
    return false;
}
