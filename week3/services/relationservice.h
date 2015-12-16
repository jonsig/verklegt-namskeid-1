#ifndef RELATIONSERVICE_H
#define RELATIONSERVICE_H

#include "repositories/relationrepository.h"

class RelationService
{
public:
    /**
     * @brief RelationService initializes nothing
     */
    RelationService();

    /**
     * @brief findRelations finds relations to names resembling a search term
     * @param name is the search term
     * @param relateTo chooses wether the search term is a computer/scientist/all
     * @return a vector of namePair, consisting of a computer name and scientist name. namePair maintains the connection
     */
    vector<namePair> findRelations(string name, string relateTo);

    /**
     * @brief addRelation adds a relation between a computer and a scientist in the repository
     * @param compName name of the computer to be related
     * @param sciName name of the scientist to be related
     * @return true if it was a success, false if it was a failure
     */
    bool addRelation(string compName, string sciName);

    /**
     * @brief removeRelation deletes relation entries in the repository
     * @param compName is a full name of a computer
     * @param sciName is a full name of a scientist
     * @return true if it was a success, false if it was a failure
     */
    bool removeRelation(string compName, string sciName);

private:
    /**
     * @brief relationRepository is the repository connection to be used
     */
    RelationRepository relationRepository;
};

#endif // RELATIONSERVICE_H
