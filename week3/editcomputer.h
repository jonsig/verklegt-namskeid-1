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
    void on_buttonCancelEditComputer_clicked();

    void on_buttonEditComputer_clicked();

private:
    int com_id;
    std::string compName;
    enum computerType compType;
    std::string wasMade;
    int yearMade;
    ComputerService computerService;
    Ui::EditComputer *ui;
};

#endif // EDITCOMPUTER_H
