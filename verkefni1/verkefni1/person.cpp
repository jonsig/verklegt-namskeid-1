#include "person.h"
#include <iostream>
#include <string>
#include <fstream>

Person::Person()
{
    name = "N/A";
    gender = "N/A";
    yearOfBirth = 0;
    yearOfDeath = 0;
    description = "N/A";
}

void Person::makePerson()
{
    setName();
    setGender();
    setyearOfBirth();
    setyearOfDeath();
    setDescription();
}

void Person::setName(){
    cout << "Input name: ";
    getline(cin, name);
}
void Person::setGender(){
    cout << "Input gender (m/f): ";
    getline(cin, gender);
}
void Person::setyearOfBirth(){
    cout << "Input year of birth: ";
    cin >> yearOfBirth;
    if(yearOfBirth>2015){
        cout << "Timetravel is not allowed!" << endl;
        setyearOfBirth();
    }
}
void Person::setDescription()
{
    char choice;
    cout << "Add description? (y/n) ";
    cin >> choice;
    cin.ignore();
    if(tolower(choice) == 'y')
    {
        cout << "Description: ";
        getline(cin, description);
    }
}

void Person::setyearOfDeath(){
    if(2015-yearOfBirth<=100) {
        char input;
        cout << "Is this person dead? (y/n) ";
        cin >> input;
        if(input == 'y'){
            cout << "Input year of death: ";
            cin >> yearOfDeath;
            trueAge();
        }
        else if(input == 'n'){
            yearOfDeath = 3000;
        }
    }
    else {
        cout << "Input year of death: ";
        cin >> yearOfDeath;
        trueAge();
    }
    if(yearOfDeath<yearOfBirth && yearOfDeath != 3000){
        cout << "This person cannot have died before he was born" << endl;
        setyearOfDeath();
    }
}

void Person::trueAge() {
    int ageOfDeath;
    char confused;  //chooses wether years were correct or not
    int choice;     //chooses what years to change
    bool makesSense;
    do{
        makesSense =true;
        ageOfDeath = yearOfDeath-yearOfBirth;
       if(ageOfDeath >100){
           fixIt(confused, choice, ageOfDeath);
           if(confused == 'n'){
               makesSense=false;
               if(choice==1) {
                   setyearOfBirth();
                   trueAge();
               }
               else if(choice==2) {
                   setyearOfDeath();
               }
               else if(choice==3) {
                   setyearOfBirth();
                   setyearOfDeath();
               }
           }
       }
    }while(makesSense==false);
}

void Person::fixIt(char& confused, int& choice, const int& ageOfDeath) {
    cout << "The person seems to have been " << ageOfDeath << " years old when they died" << endl;
    cout << "Is this correct? (y/n) ";
    cin >> confused;

    cout << "What would you like to change?" << endl;
    cout << "(1): Year of birth." << endl;
    cout << "(2): Year of death." << endl;
    cout << "(3): Both." << endl;
    cin >> choice;
    cin.ignore();
}

string Person::getName(){
    return name;
}
string Person::getGender(){
    return gender;
}
int Person::getyearOfBirth(){
    return yearOfBirth;
}
int Person::getyearOfDeath(){
    return yearOfDeath;
}

ofstream& operator << (ofstream& outf, const Person& a)
{
    outf << a.name << endl
         << a.gender << endl
         << a.yearOfBirth << endl
         << a.yearOfDeath << endl
         << a.description << endl;
    return outf;
}

ifstream& operator >> (ifstream& inf, Person& a)
{
    getline(inf, a.name);
    getline(inf, a.gender);
    inf >> a.yearOfBirth;
    inf >> a.yearOfDeath;
    inf.ignore();
    getline(inf, a.description);
    return inf;
}

ostream& operator << (ostream& out, const Person& a)
{
    Person temp = a;
    out << "Name: " << temp.getName() << endl
        << "Gender: ";
    if(temp.getGender() == "m")
        out << "Male";
    else if(temp.getGender() == "f")
        out << "Female";
    else
        out << "(User error) " << temp.getGender();
    out << endl
        << "Year of birth: " << temp.getyearOfBirth() << endl;
    if(temp.getyearOfDeath() != 3000)
        out << "Year of death: " << temp.getyearOfDeath() << endl;
    else
        out << temp.getName() << " is alive." << endl;
    if(temp.description != "N/A")
        cout << "Description: " << temp.description << endl;
    cout << endl;
    return out;
}
