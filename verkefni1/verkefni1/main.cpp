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
void printPerson(Person& a);

int main()
{
    int choice;
    do {
        mainMenu();
        cin >> choice;
        if(choice == 1)
            addPerson();
        else if(choice == 2)
            search();
        else if(choice == 3)
            cout << "I'm not ready!" << endl;
    }while(choice==1||choice==2||choice==3);
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
         << "(3): Show known people." << endl
         << "(4): Quit." << endl;
}
void search(){
    Person tempP;                  //will be added to vector
    vector<Person> people;
    string search;
    int numSearch;                 //If you're searching for a year.
    ifstream inf;
    int checker =0;
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
        size_t pos = string::npos;
        inf >> tempP;              //">>" is overloaded in person class
        inf.ignore();
        if(choice == 1)
            pos = tempP.getName().find(search);
        else if(choice == 2)
            pos = tempP.getGender().find(search);
        else if(choice == 3 && numSearch == tempP.getyearOfBirth())
            pos = 1;
        else if(choice == 4 && numSearch == tempP.getyearOfDeath())
            pos = 1;
        if(inf.good() && pos != string::npos) {     //If a match was found.
                printPerson(tempP);
                checker++;
        }
    }
    if(checker == 0)        //If function is ending without having found a match
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

void printPerson(Person& a)
{
    cout << "\nName: " << a.getName() << endl
         << "Gender: " << a.getGender() << endl
         << "Year of birth: " << a.getyearOfBirth() << endl
         << "Year of death: " << a.getyearOfDeath() << endl
         << endl;
}
