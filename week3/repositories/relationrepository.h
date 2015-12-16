#ifndef CONNECTIONREPOSITORY_H
#define CONNECTIONREPOSITORY_H

#include <vector>
#include <string>
#include <QtSql>

#include "models/computer.h"
#include "models/scientist.h"

using namespace std;

struct namePair
{
    string compName;
    string sciName;
};

/**
 * @brief The RelationRepository class handles reading and writing relations between computers and scientists from a file
 */

class RelationRepository
{
public:
    /**
     * @brief RelationRepository constructor initializes the database connection
     */
    RelationRepository();

    /**
     * @brief findRelations finds relations to names resembling a search term
     * @param name is the search term
     * @param relateTo chooses wether the search term is a computer/scientist/all
     * @return a vector of namePair, consisting of a computer name and scientist name. namePair maintains the connection
     */
    vector<namePair> findRelations(string name, string relateTo);

    /**
     * @brief addRelation adds a relation between a computer and a scientist in the relation database
     * @param compName name of the computer to be related
     * @param sciName name of the scientist to be related
     * @return true/false indicating success
     */
    bool addRelation(string compName, string sciName);

    /**
     * @brief removeRelation deletes relation database entries where both given names match the IDs
     * @param compName is a full name of a computer
     * @param sciName is a full name of a scientist
     * @return true/false indicating success
     */
    bool removeRelation(string compName, string sciName);

private:
    /**
     * @brief cleanRelations finds relations where either of the two ID's refers to a computer/scientist entry that does not exist anymore and removes them
     */
    void cleanRelations();

    /**
     * @brief db is the database connection to be used
     */
    QSqlDatabase db;
};

#endif // CONNECTIONREPOSITORY_H
