#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include "repositories/scientistrepository.h"

using namespace std;

/**
 * @brief The ScientistService acts as a middle layer between the UI and Data layers, also handles sorting
 */
class ScientistService
{
public:
    ScientistService();

    /**
     * @brief getAllScientists fetches scientists from the ScientistRepository and sorts them
     * @param orderBy Which column the scientists should be sorted on
     * @param orderAscending Should the list be sorted in ascending order?
     * @return a vector containing all scientists in the repository
     */
    vector<Scientist> getAllScientists(string orderBy, bool orderAscending);

    /**
     * @brief searchForScientists fetches all scientists from file and filters them on searchTerm
     * @param searchTerm Contains the input that the user wishes to filter on
     * @return a vector of scientists filtered by searchTerm
     */
    vector<Scientist> searchForScientists(string searchTerm);

    /**
     * @brief addScientist calls an add function in the repository
     * @param scientist is the variable to be added
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(Scientist scientist);

    /**
     * @brief removeScientist calls a remove function in the repository
     * @param scientist is the variable to be added
     * @return true if it was a success, false if it was a failure
     */
    bool removeScientist(Scientist scientist);

private:
    ScientistRepository scientistRepo;
};

#endif // SCIENTISTSERVICE_H
