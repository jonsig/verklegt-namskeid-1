#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include<vector>    //<- Will be replaced by inheritance from computer repository
#include "models/computer.h"

class ComputerService
{
public:
    ComputerService();

    /**
     * @brief getAllComputers makes the sql command and calls a repository function to read all entries
     * @param orderBy commands how the result will be sorted
     * @param orderAscending decides if the list is ascending or descending
     * @return sorted vector of all computers
     */
    std::vector<Computer> getAllComputers(std::string orderBy, bool orderAscending);

    /**
     * @brief searchComputers makes an sql command using searchTerm and calls a read function in the repository
     * @param searchTerm is searched for in the database
     * @return vector of entries containing the serach term
     */
    std::vector<Computer> searchComputers(std::string searchTerm);

    /**
     * @brief addComputer calls an add function in the repository
     * @param computer is the variable to be added
     * @return true or false indicating success
     */
    bool addComputer(Computer computer);
};

#endif // COMPUTERSERVICE_H
