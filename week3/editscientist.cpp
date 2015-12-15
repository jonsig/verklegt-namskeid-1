#include "editscientist.h"
#include "ui_editscientist.h"
#include "utilities/utils.h"
#include "utilities/constants.h"

//#include <QMessageBox>

EditScientist::EditScientist(Scientist currentScientist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientist)
{
    this->name = currentScientist.getName();
    this->sex = currentScientist.getSex();
    this->yearBorn =currentScientist.getYearBorn();
    this->yearDied = currentScientist.getYearDied();
    ui->setupUi(this);
    ui->editScientistSex->addItem("Male");
    ui->editScientistSex->addItem("Female");
    QString currentName = QString::fromStdString(name);
    QString currentYearOfBirth = QString::fromStdString(utils::intToString(yearBorn));
    QString currentYearOfDeath = QString::fromStdString(utils::intToString(yearDied));
    ui->editScientistName->setText(currentName);
    if(sex == 0)
    {
        ui->editScientistSex->setCurrentText("Female");
    }
    else if(sex == 1)
    {
        ui->editScientistSex->setCurrentText("Male");
    }
    ui->editScientistYearOfBirth->setText(currentYearOfBirth);
    if(yearDied != constants::YEAR_NOT_ENTERED_DEFAULT_VALUE)
        ui->editScientistYearOfDeath->setText(currentYearOfDeath);
    else
    {
        ui->editScientistYearOfDeath->setText("N/A");
    }
}

EditScientist::~EditScientist()
{
    delete ui;
}

void EditScientist::on_buttonEditScientist_clicked()
{
    if(!scientistService.removeScientist(Scientist(name, sex, yearBorn, yearDied)))
    {
        return;
    }

    string name = ui->editScientistName->text().toStdString();
    string sType = ui->editScientistSex->currentText().toStdString();
    enum sexType sex;
    if(sType == "Male")
    {
        sex = male;
    }
    else if(sType == "Female")
    {
        sex = female;
    }
    string yearOfBirth = ui->editScientistYearOfBirth->text().toStdString();

    bool inputError = false;

    if(name == "")
    {
        ui->editScientistNameError->setText("<span style='color: #DF0101'>Scientist must have name</span>");
        inputError = true;
    }
    if(yearOfBirth == "")
    {
        ui->editScientistYearOfBirthError->setText("<span style='color: #DF0101'>Scientist must have existed</span>");
        inputError = true;
    }
    if(inputError == true)
    {
        return;
    }
    /*int isSure = QMessageBox::question(this,"Confirm","Are you sure?");

    if(isSure == QMessageBox::No)
    {
        return;
    }*/
    int newYearBorn = utils::stringToInt(yearOfBirth);
    string yearOfDeath = ui->editScientistYearOfDeath->text().toStdString();

    if(yearOfDeath == "")
        scientistService.addScientist(Scientist(name, sex, newYearBorn));
    else
    {
        int newYearDied = utils::stringToInt(yearOfDeath);
        scientistService.addScientist(Scientist(name, sex, newYearBorn, newYearDied));
    }
    //CHANGE ADD TO UPDATE ONCE UPDATE IS IMPLEMENTED
}


void EditScientist::on_buttonCancelEditScientist_clicked()
{
    this->done(0);
}
