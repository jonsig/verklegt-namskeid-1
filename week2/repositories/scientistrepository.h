#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include <vector>
#include <string>
#include <QtSql>

#include "models/scientist.h"


/**
 * @brief The ScientistRepository class handles reading and writing scientists to and from a file
 */
class ScientistRepository
{
public:
    ScientistRepository();

    /**
     * @brief getScientist reads scientists from the database using the filter
     * @param filter is an SQL SELECT command
     * @return vector of scientists
     */
    std::vector<Scientist> getScientists(std::string filter);

    bool addScientist(Scientist scientist);

private:
    QSqlDatabase db;
};

#endif // SCIENTISTREPOSITORY_H
