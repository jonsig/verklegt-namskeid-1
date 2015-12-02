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
        Person();                                                       //Core function
        void makePerson();                                              //Core function     Calls all set functions
        void setName();                                                 //Interface
        void setGender();                                               //Interface
        void setyearOfBirth();                                          //Interface
        void setyearOfDeath();                                          //Interface
        void setDescription();                                          //Interface
        void trueAge();                                                 //Core function     Checks if age is unusual
        void fixIt(char& confused, int& choice, const int& ageOfDeath); //Interface         Asks if unusual ages should be changed and how
        string getName();                                               //Core function
        string getGender();                                             //Core function
        int getyearOfBirth();                                           //Core function
        int getyearOfDeath();                                           //Core function
        friend ofstream& operator << (ofstream& outf, const Person& a); //file i/o  compiler uses ofstream for writing in files and ostream to write with cout
        friend ifstream& operator >> (ifstream& inf, Person& a);        //file i/o
        friend ostream& operator << (ostream& out, const Person& a);    //interface
};

#endif // PERSON_H
