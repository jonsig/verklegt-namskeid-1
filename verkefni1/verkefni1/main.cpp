#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

void printToFile(const Person& a);      //Adds Person to file
void addPerson();                       //Reads people to add to file
void setPerson(Person& newGuy);         //calls all Person::set functions. Could be replaced by operator overloading
void mainMenu();                        //First menu
void search();                          //Find entries in file
void searchMenu(int& choice);           //Gives options of what to search for
void printPerson(const string& name, const string& gender, const  int& yearOfBirth, const int& yearOfDeath);

int main()
{
    int choice;
    mainMenu();
    cin >> choice;
    if(choice == 1)
        addPerson();
    else if(choice == 2)
        search();
    else if(choice == 3)
        cout << "I'm not ready!" << endl;
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
    cin.ignore();           //Clears last cin
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
         << "(1): Add people." << endl
         << "(2): Search for people." << endl
         << "(3): Show known people." << endl;
}
void search(){
    string search;
    int numSearch;                 //If you're searching for a year.
    ifstream inf;
    string name, gender;
    int yearOfBirth, yearOfDeath;
    size_t pos = string::npos;
    inf.open("pList.txt");

    int choice;
    searchMenu(choice);            //Choose what to search for

    cout << "Enter search term: ";
    if(choice == 1 || choice == 2)
    {
        cin.ignore();
        getline(cin, search);
    }
    else
    {
        cin >> numSearch;
    }
    while(inf.good()){             //If file read didn't give errors
        getline(inf, name);
        getline(inf, gender);
        inf >> yearOfBirth;
        inf >> yearOfDeath;
        inf.ignore();
        switch(choice)
        {
        case 1:
            pos = name.find(search);
            break;
        case 2:
            pos = gender.find(search);
            break;
        case 3:
            if(numSearch == yearOfBirth)
                pos = 1;
            break;
        case 4:
            if(numSearch == yearOfDeath)
                pos = 1;
            break;
        }
        if(pos !=string::npos){    //If a match was found.
            printPerson(name, gender, yearOfBirth, yearOfDeath);
            break;
        }
    }
    if(pos == string::npos)        //If function is ending without having found a match
        cout << "No matches found" << endl;
}

void searchMenu(int& choice)
{
    cout << "What do you want to search for?" << endl
         << "(1): Name" << endl
         << "(2): Gender" << endl
         << "(3): Year of birth" << endl
         << "(4): Year of death (searching for 0 gives living people)" << endl;
    cin >> choice;

}

void printPerson(const string& name, const string& gender, const int& yearOfBirth, const int& yearOfDeath)
{
    cout << "Name: " << name << endl
         << "Gender: " << gender << endl
         << "Year of birth: " << yearOfBirth << endl
         << "Year of death: " << yearOfDeath << endl;
}
