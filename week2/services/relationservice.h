#ifndef RELATIONSERVICE_H
#define RELATIONSERVICE_H

#include "repositories/relationrepository.h"

class RelationService
{
public:
    RelationService();

    vector<string> findSciRelation(string name);

    vector<string> findCompRelation(string name);

    bool addRelation(string compName, string sciName);

private:
    RelationRepository relationRepository;
};

#endif // RELATIONSERVICE_H
