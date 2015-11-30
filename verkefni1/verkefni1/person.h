#ifndef PERSON_H
#define PERSON_H
#include <string>

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
        friend ostream& operator << (ostream& out, const Person& a);
        friend istream& operator >> (istream& in, Person& a);
    
};

#endif // PERSON_H
