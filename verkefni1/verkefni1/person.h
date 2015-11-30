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
        friend ofstream& operator << (ofstream& outf, const Person& a);     //there are two overloads for each i/o operator, one file stream, one standard. Compiler chooses them based on what called them.
        friend ifstream& operator >> (ifstream& inf, Person& a);
        friend ostream& operator << (ostream& out, const Person& a);
        friend istream& operator >> (istream& in, Person& a);
};

#endif // PERSON_H
