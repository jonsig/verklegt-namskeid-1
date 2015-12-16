#ifndef ADDRELATION_H
#define ADDRELATION_H

#include <QDialog>
#include "services/relationservice.h"
#include "services/computerservice.h"
#include "services/scientistservice.h"

namespace Ui {
class AddRelation;
}

class AddRelation : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelation(QWidget *parent = 0);
    ~AddRelation();

private slots:
    void on_buttonAddRelation_clicked();        //add button, add relation

    void on_buttonCancel_AddRelation_clicked(); //cancel button, close window

private:
    Ui::AddRelation *ui;

    //Service classes provide connections to repositories
    RelationService relationsService;
    ScientistService scientistService;
    ComputerService computerService;



};

#endif // ADDRELATION_H
