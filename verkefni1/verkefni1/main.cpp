#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;
/*
 * Interface functions handle all window information. Core functions do calculations like sorting and searching,
 * file i/o reads and writes files. This is done so they can easily be replaced in the following weeks.
 */
void mainMenu(int& choice);                                     //interface
void addPeople();                                               //interface
void printToFile(const Person& a);                              //file i/o
void search(vector<Person>& people);                            //core function
void searchMenu(string& sSearch, int& iSearch, int& choice);    //interface
void getPeople(vector<Person>& people);                         //file i/o
void printPerson(const Person& a);                              //interface
void showAll(vector<Person>& people);                           //interface
void sort(vector<Person>& people);                              //core function

int main()
{
    int choice;
    do
    {
        mainMenu(choice);
        if(choice == 1)
            addPeople();
        else
        {
            vector<Person> people;
            getPeople(people);      //People are loaded every time search or show all are selected
            if(choice == 2)
            {
                search(people);
            }
            else if(choice == 3)
            {
                showAll(people);
            }
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
    cin.ignore();
}

void addPeople()
{
    char addMore;
    do
    {
        Person newGuy;
        newGuy.makePerson(); //Replaces the old istream overload since it wasn't actually using istream.
        printToFile(newGuy);
        cout << "Add a new person?" << endl << "y/n: ";
        cin >> addMore;
        cin.ignore();
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

void search(vector<Person>& people)
{
    string sSearch;     //String search
    int iSearch;        //Integer search
    int choice;         //Choice of what to search for
    searchMenu(sSearch, iSearch, choice);

    for(unsigned i = 0; i < people.size()-1; i++)
    {
        if(choice == 1 && people[i].getName().find(sSearch) != string::npos) //choice = 1 and match found
            printPerson(people[i]);
        else if(choice == 2 && people[i].getGender().find(sSearch) != string::npos) //choice = 1 and match found
            printPerson(people[i]);
        else if(choice == 3 && people[i].getyearOfBirth() == iSearch)
            printPerson(people[i]);
        else if(choice == 4 && people[i].getyearOfDeath() == iSearch)
            printPerson(people[i]);
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

void printPerson(const Person& a) //used so cout is seperated from core functions and can be replaced by future gui
{
    cout << a;
}

void showAll(vector<Person>& people)
{
    for(unsigned i = 0; i < people.size()-1; i++)
    {
        cout << people[i];      //Temporary
    }
}
