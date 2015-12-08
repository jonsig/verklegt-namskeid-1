#include "computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    std::string command = "SELECT * FROM computers";
    return computerRepo.getComputers(command);
}

std::vector<Computer> ComputerService::searchComputers(std::string searchTerm)
{
    std::vector<Computer> deletemelater;
    //Placeholder, only searches name
    std::string command = "SELECT * FROM computers WHERE name LIKE '%" + searchTerm +"%'";
    return deletemelater;
}
bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}
