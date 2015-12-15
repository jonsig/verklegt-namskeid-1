#include "computerservice.h"

using namespace std;

ComputerService::ComputerService()
{

}

vector<Computer> ComputerService::searchComputers(string searchTerm)
{
    return computerRepo.findComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer)
{
    return computerRepo.addComputer(computer);
}

bool ComputerService::removeComputer(Computer computer)
{
    return computerRepo.removeComputer(computer);
}
