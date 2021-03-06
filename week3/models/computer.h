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
    /**
     * @brief Computer constructor for when yearMade is known
     * @param name is the name of the computer
     * @param compType is the computerType
     * @param wasMade refers to wether or not the computer was made
     * @param yearMade is when the computer was made
     */
    Computer(string name, computerType compType, string wasMade, int yearMade);

    /**
     * @brief Computer constructor for when yearMade is not given
     * @param name is the name of the computer
     * @param compType is the computerType
     * @param wasMade refers to wether or not the computer was made
     */
    Computer(string name, computerType compType, string wasMade);

    //the 4 public members below provide read access to private variables
    string getName() const;
    enum computerType getType() const;
    string getWasMade() const;
    int getYearMade() const;

private:
    string name;                //Computer name
    enum computerType compType; //The type of computer
    int yearMade;               //Year the computer was made
    string wasMade;             //Wether or not the computer was made.
};

#endif // COMPUTER_H
