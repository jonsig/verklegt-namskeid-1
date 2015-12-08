#include "computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    std::string command = "SELECT name,compType,yearMade FROM computers";
    command += " ORDER BY " + orderBy;

    return computerRepo.getComputers(command);
}

std::vector<Computer> ComputerService::searchComputers(std::string searchTerm)
{
    //Placeholder, only searches name
    std::string command = "SELECT * FROM computers WHERE name LIKE '%" + searchTerm +"%'";
    return computerRepo.getComputers(command);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}
