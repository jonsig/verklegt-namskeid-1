#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

void printToFile(const Person& a);      //Adds Person to file
void addPerson();                       //Reads people to add to file
void setPerson(Person& newGuy);         //calls all Person::set functions. Could be replaced by operator overloading
void mainMenu();                      //First menu
void search();
int main()
{
    int choice;
    mainMenu();
    cin >> choice;
    if(choice == 1)
        addPerson();
    else if(choice == 2) //|| choice == 3)
        search();
    else if(choice == 3)
        cout << "Im not ready!" << endl;


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
    cin.ignore();           //losnar við síðasta cin input
    newGuy.setName();
    newGuy.setGender();
    newGuy.setyearOfBirth();
    newGuy.setyearOfDeath();
}

void printToFile(const Person& a)
{
    ofstream outf;
    outf.open("pList.txt", ios::app);
    outf << a;     //"<<" is overloaded in Person class.
    outf.close();
}

void mainMenu()
{
    cout << "What do you want to do?" << endl
         << "(1) Add people." << endl
         << "(2) Search for people." << endl
         << "(3) Show known people." << endl;
}
void search(){
    string search;
    ifstream inf;
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
    size_t pos;


    inf.open("pList.txt");
    cout << "Enter search term: ";
    cin >> search;
    while(inf.good()){
        getline(inf, name);
        getline(inf, gender);
        inf >> yearOfBirth;
        inf >> yearOfDeath;
        pos = name.find(search);
        inf.ignore();
        if(pos !=string::npos){
            cout << name << endl
                 << gender << endl
                 << yearOfBirth << endl
                 << yearOfDeath << endl;

            break;
        }
    }

}
