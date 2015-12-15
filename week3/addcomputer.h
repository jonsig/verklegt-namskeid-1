#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H
#include "services/computerservice.h"

#include <QDialog>

namespace Ui {
class AddComputer;
}

class AddComputer : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputer(QWidget *parent = 0);
    ~AddComputer();

private slots:
    void on_buttonAddComputer_clicked();

    void on_buttonCancelAddComputer_clicked();

private:
    Ui::AddComputer *ui;
    ComputerService computerService;
};

#endif // ADDCOMPUTER_H
