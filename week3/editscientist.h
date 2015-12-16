#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include "services/scientistservice.h"

namespace Ui {
class EditScientist;
}

class EditScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientist(Scientist currentScientist, QWidget *parent = 0);
    ~EditScientist();

private slots:
    void on_buttonEditScientist_clicked();          //edit button, update currently selected scientist

    void on_buttonCancelEditScientist_clicked();    //cancel button, close window

private:
    //scientist variables for deleting the old scientist entry
    std::string name;
    enum sexType sex;
    int yearBorn;
    int yearDied;

    Ui::EditScientist *ui;

    ScientistService scientistService; //provides the repository connection
};

#endif // EDITSCIENTIST_H
