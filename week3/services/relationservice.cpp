#include "relationservice.h"

RelationService::RelationService()
{
    //intentionally blank
}

vector<namePair> RelationService::findRelations(string name, string relateTo)
{
    return relationRepository.findRelations(name, relateTo);
}

bool RelationService::addRelation(string compName, string sciName)
{
    return relationRepository.addRelation(compName, sciName);
}

bool RelationService::removeRelation(string compName, string sciName)
{
    return relationRepository.removeRelation(compName, sciName);
}
