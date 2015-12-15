#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H
#include "services/computerservice.h"

#include <QDialog>

namespace Ui {
class addComputer;
}

class addComputer : public QDialog
{
    Q_OBJECT

public:
    explicit addComputer(QWidget *parent = 0);
    ~addComputer();

private slots:
    void on_buttonAddComputer_clicked();

    void on_buttonCancelAddComputer_clicked();

private:
    Ui::addComputer *ui;
    ComputerService computerService;
};

#endif // ADDCOMPUTER_H
