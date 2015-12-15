#include "addrelation.h"
#include "ui_addrelation.h"

addrelation::addrelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrelation)
{
    ui->setupUi(this);
}

addrelation::~addrelation()
{
    delete ui;
}
