#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_add_scientist_clicked()
{

}
