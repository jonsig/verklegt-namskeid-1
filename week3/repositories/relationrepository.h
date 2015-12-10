#ifndef CONNECTIONREPOSITORY_H
#define CONNECTIONREPOSITORY_H

#include <vector>
#include <string>
#include <QtSql>

#include "models/computer.h"
#include "models/scientist.h"

using namespace std;

class RelationRepository
{
public:
    RelationRepository();

    /**
     * @brief findSciRelation finds all relations to a given scientist name
     * @param name is the scientist name
     * @return vector where the first value is the scientists name and the rest are results
     */
    vector<string> findSciRelation(string name);

    /**
     * @brief findCompRelation finds all relations to a given computer name
     * @param name is the computer name
     * @return vector where the first value is the computer name and the rest are results
     */
    vector<string> findCompRelation(string name);

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
