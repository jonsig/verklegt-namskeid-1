#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include "addscientist.h"
#include "addcomputer.h"

#include <iomanip>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayScientists();
    displayComputers();
    displayRelations();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_inputScientistSearchTerm_textChanged()
{
    displayScientists();
}

void MainWindow::on_inputComputerSearchTerm_textChanged()
{
    displayComputers();
}

void MainWindow::on_inputRelationSearchTerm_textChanged()
{
    displayRelations();
}

void MainWindow::on_choiceRelateTo_currentTextChanged()
{
    displayRelations();
}


void MainWindow::displayScientists()
{
    string searchTerm = ui->inputScientistSearchTerm->text().toStdString();
    vector<Scientist> scientists = scientistService.searchForScientists(searchTerm);

    ui->scientistTable->setSortingEnabled(false);
    ui->scientistTable->clearContents();
    ui->scientistTable->setRowCount(scientists.size());
    for (unsigned row = 0; row < scientists.size(); row++)
    {
        Scientist currentSci = scientists.at(row);
        QString name = QString(currentSci.getName().c_str());
        QString sex = "";

        if (currentSci.getSex() == 0)
        {
            sex = "Female";
        }
        else
        {
            sex = "Male";
        }

        QString yearBorn = QString(utils::intToString(currentSci.getYearBorn()).c_str());
        QString yearDied = "N/A";

        if (currentSci.getYearDied() != constants::YEAR_NOT_ENTERED_DEFAULT_VALUE)
        {
           yearDied = QString(utils::intToString(currentSci.getYearDied()).c_str());
        }

        ui->scientistTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->scientistTable->setItem(row, 1, new QTableWidgetItem(sex));
        ui->scientistTable->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->scientistTable->setItem(row, 3, new QTableWidgetItem(yearDied));
    }
    ui->scientistTable->setSortingEnabled(true);
}

void MainWindow::displayComputers()
{
    string searchTerm = ui->inputComputerSearchTerm->text().toStdString();
    vector<Computer> computers = computerService.searchComputers(searchTerm);

    ui->computerTable->setSortingEnabled(false);
    ui->computerTable->clearContents();
    ui->computerTable->setRowCount(computers.size());
    for (unsigned row = 0; row < computers.size(); row++)
    {
        Computer currentComp = computers.at(row);
        QString name = QString(currentComp.getName().c_str());
        QString type = "";

        switch(currentComp.getType())
        {
        case 0:
            type = "Electronic";
            break;
        case 1:
            type = "Mechanical";
            break;
        case 2:
            type = "Transistor";
            break;
        case 3:
            type = "Other";
            break;
        }

        QString wasMade = "Unknown";

        if (currentComp.getWasMade() == "yes")
        {
            wasMade = "Yes";
        }
        else if (currentComp.getWasMade() == "No")
        {
            wasMade = "No";
        }

        QString yearMade = "N/A";
        if (currentComp.getYearMade() != constants::YEAR_NOT_ENTERED_DEFAULT_VALUE)
        {
            yearMade = QString(utils::intToString(currentComp.getYearMade()).c_str());
        }

        ui->computerTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->computerTable->setItem(row, 1, new QTableWidgetItem(type));
        ui->computerTable->setItem(row, 2, new QTableWidgetItem(wasMade));
        ui->computerTable->setItem(row, 3, new QTableWidgetItem(yearMade));
    }
    ui->computerTable->setSortingEnabled(true);
}

void MainWindow::displayRelations()
{
    string searchTerm = ui->inputRelationSearchTerm->text().toStdString();
    string relateTo = ui->choiceRelateTo->currentText().toStdString();

    vector<namePair> relations = relationService.findRelations(searchTerm, relateTo);

    ui->relationTable->setSortingEnabled(false);
    ui->relationTable->clearContents();
    ui->relationTable->setRowCount(relations.size());

    for (unsigned row = 0; row < relations.size(); row++)
    {
        namePair currentRelation = relations.at(row);
        QString compName = QString(currentRelation.compName.c_str());
        QString sciName = QString(currentRelation.sciName.c_str());

        ui->relationTable->setItem(row, 0, new QTableWidgetItem(compName));
        ui->relationTable->setItem(row, 1, new QTableWidgetItem(sciName));
    }
    ui->relationTable->setSortingEnabled(true);
}

void MainWindow::removeRelation()
{
    int row = ui->relationTable->currentRow();
    string compName = ui->relationTable->item(row, 0)->text().toStdString();
    string sciName = ui->relationTable->item(row, 1)->text().toStdString();

    //ABOUT TO DELETE *COMPNAME*, *SCINAME* RELATION, ARE YOU SURE PROMPT

    if(relationService.removeRelation(compName, sciName))
    {
        printf("\nSuccess\n");      //Replace me with a GUI message
    }
    else
        printf("\nFailure\n");
}


void MainWindow::on_tabsCurrentChanged(int index)
{
    if (index == 0)
    {
        displayScientists();
    }
    else if (index == 1)
    {
        displayComputers();
    }
    else if (index == 2)
    {
        displayRelations();
    }
}

void MainWindow::on_buttonAddNewScientist_clicked()
{
    AddScientist addScientist;
    addScientist.exec();

    ui->inputScientistSearchTerm->setText("");
    displayScientists();

    //ui->statusBar->showMessage("Successfully added student", 1500);

}

void MainWindow::on_relationTable_itemClicked()
{
    ui->buttonDelete->setEnabled(true);
}

void MainWindow::on_buttonDelete_clicked()
{
    removeRelation();
    displayRelations();
    ui->buttonDelete->setEnabled(false);
}

void MainWindow::on_buttonAddNewComputer_clicked()
{
    addComputer addComputer;
    addComputer.exec();

    ui->inputComputerSearchTerm->setText("");
    displayComputers();
}
