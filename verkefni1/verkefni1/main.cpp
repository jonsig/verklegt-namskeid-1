#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

void printToFile(const Person& a, const int& num);             //Adds Person to file
void addPerson();                       //Reads people to add to file
void setPerson(Person& newGuy);         //calls all Person::set functions. Could be replaced by operator overloading
void masterMenu();                      //First menu
int main()
{
    int choice;
    masterMenu();
    cin >> choice;
    if(choice == 1)
        addPerson();
    return 0;
}

void addPerson()
{
    int personNum = 0;
    char addMore;
    do
    {
        Person newGuy;
        setPerson(newGuy);
        printToFile(newGuy, personNum);
        cout << "Add a new person?" << endl << "y/n: ";
        cin >> addMore;
        personNum++;
    }
    while(tolower(addMore) == 'y');  //"tolower(choice)" converts upper case to lower
}

void setPerson(Person& newGuy)
{
    cin.ignore();
    newGuy.setName();
    newGuy.setGender();
    newGuy.setyearOfBirth();
    newGuy.setyearOfDeath();
}

void printToFile(const Person& a, const int& num)
{
    ofstream outf;
    outf.open("pList.txt", ios::app);
    outf << a;     //"<<" is overloaded in Person class.
    outf << num << endl;
    outf.close();
}

void masterMenu()
{
    cout << "What do you want to do?" << endl
         << "(1) Add people." << endl
         << "(2) Search for people." << endl
         << "(3) Show known people." << endl;
}
