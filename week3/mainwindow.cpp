#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iomanip>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_input_search_term_textChanged()
{
    string searchTerm = ui->input_search_term->text().toStdString();
    vector<Scientist> scientists = scientistService.searchForScientists(searchTerm);
    displayScientists(scientists);
}

void MainWindow::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists("name", true);
    displayScientists(scientists);
}

void MainWindow::displayScientists(vector<Scientist> scientists)
{
    ui->scientist_table->setSortingEnabled(false);
    ui->scientist_table->clearContents();
    ui->scientist_table->setRowCount(scientists.size());
    for(unsigned row = 0; row < scientists.size(); row++)
    {
        Scientist currentSci = scientists.at(row);
        QString name = QString(currentSci.getName().c_str());
        QString sex;

        if (currentSci.getSex() == 0)
        {
            sex = "Female";
        }
        else
        {
            sex = "Male";
        }

        QString yearBorn = QString(utils::intToString(currentSci.getYearBorn()).c_str());
        QString yearDied;

        if (currentSci.getYearDied() != constants::YEAR_NOT_ENTERED_DEFAULT_VALUE)
        {
           yearDied = QString(utils::intToString(currentSci.getYearDied()).c_str());
        }
        else
        {
            yearDied = "";
        }

        ui->scientist_table->setItem(row, 0, new QTableWidgetItem(name));
        ui->scientist_table->setItem(row, 1, new QTableWidgetItem(sex));
        ui->scientist_table->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->scientist_table->setItem(row, 3, new QTableWidgetItem(yearDied));
    }
    ui->scientist_table->setSortingEnabled(true);
}
