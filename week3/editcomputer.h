#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include "services/computerservice.h"

namespace Ui {
class EditComputer;
}

class EditComputer : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputer(Computer computer, QWidget *parent = 0);
    ~EditComputer();

private slots:
    void on_buttonCancelEditComputer_clicked(); //cancel button, close window

    void on_buttonEditComputer_clicked();       //edit button, update selected computer entry

private:
    //Computer class variables used to delete the old computer entry
    std::string compName;
    enum computerType compType;
    std::string wasMade;
    int yearMade;

    ComputerService computerService; //provides the repository connection

    Ui::EditComputer *ui;
};

#endif // EDITCOMPUTER_H
