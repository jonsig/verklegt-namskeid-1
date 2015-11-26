#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

class Person {
        char name, gender;
        int yearOfBirth, yearOfDeath;
    public:
        void setName();
        void setGender();
        void setyearOfBirth();
        void setyearOfDeath();
};
void Person::setName(){
    cout << "Input name";
    cin >> name;
}
void Person::setGender(){
    cout << "Input gender";
    cin >> gender;
}
void Person::setyearOfBirth(){
    cout << "Input year of birth";
    cin >> yearOfBirth;
}
void Person::setyearOfDeath(){
    char input;
    cout << "Is this person dead?" << endl <<  "y/n";
    cin >> input;
    if(input==y){
        cout << "Input year of death: ";
        cin >> yearOfDeath;
    }else{ yearOfDeath = 0;}
}
