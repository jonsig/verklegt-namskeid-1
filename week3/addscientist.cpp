#include "addscientist.h"
#include "ui_addscientist.h"
#include "utilities/utils.h"

#include <QMessageBox>

AddScientist::AddScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientist)
{
    ui->setupUi(this);
    ui->scientistSex->addItem("Male");
    ui->scientistSex->addItem("Female");
}

AddScientist::~AddScientist()
{
    delete ui;
}

void AddScientist::on_buttonAddScientist_clicked()
{
    string name = ui->addScientistName->text().toStdString();
    string sType = ui->addScientistSex->currentText().toStdString();
    enum sexType sex;
    if (sType == "Male")
    {
        sex = male;
    }
    else if (sType == "Female")
    {
        sex = female;
    }
    string yearOfBirth = ui->addScientistYearBorn->text().toStdString();

    bool inputError = false;

    if(name == "")
    {
        ui->addScientistNameError->setText("<span style='color: #DF0101'>Scientist must have name</span>");
        inputError = true;
    }
    if(yearOfBirth == "")
    {
        ui->addScientistYearBornError->setText("<span style='color: #DF0101'>Scientist have existed</span>");
        inputError = true;
    }

    if (inputError == true)
        return;

    int isSure = QMessageBox::question(this, "Confirm", "Are you sure?");

    if (isSure == QMessageBox::No)
    {
        return;
    }

    int yearBorn =utils::stringToInt(yearOfBirth);
    string yearOfDeath = ui->addScientistYearDied->text().toStdString();

    if(yearOfDeath == "")
        scientistService.addScientist(Scientist(name, sex, yearBorn));
    else
    {
        int yearDied = utils::stringToInt(yearOfDeath);
        scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
    }
    ui->addScientistName->setText("");
    ui->addScientistSex->setCurrentText("Male");
    ui->addScientistYearBorn->setText("");
    ui->addScientistYearDied->setText("");
}

void AddScientist::on_buttonCancelAddScientist_clicked()
{
    this->done(0);
}
