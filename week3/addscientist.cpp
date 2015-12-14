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
    string name = ui->scientistName->text().toStdString();
    string sType = ui->scientistSex->currentText().toStdString();
    enum sexType sex;
    if (sType == "Male")
    {
        sex = male;
    }
    else if (sType == "Female")
    {
        sex = female;
    }
    string yearOfBirth = ui->scientistYearBorn->text().toStdString();

    bool inputError = false;

    if(name == "")
    {
        ui->scientistNameError->setText("<span style='color: #DF0101'>Scientist must have name</span>");
        inputError = true;
    }
    if(yearOfBirth == "")
    {
        ui->scientistYearBornError->setText("<span style='color: #DF0101'>Scientist have existed</span>");
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
    string yearOfDeath = ui->scientistYearDied->text().toStdString();

    if(yearOfDeath == "")
        scientistService.addScientist(Scientist(name, sex, yearBorn));
    else
    {
        int yearDied = utils::stringToInt(yearOfDeath);
        scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
    }
    ui->scientistName->setText("");
    ui->scientistSex->setCurrentText("Male");
    ui->scientistYearBorn->setText("");
    ui->scientistYearDied->setText("");
}

void AddScientist::on_buttonCancelAddScientist_clicked()
{
    this->done(0);
}
