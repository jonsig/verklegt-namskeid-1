#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

const int LIVING_VALUE = 3000;    //Year of death value used to represent living people

/*
 * Interface functions handle all window information. Core functions do calculations like sorting and searching,
 * file i/o reads and writes files. This is done so they can easily be replaced in the following weeks.
 */
void mainMenu(int& choice);                                     //interface
void addPeople();                                               //Core function     Adds new people
void printToFile(const Person& a);                              //file i/o          Writes person list file
void search(vector<Person>& people);                            //Core function     Search people
void searchMenu(string& sSearch, int& iSearch, int& choice);    //interface         Choose how to search people
void getPeople(vector<Person>& people);                         //file i/o          Loads people vector from person list file
void printPerson(const Person& a);                              //interface         show user a person
void showAll(vector<Person>& people);                           //interface         show all people
void sortingMenu(int& order, int& upordown);                    //interface         Choose how to sort
void listAll(vector<Person>& people);                           //Core function     Sorts people using following sort functions
void sortName(Person& a, Person& b);                            //Core function
void sortLastName(Person& a, Person& b);                        //Core function
void sortGender(Person& a, Person& b);                          //Core function
void sortBirthyear(Person& a, Person& b);                       //Core function
void sortDeathyear(Person& a, Person& b);                       //Core function
void switching(Person& a, Person& b);                           //Core function
void theFlipSide(vector<Person>& people);                       //interface         show all people in reverse order
void noFind();                                                  //interface         just tells the user that the search function didn't find anything

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
                listAll(people);
            }
        }
    }
    while(choice == 1 || choice == 2 || choice == 3);
    return 0;
}

void addPeople()
{
        Person newGuy;
        newGuy.makePerson();
        printToFile(newGuy);
}

void search(vector<Person>& people)
{
    string sSearch;     //String search
    int iSearch;        //Integer search
    int choice;         //Choice of what to search for
    bool found = false;
    searchMenu(sSearch, iSearch, choice);

    for(unsigned i = 0; i < people.size(); i++)
    {
        if(choice == 1 && people[i].getName().find(sSearch) != string::npos) { //choice = 1 and match found
            printPerson(people[i]);
            found = true;
        }
        else if(choice == 2 && people[i].getGender().find(sSearch) != string::npos) { //choice = 1 and match found
            printPerson(people[i]);
            found = true;
        }
        else if(choice == 3 && people[i].getyearOfBirth() == iSearch) {
            printPerson(people[i]);
            found = true;
        }
        else if(choice == 4 && people[i].getyearOfDeath() == iSearch) {
            printPerson(people[i]);
            found = true;
        }
        else if(choice == 5 && people[i].getyearOfDeath() == LIVING_VALUE)
        {
            printPerson(people[i]);
            found = true;
        }
        else if(choice == 6 && people[i].getyearOfDeath() != LIVING_VALUE)
        {
            printPerson(people[i]);
            found = true;
        }
    }
    if(found == false)
        noFind();
}

void listAll(vector<Person>& people) {
    int order;
    int upordown;
    sortingMenu(order, upordown);
    if(order != 1)
    {
        for(unsigned a = 0; a < people.size(); a++)
        {
            for(unsigned b = 0; b < people.size(); b++)
            {
                if(order == 2)
                    sortName(people[a], people[b]);
                else if(order == 3)
                    sortLastName(people[a], people[b]);
                else if(order == 4)
                    sortGender(people[a], people[b]);
                else if(order == 5)
                    sortBirthyear(people[a], people[b]);
                else if(order == 6)
                    sortDeathyear(people[a], people[b]);
            }
        }
    }
   if(upordown==1){
       showAll(people);
   }
   else if(upordown == 2)
       theFlipSide(people);
}

void sortName(Person& a, Person& b)
{
    if(a.getName() < b.getName())
        switching(a, b);
}

void sortLastName(Person& a, Person& b)
{
    size_t lastSpace_a = a.getName().find_last_of(' ');            //Positions of last spaces
    size_t lastSpace_b = b.getName().find_last_of(' ');
    if(lastSpace_a != string::npos && lastSpace_b != string::npos) //Both names had more than 1 word
        if(a.getName()[lastSpace_a +1] < b.getName()[lastSpace_b + 1]) //Compares first letters of last names
            switching(a, b);
}

void sortGender(Person& a, Person& b)
{
    if(a.getGender() < b.getGender())
        switching(a, b);
}

void sortBirthyear(Person& a, Person& b) {
    if(a.getyearOfBirth() < b.getyearOfBirth())
        switching(a, b);
}

void sortDeathyear(Person& a, Person& b) {
    if(a.getyearOfDeath() < b.getyearOfDeath())
    {
        switching(a, b);
    }
}

void switching(Person& a, Person& b){
    Person temp;
    temp = a;
    a = b;
    b = temp;
}

void showAll(vector<Person>& people)
{
    for(unsigned i = 0; i < people.size(); i++)
    {
        printPerson(people[i]);
    }
}

void theFlipSide(vector<Person>& people) {
    for(int i = people.size()-1; i >= 0; i--)
    {
        printPerson(people[i]);
    }
}

void printToFile(const Person& a)
{
    ofstream outf;
    outf.open("pList.txt", ios::app);
    outf << a;     //"<<" is overloaded in Person class.
    outf.close();
}

void getPeople(vector<Person>& people)
{
    ifstream inf;
    Person temp;
    inf.open("pList.txt");
    while(inf >> temp)
    {
        people.push_back(temp);
    }
    inf.close();
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

void searchMenu(string& sSearch, int& iSearch, int& choice)
{
    cout << "What would you like to search for?" << endl
         << "(1): Name" << endl
         << "(2): Gender (m/f)" << endl
         << "(3): Year of birth" << endl
         << "(4): Year of death" << endl
         << "(5): Living people" << endl
         << "(6): Deceased people" << endl;
    cin >> choice;
    cin.ignore();
    if(choice == 1 || choice == 2)
    {
        cout << "Enter search term: ";
        getline(cin, sSearch);
    }
    else if(choice == 3 || choice == 4)
    {
        cout << "Enter search term: ";
        cin >> iSearch;
        cin.ignore();
    }
    else if(choice != 5 && choice != 6)
        cout << "Invalid choice" << endl;
}

void sortingMenu(int& order, int& upordown)
{
    cout << "How would you like to see the list?" << endl
         << "(1): Submit time" << endl
         << "(2): First name" << endl
         << "(3): Last name" << endl
         << "(4): Gender" << endl
         << "(5): Year of birth" << endl
         << "(6): Year of death" << endl;
    cin >> order;
    if(order == 4) {
        cout << "(1): Females first" << endl
             << "(2): Males first" << endl;
    }
    else {
        cout << "(1): Ascending order" << endl
             << "(2): Descending order" << endl;
    }
    cin >> upordown;
    cin.ignore();
}

void printPerson(const Person& a) //used so cout is seperated from core functions and can be replaced by future gui
{
    cout << a;
}

void noFind()
{
    cout << "No match found." << endl;
}
