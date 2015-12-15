#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "repositories/computerrepository.h"

using namespace std;

class ComputerService
{
public:
    ComputerService();

    /**
     * @brief getAllComputers calls a get all function in the repository and tells it how to sort the result
     * @param orderBy commands how the result will be sorted
     * @param orderAscending decides if the list is ascending or descending
     * @return sorted vector of all computers
     */
    vector<Computer> getAllComputers(string orderBy, bool orderAscending);

    /**
     * @brief searchComputers calls a search function in the repository
     * @param searchTerm is searched for in the database
     * @return vector of entries containing the serach term
     */
    vector<Computer> searchComputers(string searchTerm);

    /**
     * @brief addComputer calls an add function in the repository
     * @param computer is the variable to be added
     * @return true or false indicating success
     */
    bool addComputer(Computer computer);

    /**
     * @brief removeComputer calls a remove function in the repository
     * @param computer is the variable to be removed
     * @return true or false indicating success
     */
    bool removeComputer(Computer computer);


private:
    ComputerRepository computerRepo;
};

#endif // COMPUTERSERVICE_H
