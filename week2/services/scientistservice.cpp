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
    vector<Scientist> scientists = scientistRepo.getScientists(whatSort);
    return scientists;
}

vector<Scientist> ScientistService::searchForScientists(string searchTerm)
{
    string filter = "SELECT name,sex,yearBorn,yearDied FROM scientists";
    filter += " WHERE name LIKE '%" + searchTerm + "%' OR yearBorn LIKE '%" + searchTerm +"%' OR yearDied LIKE '%" + searchTerm +"%'";
    return scientistRepo.getScientists(filter);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}
