#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

enum sexType {
    female,
    male
};

/**
 * @brief The data model for scientists
 */

class Scientist
{
public:
    /**
     * @brief Scientist constructor for when the year of death is not given
     * @param name is the scientists name
     * @param sex is the scientists gender
     * @param yearBorn is the scientists year of birth
     */
    Scientist(string name, sexType sex, int yearBorn);

    /**
     * @brief Scientist constructor for when the year of death is given
     * @param name is the scientists name
     * @param sex is the scientists gender
     * @param yearBorn is the scientists year of birth
     * @param yearDied is the scientists year of death
     */
    Scientist(string name, sexType sex, int yearBorn, int yearDied);

    //The 4 members below provide read access to private variables
    string getName() const;
    enum sexType getSex() const;
    int getYearBorn() const;
    int getYearDied() const;

private:
    string name;
    enum sexType sex;
    int yearBorn;
    int yearDied;
};

#endif // SCIENTIST_H
