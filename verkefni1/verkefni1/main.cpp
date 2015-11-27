#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;


void printToFile(Person a);             //Adds Person to file
void addPerson();                       //Reads people to add to file
void setPerson(Person& newGuy);         //calls all Person::set functions. Could be replaced by operator overloading

int main()
{
    char choice;
    cout << "Add people?" << endl << "y/n: ";
    cin >> choice;
    if(tolower(choice) == 'y')          //"tolower(choice)" converts upper case to lower
        addPerson();
    return 0;
}

void addPerson()
{
    ofstream outf;
    outf.open("pList.txt", ios::app);
    char addMore;
    do
    {
        Person newGuy;
        setPerson(newGuy);
        outf << newGuy;     //"<<" is overloaded in Person class.
        cout << "Add a new person?" << endl << "y/n: ";
        cin >> addMore;
    }
    while(tolower(addMore) == 'y');
    outf.close();
}

void setPerson(Person& newGuy)
{
    newGuy.setName();
    newGuy.setGender();
    newGuy.setyearOfBirth();
    newGuy.setyearOfDeath();
}
