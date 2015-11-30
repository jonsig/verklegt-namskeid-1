#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <fstream>

using namespace std;

class Person {
    private:
        string gender;
        string name;
        int yearOfBirth, yearOfDeath;
    public:
        Person();
        void newPerson();
        void setName();
        void setGender();
        void setyearOfBirth();
        void setyearOfDeath();
        void trueAge();
        int fixIt();
        string getName();
        string getGender();
        int getyearOfBirth();
        int getyearOfDeath();
        friend ofstream& operator << (ofstream& outf, const Person& a); //used by outf
        friend ifstream& operator >> (ifstream& inf, Person& a);
        friend ostream& operator << (ostream& out, const Person& a);    //used by cout
};

#endif // PERSON_H
