#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "repositories/relationrepository.h"

using namespace std;

/**
 * @brief Holds commands that are available in the UI
 */
enum command {
    menu,
    add,
    display,
    search,
    sort,
    addRelations,
    back,
    changeType,
    quit,
    noType,
    unknown
};

enum entryType
{
    scientists,
    computers
};

class ConsoleUI
{
public:
    ConsoleUI();

    /**
     * @brief start is the main run loop for the application
     * @return should indicate how the program exists, currently always safely
     */
    int start();

private:
    /**
     * @brief display serves as a router to according display functions
     */
    void display();

    /**
     * @brief readInput handles user input by settings commands or processing it
     */
    void readInput();

    void displayTypeMenu();
    void displayMenu();
    void displayUnknownCommandMenu();
    void displaySearchMenu();
    void displayAddRelationMenu();

    void displayAddScientistMenu();
    void displayAllScientists();
    void displaySortSciMenu();
    void displayScientists(vector<Scientist> scientists);

    void displayAddComputerMenu();
    void displayAllComputers();
    void displaySortCompMenu();
    void displayComputers(vector<Computer> computers);

    /**
     * @brief addSciCommandHandler calls the addScientist function and notifies the user how it went
     * @param userInput the input the user is trying to create a scientist from
     */
    void addCommandHandler(string userInput);

    /**
     * @brief sortCommandHandler calls the setSort function and notifies the user how it went
     * @param userInput the input the user is trying to change sort from
     */
    void sortCommandHandler(string userInput);

    /**
     * @brief searchCommandHandler calls the scientistService displays a list of filtered users
     * @param userInput a string sent as input to the search function
     */
    void searchCommandHandler(string userInput);

    /**
     * @brief addRelationCommandHandler calls the addRelation function and notifies the user how it went
     * @param userInput the input the user is trying to create a relation from
     */
    void addRelationCommandHandler(string userInput);

    /**
     * @brief addScientist attempts to add a scientist
     * @param data A string containing the user input
     * @return true if it was a success, false if it was a failure
     */
    bool addScientist(string data);

    /**
     * @brief addComputer attempts to add a computer
     * @param data, string containing user input
     * @return true/false indicating success
     */
    bool addComputer(string data);

    /**
     * @brief addRelation attempts to add a relation between a computer and a scientist
     * @param data, string containing user input
     * @return true(false indicating success
     */
    bool addRelation(string data);
    /**
     * @brief setSciSort attempts to change how scientists will be sorted based on userinput
     * @param sortCommand the sort rule, rules are stored in constants.h
     * @return true if it was a success, false if it was a failure
     */
    bool setSciSort(string sortCommand);

    /**
     * @brief setCompSort converts user input to sorting commands
     * @param sortCommand
     * @return true/false indicating success
     */
    bool setCompSort(string sortCommand);

    void displayError(string error);

    ScientistService scientistService;
    ComputerService computerService;
    RelationRepository relationRepository;
    enum command lastCommand;
    enum entryType type;
    string sortBy;
    bool sortAscending;
};

#endif // CONSOLEUI_H
