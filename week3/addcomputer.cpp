#include "addcomputer.h"
#include "ui_addcomputer.h"
#include "utilities/utils.h"

#include <QMessageBox>

addComputer::addComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputer)
{
    ui->setupUi(this);

    ui->computerType->addItem("Electronic");
    ui->computerType->addItem("Mechanical");
    ui->computerType->addItem("Transistor");
    ui->computerType->addItem("Other");
    ui->computerBuilt->addItem("Yes");
    ui->computerBuilt->addItem("No");
    ui->computerBuilt->addItem("Unknown");
}

addComputer::~addComputer()
{
    delete ui;
}

void addComputer::on_buttonAddComputer_clicked()
{
    string name = ui->computerName->text().toStdString();
    string cType = ui->computerType->currentText().toStdString();
    enum computerType type;
    if (cType == "Electronic")
    {
        type = electronic;
    }
    else if (cType == "Mechanical")
    {
        type = mechanical;
    }
    else if (cType == "Transistor")
    {
        type = transistor;
    }
    else if (cType == "Other")
    {
        type = other;
    }

    string wasBuilt = ui->computerBuilt->currentText().toStdString();

    if (wasBuilt == "Yes")
        wasBuilt = utils::stringToLower(wasBuilt);

    bool inputError = false;

    if(name == "")
    {
        ui->computerNameError->setText("<span style='color: #DF0101'>Computer must have name</span>");
        inputError = true;
    }

    if (inputError == true)
        return;

    string yearOfBuild = ui->computerYearBuilt->text().toStdString();


    int isSure = QMessageBox::question(this, "Confirm", "Are you sure?");

    if (isSure == QMessageBox::No)
    {
        return;
    }


    if(yearOfBuild == "")
        computerService.addComputer(Computer(name, type, wasBuilt));
    else
    {
        int yearBuilt = utils::stringToInt(yearOfBuild);
        computerService.addComputer(Computer(name, type, wasBuilt, yearBuilt));
    }
    ui->computerName->setText("");
    ui->computerType->setCurrentText("Electronic");
    ui->computerBuilt->setCurrentText("Yes");
    ui->computerYearBuilt->setText("");
}

void addComputer::on_buttonCancelAddComputer_clicked()
{
    this->done(0);
}
