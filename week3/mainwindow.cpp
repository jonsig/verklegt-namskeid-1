#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

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

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_input_scientist_search_term_textChanged()
{
    displayScientists();
}

void MainWindow::on_input_computer_search_term_textChanged()
{
    displayComputers();
}


void MainWindow::displayScientists()
{
    string searchTerm = ui->input_scientist_search_term->text().toStdString();
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
        QString yearDied = "";

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
    string searchTerm = ui->input_computer_search_term->text().toStdString();
    vector<Computer> computers = computerService.searchComputers(searchTerm);

    ui->computer_table->setSortingEnabled(false);
    ui->computer_table->clearContents();
    ui->computer_table->setRowCount(computers.size());
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

        ui->computer_table->setItem(row, 0, new QTableWidgetItem(name));
        ui->computer_table->setItem(row, 1, new QTableWidgetItem(type));
        ui->computer_table->setItem(row, 2, new QTableWidgetItem(wasMade));
        ui->computer_table->setItem(row, 3, new QTableWidgetItem(yearMade));
    }
    ui->computer_table->setSortingEnabled(true);
}


void MainWindow::on_tabs_currentChanged(int index)
{
    if (index == 0)
    {
        displayScientists();
    }
    else if (index == 1)
    {
        displayComputers();
    }
}
