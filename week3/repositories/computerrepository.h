#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>
#include <QtSql>

#include "models/computer.h"

using namespace std;

/**
 * @brief The ComputerRepository class handles reading and writing computers from a file
 */

class ComputerRepository
{
public:

    /**
     * @brief ComputerRepository constructor initializes the database connection
     */
    ComputerRepository();

    /**
     * @brief findComputers makes a search query and sends it to getComputers
     * @param searchTerm is a string that will be used to create the search query
     * @return vector containing search results
     */
    vector<Computer> findComputers(string searchTerm);

    /**
     * @brief getComputers reads entries in the computer database using a given command
     * @param filter is a command that is used to select entries
     * @return vector of computers fitting desciption in filter
     */
    vector<Computer> getComputers(string filter);

    /**
     * @brief addComputer adds a computer to the computer database
     * @param computer is the variable to be added
     * @return true or false indicating success
     */
    bool addComputer(Computer computer);

    /**
     * @brief removeComputer removes a computer from the computer database
     * @param computer is the variable to be removed
     * @return true or false indicating success
     */
    bool removeComputer(Computer computer);

private:
    /**
     * @brief db is the databaase connection to be used
     */
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
