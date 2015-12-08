#include "computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    std::string command = "SELECT name,compType,yearMade FROM computers";
    command += " ORDER BY " + orderBy;
    if(!orderAscending)
    {
        command += " desc";
    }
    return computerRepo.getComputers(command);
}

std::vector<Computer> ComputerService::searchComputers(std::string searchTerm)
{
    std::string command = "SELECT * FROM computers WHERE name LIKE '%" + searchTerm +"%'";
    if(searchTerm == "mechanical")
    {
        command += " OR compType = 0";
    }
    else if(searchTerm == "electronic")
    {
        command += " OR compType = 1";
    }
    else if(searchTerm == "transistor")
    {
        command += " OR compType = 2";
    }

    command += " OR yearMade LIKE '%" + searchTerm + "%'";

    return computerRepo.getComputers(command);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}
