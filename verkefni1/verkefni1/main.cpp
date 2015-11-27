#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person {
        string gender;
        string name;
        int yearOfBirth, yearOfDeath;
    public:
        Person();
        void setName();
        void setGender();
        void setyearOfBirth();
        void setyearOfDeath();
        string getName();
        string getGender();
        int getyearOfBirth();
        int getyearOfDeath();
};

Person::Person()
{
    name = "N/A";
    gender = "N/A";
    yearOfBirth = 0;
    yearOfDeath = 0;
}

void Person::setName(){
    cout << "Input name: ";
    cin >> name;
}
void Person::setGender(){
    cout << "Input gender: ";
    cin >> gender;
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

void printToFile(Person a);

void addPerson(vector<Person>& people); //Adds a new person to file
void setPerson(Person& newGuy);         //calls all Person::set functions

int main()
{
    vector<Person> people;              //PLACEHOLDER FOR .TXT FILE.
    char choice;
    cout << "Add people?" << endl << "y/n: ";
    cin >> choice;
    if(tolower(choice) == 'y')
        addPerson(people);
    return 0;
}

void addPerson(vector<Person>& people)
{
    char addMore;
    do
    {
        Person newGuy;
        setPerson(newGuy);

        people.push_back(newGuy);       //PLACEHOLDER

        cout << "Add a new person?" << endl << "y/n: ";
        cin >> addMore;
    }
    while(tolower(addMore) == 'y');
}

void setPerson(Person& newGuy)
{
    newGuy.setName();
    newGuy.setGender();
    newGuy.setyearOfBirth();
    newGuy.setyearOfDeath();
}
