#include "computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    return computerRepo.getAllComputers(orderBy, orderAscending);
}

std::vector<Computer> ComputerService::searchComputers(std::string searchTerm)
{
    return computerRepo.findComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}
