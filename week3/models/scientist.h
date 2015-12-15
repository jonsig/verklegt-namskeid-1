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
    Scientist(string name, sexType sex, int yearBorn);
    Scientist(string name, sexType sex, int yearBorn, int yearDied);

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
