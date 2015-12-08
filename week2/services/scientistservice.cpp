#include "services/scientistservice.h"

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
    string filter = "SELECT name,sex,yearBorn,yearDied FROM scientists WHERE name LIKE '%" + searchTerm + "%'";

    if (searchTerm == "male")
        filter += " OR sex LIKE 1";     //because the database stores genders as 1 and 0
    else if (searchTerm == "female")
        filter += " OR sex LIKE 0";

    filter += " OR yearBorn LIKE '%" + searchTerm +"%'";

    if (searchTerm == "alive" ||searchTerm == "Alive")
        filter += " OR yearDied IS NULL OR yearDied IS ''";
    else
        filter+= "OR yearDied LIKE '%" + searchTerm +"%'";
    return scientistRepo.getScientists(filter);
}

bool ScientistService::addScientist(Scientist scientist)
{
    return scientistRepo.addScientist(scientist);
}
