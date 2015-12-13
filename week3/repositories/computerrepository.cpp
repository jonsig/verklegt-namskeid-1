#include "repositories/computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <fstream>
#include <cstdlib>
#include <QtSql>

using namespace std;

ComputerRepository::ComputerRepository()
{
    db = utils::getDatabaseConnection();
}

vector<Computer> ComputerRepository::getAllComputers(string orderBy, bool orderAscending)
{
    string command = "SELECT name,compType,wasMade,yearMade FROM computers";
    command += " ORDER BY " + orderBy;
    if(!orderAscending)
    {
        command += " desc";
    }
    return getComputers(command);
}

vector<Computer> ComputerRepository::findComputers(string searchTerm)
{
    string command = "SELECT name,compType,wasMade,yearMade FROM computers WHERE name LIKE '%" + searchTerm +"%'";

    if(searchTerm == "electronic")
    {
        command += " OR compType = 0";
    }
    else if(searchTerm == "mechanical")
    {
     command += " OR compType = 1";
    }
    else if(searchTerm == "transistor")
    {
     command += " OR compType = 2";
    }
    else if(searchTerm == "other")
    {
        command += " OR compType = 3";
    }
    else if(searchTerm == "other")
    {
        command += " OR compType = 3";
    }

    if(utils::stringToLower(searchTerm) == "was made")
    {
        command += " OR wasMade = 'yes'";
    }
    command += " OR yearMade LIKE '%" + searchTerm + "%'";

    return getComputers(command);
}

vector<Computer> ComputerRepository::getComputers(string filter)
{
    vector<Computer> computers;
    if(db.open())
    {
        QSqlQuery query(db);
        if(query.exec(QString(filter.c_str())))
        {
            while(query.next())
            {
                string name = query.value("name").toString().toStdString();
                enum computerType compType = utils::intToComp(query.value("compType").toInt()); //yet to make intToComp
                string wasMade = query.value("wasMade").toString().toStdString();
                if(query.isNull("yearMade"))    //checks if computer was not built
                {
                    computers.push_back(Computer(name,compType,wasMade));
                }
                else
                {
                    int yearMade = query.value("yearMade").toInt();
                    computers.push_back(Computer(name,compType,wasMade,yearMade));
                }
            }
        }
        db.close();
    }
    return computers;
}

bool ComputerRepository::addComputer(Computer computer)
{
    if(db.open())
    {
        QSqlQuery query(db);

        string tableCreation ="CREATE TABLE IF NOT EXISTS computers(com_id INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , name VARCHAR, compType INTEGER, wasMade VARCHAR, yearMade INTEGER)";
        query.exec(QString(tableCreation.c_str()));

        string sType = utils::intToString(computer.getType());
        string queryInsert = "INSERT INTO computers(name,compType,wasMade)VALUES('"+computer.getName()+"','"+sType+"','"+computer.getWasMade()+"')";
        if(query.exec(QString(queryInsert.c_str())))    //exec returns true if it is successful
        {
            if(computer.getYearMade() != constants::YEAR_NOT_ENTERED_DEFAULT_VALUE)
            {
                string sYearMade = utils::intToString(computer.getYearMade());
                queryInsert = "UPDATE computers SET yearMade = '" + sYearMade + "' WHERE com_id = (SELECT MAX(com_id) FROM computers)";
                query.exec(QString(queryInsert.c_str()));
            }
        }
        else
        {   //first query failed
            db.close();
            return false;
        }
        db.close();
    }
    else    //file open failed
        return false;
    return true;
}

