#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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
    void on_inputScientistSearchTerm_textChanged(); //scientist search term changed, update scientist table

    void on_inputComputerSearchTerm_textChanged();  //computer search term changed, update computer table

    void on_buttonAddNewScientist_clicked();        //add scientist button clicked, open add window

    void on_inputRelationSearchTerm_textChanged();  //relation search term changed, update relation table

    void on_choiceRelateTo_currentTextChanged();    //relateTo choice changed, update relation table

    void on_relationTable_itemClicked();    //relation table clicked, activate delete button

    void on_buttonRelationDelete_clicked(); //delete relation button clicked, delete selected relation

    void on_buttonAddNewComputer_clicked(); //add computer button clicked, open add window

    void on_scientistTable_itemClicked();   //scientist table clicked, activate edit and delete buttons

    void on_buttonScientistDelete_clicked();//delete scientist button clicked, delete selected scientist

    void on_computerTable_itemClicked();    //computer table clicked, activate edit and delete buttons

    void on_buttonComputerDelete_clicked(); //delete computer button clicked, delete selected computer

    void on_buttonRelationAdd_clicked();    //add relation button clicked, open add relation window

    void on_buttonComputerEdit_clicked();   //edit computer button clicked, open edit window

    void on_buttonScientistEdit_clicked();  //edit scientist button clicked, open edit window

    void on_tabs_currentChanged(int index); //tabs changed, update tables

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

    ScientistService scientistService;      //service classes provide repository connections
    ComputerService computerService;
    RelationService relationService;

    vector<Scientist> displayedScientist;   //Last list of scientists that the scientist table used
    vector<Computer> displayedComputer;     //Last list of computers that the computer table used
};

#endif // MAINWINDOW_H
