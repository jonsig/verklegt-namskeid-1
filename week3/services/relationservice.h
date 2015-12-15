#ifndef RELATIONSERVICE_H
#define RELATIONSERVICE_H

#include "repositories/relationrepository.h"

class RelationService
{
public:
    RelationService();

    //COMMENTA ÖLL FYRIR NEÐAN

    vector<namePair> findRelations(string name, string relateTo);

    bool addRelation(string compName, string sciName);

    bool removeRelation(string compName, string sciName);

private:
    RelationRepository relationRepository;
};

#endif // RELATIONSERVICE_H
