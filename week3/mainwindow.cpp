#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"
#include "addscientist.h"

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


void MainWindow::on_choiceRelateTo_currentIndexChanged()
{
    displayRelations();
}

void MainWindow::displayScientists()
{
    string searchTerm = ui->inputScientistSearchTerm->text().toStdString();
    vector<Scientist> scientists = scientistService.searchForScientists(searchTerm);

    ui->scientist_table->setSortingEnabled(false);
    ui->scientist_table->clearContents();
    ui->scientist_table->setRowCount(scientists.size());
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

        ui->scientist_table->setItem(row, 0, new QTableWidgetItem(name));
        ui->scientist_table->setItem(row, 1, new QTableWidgetItem(sex));
        ui->scientist_table->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->scientist_table->setItem(row, 3, new QTableWidgetItem(yearDied));
    }
    ui->scientist_table->setSortingEnabled(true);
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

    ui->relation_table->setSortingEnabled(false);
    ui->relation_table->clearContents();
    ui->relation_table->setRowCount(relations.size());

    for (unsigned row = 0; row < relations.size(); row++)
    {
        namePair currentRelation = relations.at(row);
        QString compName = QString(currentRelation.compName.c_str());
        QString sciName = QString(currentRelation.sciName.c_str());

        ui->relation_table->setItem(row, 0, new QTableWidgetItem(compName));
        ui->relation_table->setItem(row, 1, new QTableWidgetItem(sciName));
    }
    ui->relation_table->setSortingEnabled(true);
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

void MainWindow::on_inputRelationSearchTerm_textChanged()
{
    displayRelations();
}
