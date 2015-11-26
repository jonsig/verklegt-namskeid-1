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
        void setName;
        void setGender;
        void setyearOfBirth;
        void setyearOfDeath;
};
