#ifndef COMPUTER_H
#define COMPUTER_H

#endif // COMPUTER_H

#include <string>

enum computerType {
    mechanical,
    electronic,
    transistor
};

class Computer
{
public:
    Computer(std::string name, int yearMade, computerType compType, bool wasMade);

    std::string getName() const;
    int getYearMade() const;
    enum computerType getType() const;
    bool getWasMade() const;

    bool contains(std::string searchTerm);

private:
    std::string name;
    int yearMade;
    enum computerType comType;
    bool wasMade;
};
