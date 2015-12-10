#ifndef SCIENTISTCOMPARATOR_H
#define SCIENTISTCOMPARATOR_H

#include <string>

/**
 * @brief The ScientistSorting returns which rule is being used
 */
class ScientistSorting
{
public:
    ScientistSorting();

    std::string whichSort(std::string sortColumn, bool sortInAscendingOrder);
private:
    std::string sortColumn;
    bool sortInAscendingOrder;
};

#endif // SCIENTISTCOMPARATOR_H
