#include "computer.h"
#include "utilities/constants.h"

using namespace std;

Computer::Computer(string name, enum computerType compType, string wasMade, int yearMade)
{
    this->name = name;
    this->compType = compType;
    this->wasMade = wasMade;
    this->yearMade = yearMade;
}

Computer::Computer(string name, enum computerType compType, string wasMade)
{
    this->name = name;
    this->compType = compType;
    this->wasMade = wasMade;
    this->yearMade = constants::YEAR_NOT_ENTERED_DEFAULT_VALUE;
}

string Computer::getName() const
{
    return name;
}

enum computerType Computer::getType() const
{
    return compType;
}

string Computer::getWasMade() const
{
    return wasMade;
}

int Computer::getYearMade() const
{
    return yearMade;
}
