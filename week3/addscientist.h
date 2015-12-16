#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>
#include "services/scientistservice.h"

namespace Ui {
class AddScientist;
}

class AddScientist : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientist(QWidget *parent = 0);
    ~AddScientist();

private slots:
    void on_buttonAddScientist_clicked();       //add button, add scientist

    void on_buttonCancelAddScientist_clicked(); //cancel button, close window

private:
    Ui::AddScientist *ui;
    ScientistService scientistService; //provides repository connection
};

#endif // ADDSCIENTIST_H
