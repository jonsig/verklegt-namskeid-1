#ifndef SCIENTISTCOMPARATOR_H
#define SCIENTISTCOMPARATOR_H

#include "models/scientist.h"

/**
 * @brief The ScientistComparator can compare two scientists by rules set in the constructor when used with a sort function
 */
class ScientistComparator
{
public:
    ScientistComparator(std::string sortColumn, bool sortInAscendingOrder);

    bool operator() (const Scientist& first, const Scientist& second);
private:
    std::string sortColumn;
    bool sortInAscendingOrder;
};

#endif // SCIENTISTCOMPARATOR_H
