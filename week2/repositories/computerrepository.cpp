#include "repositories/computerrepository.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

#include <fstream>
#include <cstdlib>
#include <QtSql>

using namespace std;

ComputerRepository::ComputerRepository()
{
    db = QSqlDatabase::addDatabase(QString(constants::DATA_BASE.c_str()), "comp");
    db.setDatabaseName(QString(constants::FILE_NAME.c_str()));
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
                if(query.isNull("yearMade"))    //checks if computer was not built
                    computers.push_back(Computer(name,compType));
                else
                {
                    int yearMade = query.value("yearMade").toInt();
                    computers.push_back(Computer(name,compType,yearMade));
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

        string tableCreation ="CREATE TABLE IF NOT EXISTS computers(com_id INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , name VARCHAR, compType INTEGER, yearMade INTEGER)";
        query.exec(QString(tableCreation.c_str()));

        string cType = utils::intToString(computer.getType());
        string queryInsert = "INSERT INTO computers(name,compType)VALUES('"+computer.getName()+"','"+cType+"')";
        if(query.exec(QString(queryInsert.c_str())))    //exec returns true if it is successful
        {
            if(computer.getYearMade() != constants::YEAR_NOT_ENTERED_DEFAULT_VALUE)
            {
                string cYearMade = utils::intToString(computer.getYearMade());
                queryInsert = "UPDATE computers SET yearMade = '" + cYearMade + "' WHERE com_id = (SELECT MAX(com_id) FROM computers)";
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

