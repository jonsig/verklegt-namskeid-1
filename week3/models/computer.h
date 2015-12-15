#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

enum computerType {
    electronic,
    mechanical,
    transistor,
    other
};

/**
 * @brief The data model for computers
 */

class Computer
{
public:
    Computer(string name, computerType compType, string wasMade, int yearMade);
    Computer(string name, computerType compType, string wasMade);

    string getName() const;
    enum computerType getType() const;
    string getWasMade() const;
    int getYearMade() const;

private:
    string name;
    enum computerType compType;
    int yearMade;
    string wasMade;
};

#endif // COMPUTER_H
