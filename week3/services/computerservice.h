#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "repositories/computerrepository.h"

using namespace std;

class ComputerService
{
public:
    ComputerService();

    /**
     * @brief searchComputers calls a search function in the repository
     * @param searchTerm is searched for in the database
     * @return vector of entries containing the serach term
     */
    vector<Computer> searchComputers(string searchTerm);

    /**
     * @brief addComputer calls an add function in the repository
     * @param computer is the variable to be added
     * @return true if it was a success, false if it was a failure
     */
    bool addComputer(Computer computer);

    /**
     * @brief removeComputer calls a remove function in the repository
     * @param computer is the variable to be removed
     * @return true if it was a success, false if it was a failure
     */
    bool removeComputer(Computer computer);

private:
    ComputerRepository computerRepo;
};

#endif // COMPUTERSERVICE_H
