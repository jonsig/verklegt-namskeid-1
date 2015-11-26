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
        void setName();
        void setGender();
        void setyearOfBirth();
        void setyearOfDeath();
        string getName();
        string getGender();
        int getyearOfBirth();
        int getyearOfDeath();
};
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
    cout << "Is this person dead?" << endl <<  "y/n";
    cin >> input;
    if(input == 'y'){
        cout << "Input year of death: ";
        cin >> yearOfDeath;
    }else{ yearOfDeath = 0;}
    if(yearOfDeath<yearOfBirth){
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


int main()
{

    return 0;
}

