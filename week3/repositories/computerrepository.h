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
    ComputerRepository();

    /**
     * @brief getAllComputers makes a query to read all entries and how to sort them and then sends the query to getComputers
     * @param orderBy orders the result
     * @param orderAscending is true for ascending order, false for descending
     * @return vector of all entries in sorted order
     */
    vector<Computer> getAllComputers(string orderBy, bool orderAscending);

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

    bool addComputer(Computer computer);

private:
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
