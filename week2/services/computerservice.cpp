#include "computerservice.h"

using namespace std;

ComputerService::ComputerService()
{

}

vector<Computer> ComputerService::getAllComputers(string orderBy, bool orderAscending)
{
    return computerRepo.getAllComputers(orderBy, orderAscending);
}

vector<Computer> ComputerService::searchComputers(string searchTerm)
{
    return computerRepo.findComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}
