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
    void on_inputScientistSearchTerm_textChanged();

    void on_inputComputerSearchTerm_textChanged();

    void on_tabsCurrentChanged(int index);

    void on_buttonAddNewScientist_clicked();

    void on_inputRelationSearchTerm_textChanged();

    void on_choiceRelateTo_currentTextChanged();

    void on_relationTable_itemClicked();

    void on_buttonRelationDelete_clicked();

    void on_buttonAddNewComputer_clicked();

    void on_scientistTable_itemClicked();

    void on_buttonScientistDelete_clicked();

    void on_computerTable_itemClicked();

    void on_buttonComputerDelete_clicked();

private:
    /**
     * @brief displayScientists searches for scientists and writes the scientist table.
     *        If there's no input in the search bar, all scientists are shown. The table handles sorting.
     */
    void displayScientists();

    /**
     * @brief displayComputers searches for computers and writes the computer table.
     *        If there's no input in the search bar, all computers are shown. The table handles sorting.
     */
    void displayComputers();

    /**
     * @brief displayRelations searches for relations between scientists and computers and writes the relation table.
     */
    void displayRelations();

    /**
     * @brief removeRelation deletes the currently selected relation in the relation table.
     */
    void removeRelation();

    Ui::MainWindow *ui;
    ScientistService scientistService;
    ComputerService computerService;
    RelationService relationService;
    vector<Scientist> displayedScientist;   //Last list of scientists that the scientist table used
    vector<Computer> displayedComputer;     //Last list of computers that the computer table used
};

#endif // MAINWINDOW_H
