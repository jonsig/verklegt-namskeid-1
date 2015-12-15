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
    void on_buttonEditScientist_clicked();

    void on_buttonCancelEditScientist_clicked();

private:
    std::string name;
    enum sexType sex;
    int yearBorn;
    int yearDied;
    Ui::EditScientist *ui;
    ScientistService scientistService;
};

#endif // EDITSCIENTIST_H
