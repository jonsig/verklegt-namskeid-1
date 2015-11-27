#ifndef PERSON_H
#define PERSON_H
#include <string>

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
        friend ofstream& operator << (ofstream& outf, const Person& a);
};

#endif // PERSON_H
