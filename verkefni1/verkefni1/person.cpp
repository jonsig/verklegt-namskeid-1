#include "person.h"
#include <iostream>
#include <string>

Person::Person()
{
    name = "N/A";
    gender = "N/A";
    yearOfBirth = 0;
    yearOfDeath = 0;
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
void Person::setyearOfDeath(){
    if(2015-yearOfBirth<=100) {
        char input;
        cout << "Is this person dead?" << endl <<  "y/n: ";
        cin >> input;
        if(input == 'y'){
            cout << "Input year of death: ";
            cin >> yearOfDeath;
            trueAge();
        }
        else if(input == 'n'){
            yearOfDeath = 0;
        }
    }
    else {
        cout << "Input year of death: ";
        cin >> yearOfDeath;
        trueAge();
    }
    if(yearOfDeath<yearOfBirth && yearOfDeath != 0){
        cout << "This person cannot have died before he was born" << endl;
        setyearOfDeath();
    }
}
void Person::trueAge() {
    int ageOfDeath;
    char confused;
    bool makesSense;
    do{
        makesSense =true;
        ageOfDeath = yearOfDeath-yearOfBirth;
       if(ageOfDeath >100){
           cout << "The person seems to have been " << ageOfDeath << " years old when they died" << endl;
           cout << "Is this correct? (y/n) ";
           cin >> confused;
           if(confused == 'n'){
               makesSense=false;
               int toFix = fixIt();
               if(toFix==1) {
                   setyearOfBirth();
                   trueAge();
               }
               else if(toFix==2) {
                   setyearOfDeath();
               }
               else if(toFix==3) {
                   setyearOfBirth();
                   setyearOfDeath();
               }
           }
       }
    }while(makesSense==false);
}

int Person::fixIt() {
    int choice;
    cout << "What would you like to change?" << endl;
    cout << "(1): Year of birth." << endl;
    cout << "(2): Year of death." << endl;
    cout << "(3): Both." << endl;
    cin >> choice;
    return choice;
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
ostream& operator << (ostream& out, const Person& a)
{
    out << a.name << endl
        << a.gender << endl
        << a.yearOfBirth << endl
        << a.yearOfDeath << endl;
    return out;
}

istream& operator >> (istream& in, Person& a)
{
    getline(in, a.name);
    getline(in, a.gender);
    in >> a.yearOfBirth;
    in >> a.yearOfDeath;
    return in;
}

