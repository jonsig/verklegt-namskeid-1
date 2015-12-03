#include "models/scientist.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

using namespace std;

Scientist::Scientist(string name, enum sexType sex, int yearBorn)
{
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = constants::YEAR_DIED_DEFAULT_VALUE;
}

Scientist::Scientist(string name, enum sexType sex, int yearBorn, int yearDied)
{
    this->name = name;
    this->sex = sex;
    this->yearBorn = yearBorn;
    this->yearDied = yearDied;
}

std::string Scientist::getName() const
{
    return name;
}

enum sexType Scientist::getSex() const
{
    return sex;
}

int Scientist::getYearBorn() const
{
    return yearBorn;
}

int Scientist::getYearDied() const
{
    return yearDied;
}

bool Scientist::contains(string searchTerm)
{
    string searchTermLower = utils::stringToLower(searchTerm);

    string nameLower = utils::stringToLower(name);
    if (nameLower.find(searchTermLower) != string::npos)
    {
        return true;
    }

    if (searchTermLower == "male" && sex == sexType::male)
    {
        return true;
    }

    if (searchTermLower == "female" && sex == sexType::female)
    {
        return true;
    }

    string yearBornString = utils::intToString(yearBorn);

    if (yearBornString.find(searchTerm) != string::npos)
    {
        return true;
    }

    if (yearDied != constants::YEAR_DIED_DEFAULT_VALUE)
    {
        string yearDiedString = utils::intToString(yearDied);

        if (yearDiedString.find(searchTerm) != string::npos)
        {
            return true;
        }
    }
    else
    {
        if (searchTermLower == "alive")
        {
            return true;
        }
    }

    return false;
}
