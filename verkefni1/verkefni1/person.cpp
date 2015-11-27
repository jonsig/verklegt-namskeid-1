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
}

void Person::setName(){
    cout << "Input name: ";
    getline(cin, name);
}
void Person::setGender(){
    cout << "Input gender: ";
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
    char input;
    cout << "Is this person dead?" << endl <<  "y/n: ";
    cin >> input;
    if(input == 'y'){
        cout << "Input year of death: ";
        cin >> yearOfDeath;
    }
    else if(input == 'n'){
        yearOfDeath = 0;
    }

    if(yearOfDeath<yearOfBirth && yearOfDeath != 0){
        cout << "This person cannot have died before he was born" << endl;
        setyearOfDeath();
    }
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
         << a.yearOfDeath << endl;
    return outf;
}

