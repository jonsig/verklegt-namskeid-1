#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include <vector>
#include <string>
#include <QtSql>

#include "models/scientist.h"

using namespace std;

/**
 * @brief The ScientistRepository class handles reading and writing scientists to and from a file
 */
class ScientistRepository
{
public:
    ScientistRepository();

    /**
     * @brief getAllScientists creates a command and sends it to getScientists to read and sort all scientist entries
     * @param orderBy chooses what to sort the entries by
     * @param orderAscending chooses descending or ascending order
     * @return vector containing all scientists in sorted order
     */
    vector<Scientist> getAllScientists(string orderBy, bool orderAscending);

    /**
     * @brief findScientists creates a command and sends it to getScientists to find entries fitting the search term
     * @param searchTerm is used to make the search command
     * @return vector containing search results
     */
    vector<Scientist> findScientists(string searchTerm);
    /**
     * @brief getScientist reads scientists from the database using the filter
     * @param filter is an SQL SELECT command
     * @return vector of scientists
     */
    vector<Scientist> getScientists(string filter);

    bool addScientist(Scientist scientist);

private:
    QSqlDatabase db;
};

#endif // SCIENTISTREPOSITORY_H
