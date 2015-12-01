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
        string description;
    public:
        Person();
        void makePerson();  //Replaces the old istream overload since it wasn't actually using istream.
        void setName();
        void setGender();
        void setyearOfBirth();
        void setyearOfDeath();
        void setDescription();
        void trueAge();
        int fixIt();
        string getName();
        string getGender();
        int getyearOfBirth();
        int getyearOfDeath();
        friend ofstream& operator << (ofstream& outf, const Person& a);     //compiler uses ofstream for writing in files and ostream to write with cout.
        friend ifstream& operator >> (ifstream& inf, Person& a);
        friend ostream& operator << (ostream& out, const Person& a);
};

#endif // PERSON_H
