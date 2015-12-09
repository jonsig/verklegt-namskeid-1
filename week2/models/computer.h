#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

enum computerType {
    electronic,
    mechanical,
    transistor,
    other
};

class Computer
{
public:
    Computer(std::string name, computerType compType, std::string wasMade, int yearMade);
    Computer(std::string name, computerType compType, std::string wasMade);

    std::string getName() const;
    enum computerType getType() const;
    std::string getWasMade() const;
    int getYearMade() const;

private:
    std::string name;
    enum computerType compType;
    int yearMade;
    std::string wasMade;
};

#endif // COMPUTER_H
