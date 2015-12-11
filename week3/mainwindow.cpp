#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scientistSex->addItem("Male");
    ui->scientistSex->addItem("Female");
    ui->scientistSortBy->addItem("Name");
    ui->scientistSortBy->addItem("Sex");
    ui->scientistSortBy->addItem("Year born");
    ui->scientistSortBy->addItem("Year died");
    ui->scientistSortOrder->addItem("Ascending");
    ui->scientistSortOrder->addItem("Descending");
    ui->computerType->addItem("Electronic");
    ui->computerType->addItem("Mechanical");
    ui->computerType->addItem("Transistor");
    ui->computerType->addItem("Other");
    ui->computerBuilt->addItem("Yes");
    ui->computerBuilt->addItem("No");
    ui->computerBuilt->addItem("Unknown");
    ui->computerSortBy->addItem("Name");
    ui->computerSortBy->addItem("Type");
    ui->computerSortBy->addItem("Was made");
    ui->computerSortBy->addItem("Year made");
    ui->computerSortOrder->addItem("Ascending");
    ui->computerSortOrder->addItem("Descending");

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_addScientistButton_clicked()
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

    return;
}
