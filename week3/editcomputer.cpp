#include "editcomputer.h"
#include "ui_editcomputer.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <QMessageBox>

EditComputer::EditComputer(Computer computer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComputer)
{
    ui->setupUi(this);

    //values of original entry are saved in private variables
    this->compName = computer.getName();
    this->compType = computer.getType();
    this->wasMade = computer.getWasMade();
    this->yearMade = computer.getYearMade();

    ui->editComputerNameInput->setText(QString::fromStdString(compName));

    switch (compType)
    {
    case 0:
        ui->editComputerType->setCurrentIndex(0);
        break;
    case 1:
        ui->editComputerType->setCurrentIndex(1);
        break;
    case 2:
        ui->editComputerType->setCurrentIndex(2);
        break;
    case 3:
        ui->editComputerType->setCurrentIndex(3);
        break;
    }

    if (wasMade == "Yes")
    {
        ui->editComputerWasBuilt->setCurrentIndex(0);
    }

    else if(wasMade == "No")
    {
        ui->editComputerWasBuilt->setCurrentIndex(1);
    }

    else if (wasMade == "Unknown")
    {
        ui->editComputerWasBuilt->setCurrentIndex(2);
    }

    if (yearMade != constants::YEAR_NOT_ENTERED_DEFAULT_VALUE)
    {
        ui->editComputerYearBuilt->setText(QString::fromStdString(utils::intToString(yearMade)));
    }
}

EditComputer::~EditComputer()
{
    delete ui;
}

void EditComputer::on_buttonCancelEditComputer_clicked()
{
    this->done(0);
}

void EditComputer::on_buttonEditComputer_clicked()
{
    if(!(computerService.removeComputer(Computer(compName, compType, wasMade, yearMade))))
    {
        return;
    }

    compName = ui->editComputerNameInput->text().toStdString();
    if (compName == "")
    {
        ui->editComputerFeedbackLabel->setText("<span style='color: #DF0101'>Computers must have a name</span>");
        return;
    }
    string cType = ui->editComputerType->currentText().toStdString();
    if (cType == "Electronic")
    {
        compType = electronic;
    }
    else if (cType == "Mechanical")
    {
        compType = mechanical;
    }
    else if (cType == "Transistor")
    {
        compType = transistor;
    }
    else if (cType == "Other")
    {
        compType = other;
    }

    wasMade = ui->editComputerWasBuilt->currentText().toStdString();

    QString yearMadeAsString = ui->editComputerYearBuilt->text();

    bool success = false;

    if (yearMadeAsString != "")
    {
        int yearMade = yearMadeAsString.toInt();
        Computer newComputer(compName, compType, wasMade, yearMade);
        success = computerService.addComputer(newComputer);
    }
    else
    {
        Computer newComputer(compName, compType, wasMade);
        success = computerService.addComputer(newComputer);
    }

    if (success)
    {
        ui->editComputerFeedbackLabel->setText("<span style='color: #49E20E'>Computer successfully changed</span>");
    }
    else
    {
        ui->editComputerFeedbackLabel->setText("<span style='color: #DF0101'>An unknown error occurred, further changes not attempted</span>");
    }


}
