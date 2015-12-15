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
     * @brief findScientists creates a command and sends it to getScientists to find entries fitting the search term
     * @param searchTerm is used to make the search command
     * @return vector containing search results
     */
    vector<Scientist> findScientists(string searchTerm);

    /**
     * @brief addScientist adds a scientist to the scientist database
     * @param scientist is the variable to be added
     * @return true or false indicating success
     */
    bool addScientist(Scientist scientist);

    /**
     * @brief addScientist removes a scientist to the scientist database
     * @param scientist is the variable to be removed
     * @return true or false indicating success
     */
    bool removeScientist(Scientist scientist);

private:

    /**
     * @brief getScientist reads scientists from the database using the filter
     * @param filter is an SQL SELECT command
     * @return vector of scientists
     */
     vector<Scientist> getScientists(string filter);

    QSqlDatabase db;
};

#endif // SCIENTISTREPOSITORY_H
