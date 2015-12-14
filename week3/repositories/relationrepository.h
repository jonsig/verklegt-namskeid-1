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

class RelationRepository
{
public:
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

private:
    QSqlDatabase db;
};

#endif // CONNECTIONREPOSITORY_H
