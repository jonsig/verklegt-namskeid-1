#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

void mainMenu(int& choice);                                     //interface
void addPeople();                                               //interface
void printToFile(const Person& a);                              //file i/o
void search();                                                  //core function
void searchMenu(string& sSearch, int& iSearch, int& choice);    //interface
void getPeople(vector<Person>& people);                         //file i/o

int main()
{
    int choice;
    do
    {
        mainMenu(choice);
        if(choice == 1)
            addPeople();
        else if(choice == 2)
        {
            search();
        }
    }
    while(choice == 1 || choice == 2 || choice == 3);
    return 0;
}

void mainMenu(int& choice)
{
    cout << "What would you like to do?" << endl
         << "(1): Add people" << endl
         << "(2): Search for people" << endl
         << "(3): Show known people" << endl
         << "Anything else to quit" << endl;
    cin >> choice;
}

void addPeople()
{
    char addMore;
    do
    {
        Person newGuy;
        cin >> newGuy;
        printToFile(newGuy);
        cout << "Add a new person?" << endl << "y/n: ";
        cin >> addMore;
    }
    while(tolower(addMore) == 'y');  //"tolower(choice)" converts upper case to lower
}

void printToFile(const Person& a)
{
    ofstream outf;
    outf.open("pList.txt", ios::app);
    outf << a;     //"<<" is overloaded in Person class.
    outf.close();
}

void search()
{
    string sSearch;     //String search
    int iSearch;        //Integer search
    int choice;         //Choice of what to search for
    searchMenu(sSearch, iSearch, choice);

    vector<Person> people;      //Vector is made so file read can be in a different layer
    getPeople(people);          //Vector filled.
    for(unsigned i = 0; i < people.size()-1; i++)
    {
        if(choice == 1 && people[i].getName().find(sSearch) != string::npos) //choice = 1 and match found
            cout << people[i];
        else if(choice == 2 && people[i].getGender().find(sSearch) != string::npos) //choice = 1 and match found
            cout << people[i];
        else if(choice == 3 && people[i].getyearOfBirth() == iSearch)
            cout << people[i];
        else if(choice == 4 && people[i].getyearOfDeath() == iSearch)
            cout << people[i];
    }
}

void searchMenu(string& sSearch, int& iSearch, int& choice)
{
    cout << "What would you like to search for?" << endl
         << "(1): Name" << endl
         << "(2): Gender" << endl
         << "(3): Year of birth" << endl
         << "(4): Year of death" << endl;
    cin >> choice;
    cin.ignore();
    cout << "Enter search term: ";
    if(choice == 1 || choice == 2)
    {
        getline(cin, sSearch);
    }
    else if(choice == 3 || choice == 4)
    {
        cin >> iSearch;
        cin.ignore();
    }
    else
        cout << "Invalid choice" << endl;
}

void getPeople(vector<Person>& people)
{
    ifstream inf;
    inf.open("pList.txt");
    while(inf.good())
    {
        Person temp;
        inf >> temp;
        people.push_back(temp);
    }
    inf.close();
}
