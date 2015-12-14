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
    void on_input_scientist_search_term_textChanged();

    void on_input_computer_search_term_textChanged();

    void on_tabs_currentChanged(int index);


private:
    /**
     * @brief displayScientists searches for scientists and writes the scientist table.
     *        If there's no input in the search bar, all scientists are shown. The table handles sorting.
     */
    void displayScientists();

    /**
     * @brief displayComputers searcher for computers and writes the computer table.
     *        If there's no input in the search bar, all computers are shown. The table handles sorting.
     */
    void displayComputers();

    Ui::MainWindow *ui;
    ScientistService scientistService;
    ComputerService computerService;
    RelationService relationService;
};

#endif // MAINWINDOW_H
