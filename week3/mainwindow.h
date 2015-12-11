#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "services/relationservice.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addScientistButton_clicked(); //eitthvað vesen

private:
    Ui::MainWindow *ui;
    ScientistService scientistService;
    ComputerService computerService;
    RelationService relationService;
};

#endif // MAINWINDOW_H
