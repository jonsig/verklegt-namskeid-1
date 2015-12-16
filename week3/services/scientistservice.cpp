#include "services/scientistservice.h"

using namespace std;

ScientistService::ScientistService()
{
    //intentionally blank
}

vector<Scientist> ScientistService::searchForScientists(string searchTerm)
{
    return scientistRepo.findScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}

bool ScientistService::removeScientist(Scientist scientist)
{
     return scientistRepo.removeScientist(scientist);
}

