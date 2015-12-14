#include "relationservice.h"

RelationService::RelationService()
{

}

vector<namePair> RelationService::findRelations(string name, string relateTo)
{
    return relationRepository.findRelations(name, relateTo);
}

bool RelationService::addRelation(string compName, string sciName)
{
    return relationRepository.addRelation(compName, sciName);
}
