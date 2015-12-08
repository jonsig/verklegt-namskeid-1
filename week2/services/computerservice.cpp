#include "computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending)
{
    bool drasl1 = orderAscending;   //<- bara til að losna við unused variable warning
    std::string drasl2 = orderBy;   //<-
    std::vector<Computer> deletemelater;
    deletemelater.push_back(Computer("PLACEHOLDER", computerType::electronic));
    std::string command = "SELECT * FROM computers";
    //return computerRepo.getComputers(command);
    return deletemelater;
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
    Computer drasl = computer; //nota computer bara til að losna við unused variable warning
    //return computerRepo.addCompuer(computer);
    return false;   //Placeholder
}
