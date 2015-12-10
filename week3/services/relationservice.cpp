#include "relationservice.h"

RelationService::RelationService()
{

}

vector<string> RelationService::findSciRelation(string name)
{
    return relationRepository.findSciRelation(name);
}

vector<string> RelationService::findCompRelation(string name)
{
    return relationRepository.findCompRelation(name);
}

bool RelationService::addRelation(string compName, string sciName)
{
    return relationRepository.addRelation(compName, sciName);
}
