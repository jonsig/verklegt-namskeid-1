#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

void printToFile(Person a);             //Adds Person to file
void addPerson();                       //Reads people to add to file
void setPerson(Person& newGuy);         //calls all Person::set functions. Could be replaced by operator overloading
void options1();
int main()
{
    int choice;
    options1();
    cin >> choice;
    if(choice == 1)
        addPerson();
    return 0;
}

void addPerson()
{

    char addMore;
    do
    {
        Person newGuy;
        setPerson(newGuy);
        printToFile(newGuy);
        cout << "Add a new person?" << endl << "y/n: ";
        cin >> addMore;
    }
    while(tolower(addMore) == 'y');  //"tolower(choice)" converts upper case to lower
}

void setPerson(Person& newGuy)
{
    newGuy.setName();
    newGuy.setGender();
    newGuy.setyearOfBirth();
    newGuy.setyearOfDeath();
}

void printToFile(Person a)
{
    ofstream outf;
    outf.open("pList.txt", ios::app);
    outf << a;     //"<<" is overloaded in Person class.
    outf.close();
}

void options1()
{
    cout << "What do you want to do?" << endl
         << "(1) Add people." << endl
         << "(2) Search for people." << endl
         << "(3) Show known people." << endl;
}
