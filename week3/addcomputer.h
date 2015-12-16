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
    /**
     * @brief AddComputer constructor for the add computer window
     */
    explicit AddComputer(QWidget *parent = 0);

    ~AddComputer(); //Add computer window destructor

private slots:
    /**
     * @brief on_buttonAddComputer_clicked - add computer when button is pressed
     */
    void on_buttonAddComputer_clicked();

    /**
     * @brief on_buttonCancelAddComputer_clicked - close the window when cancel button is pressed
     */
    void on_buttonCancelAddComputer_clicked();

private:
    Ui::AddComputer *ui;

    ComputerService computerService; //computer service connection to the repository
};

#endif // ADDCOMPUTER_H
