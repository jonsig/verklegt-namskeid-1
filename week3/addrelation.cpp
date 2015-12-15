#include "addrelation.h"
#include "ui_addrelation.h"
#include "utilities/utils.h"

#include <QMessageBox>

AddRelation::AddRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelation)
{
    vector<Scientist> currentScientists = scientistService.searchForScientists("");
    vector<Computer> currentComputers = computerService.searchComputers("");
    ui->setupUi(this);

    for(unsigned i = 0; i < currentScientists.size(); i++)
    {
        QString sciName = QString::fromStdString(currentScientists.at(i).getName());
        ui->sciNameInput->addItem(sciName);
    }
    for(unsigned i = 0; i < currentComputers.size(); i++)
    {
        QString compName = QString::fromStdString(currentComputers.at(i).getName());
        ui->compNameInput->addItem(compName);
    }
}

AddRelation::~AddRelation()
{
    delete ui;
}

void AddRelation::on_buttonAddRelation_clicked()
{
    string sciName = ui->sciNameInput->currentText().toStdString();
    string compName = ui->compNameInput->currentText().toStdString();


    int isSure = QMessageBox::question(this, "Confirm", "Are you sure?");

    if(isSure == QMessageBox::No)
    {
        return;
    }
    relationsService.addRelation(compName, sciName);
    ui->sciNameInput->setCurrentIndex(0);
    ui->compNameInput->setCurrentIndex(0);
}

void AddRelation::on_buttonCancel_AddRelation_clicked()
{
    this->done(0);
}
