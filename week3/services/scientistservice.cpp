#include "services/scientistservice.h"

using namespace std;

ScientistService::ScientistService()
{

}

vector<Scientist> ScientistService::getAllScientists(string orderBy, bool orderAscending)
{
    return scientistRepo.getAllScientists(orderBy, orderAscending);
}

vector<Scientist> ScientistService::searchForScientists(string searchTerm)
{
    return scientistRepo.findScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}
