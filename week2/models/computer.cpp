#include "computer.h"
#include "utilities/constants.h"

using namespace std;

Computer::Computer(string name, enum computerType compType, int yearMade)
{
    this->name = name;
    this->compType = compType;
    this->yearMade = yearMade;
}

Computer::Computer(string name, enum computerType compType)
{
    this->name = name;
    this->compType = compType;
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

int Computer::getYearMade() const
{
    return yearMade;
}
