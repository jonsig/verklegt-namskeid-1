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

}

MainWindow::~MainWindow()
{

    delete ui;

}

void MainWindow::on_pushButton_add_scientist_clicked()
{

}
