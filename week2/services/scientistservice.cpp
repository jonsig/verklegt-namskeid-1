#include "services/scientistservice.h"
#include "utilities/scientistsorting.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService()
{

}

vector<Scientist> ScientistService::getAllScientists(string orderBy, bool orderAscending)
{
    string whatSort = scientistSort.whichSort(orderBy, orderAscending);
    vector<Scientist> scientists = scientistRepo.sortTheScientists(whatSort);
    return scientists;
}

vector<Scientist> ScientistService::searchForScientists(string searchTerm)
{
    return scientistRepo.searchForScientists(searchTerm);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}
