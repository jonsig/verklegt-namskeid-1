#include "ui/consoleui.h"
#include "utilities/constants.h"
#include "utilities/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{
    lastCommand = command::changeType;
    sortBy = "name";
    sortAscending = true;
}

int ConsoleUI::start()
{
    while(lastCommand != command::quit)
    {
        display();
        readInput();
    }

    return 0;
}

void ConsoleUI::display()
{
    if(type == entryType::scientists)
    {
        switch (lastCommand)
        {
            case command::changeType:
                displayTypeMenu();
                break;
            case command::menu:
                displayMenu();
                break;
            case command::add:
                displayAddScientistMenu();
                break;
            case command::display:
                displayAllScientists();
                break;
            case command::search:
                displaySearchMenu();
                break;
            case command::sort:
                displaySortSciMenu();
                break;
            default:
                displayUnknownCommandMenu();
                break;
        }
    }
    else if(type == entryType::computers)
    {
        switch (lastCommand)
        {
            case command::changeType:
                displayTypeMenu();
                break;
            case command::menu:
                displayMenu();
                break;
            case command::add:
                displayAddComputerMenu();
                break;
            case command::display:
                displayAllComputers();
                break;
            case command::search:
                displaySearchMenu();
                break;
            case command::sort:
                displaySortCompMenu();
                break;
            default:
                displayUnknownCommandMenu();
                break;
        }
    }
}

void ConsoleUI::readInput()
{
    if (lastCommand == command::display)
    {
        lastCommand = command::sort;
        return;
    }
    if (lastCommand == command::noType)
    {
        lastCommand = command::changeType;
        return;
    }

    string userInput;
    getline(cin, userInput);

    cout << "\n\n";

    bool shouldTreatInputAsCommand = (lastCommand != command::search);  //So commands can be locked during searches
    bool typeIsSelected = (lastCommand != command::changeType);         //So commands can be locked before a type is selected

    if (userInput == "display" && shouldTreatInputAsCommand && typeIsSelected)
    {
        lastCommand = command::sort;
    }
    else if (userInput == "add" && shouldTreatInputAsCommand && typeIsSelected)
    {
        lastCommand = command::add;
    }
    else if (userInput == "search" && shouldTreatInputAsCommand && typeIsSelected)
    {
        lastCommand = command::search;
    }
    else if (userInput == "back" && typeIsSelected)
    {
        lastCommand = command::menu;
    }
    else if(userInput == "change type" && shouldTreatInputAsCommand)
    {
        lastCommand = command::changeType;
    }
    else if(userInput == "scientists" && !typeIsSelected)
    {
        type = entryType::scientists;
        lastCommand = command::menu;
    }
    else if(userInput == "computers" && !typeIsSelected)
    {
        type = entryType::computers;
        lastCommand = command::menu;
    }
    else if (userInput == "quit")
    {
        lastCommand = command::quit;
    }
    else if(typeIsSelected)
    {
        if (lastCommand == command::add)
        {
            addCommandHandler(userInput);
        }
        else if (lastCommand == command::sort)
        {
            sortCommandHandler(userInput);
        }
        else if (lastCommand == command::search)
        {
            searchCommandHandler(userInput);
        }
        else
        {
            lastCommand = command::unknown;
        }
    }
    else
    {
        lastCommand = command::noType;
    }
}

void ConsoleUI::addCommandHandler(string userInput)
{
    if(type == entryType::scientists){
        if (addScientist(userInput)) {
            cout << "Successfully added a scientist\n\n";
            lastCommand = command::menu;
        }
        else
        {
            displayError("There was an error in your input.");
        }
    }
    else if(type == entryType::computers){
        if (addComputer(userInput)) {
            cout << "Successfully added a computer\n\n";
            lastCommand = command::menu;
        }
        else
        {
            displayError("There was an error in your input.");
        }
    }
}

void ConsoleUI::sortCommandHandler(string userInput)
{
    if(type == entryType::scientists)
    {
        if (setSciSort(userInput))
        {
            lastCommand = command::display;
        }
        else
        {
            displayError("Your input did not match any of the scientist sorting commands");
        }
    }
    else if(type == entryType::computers)
    {
        if(setCompSort(userInput))
        {
            lastCommand = command::display;
        }
        else
        {
            displayError("Your input did not match any of the computer sorting commands");
        }
    }
}

void ConsoleUI::searchCommandHandler(string userInput)
{
    if(type == entryType::scientists)
    {
        displayScientists(scientistService.searchForScientists(userInput));
    }
    else if(type == entryType::computers)
    {
        displayComputers(computerService.searchComputers(userInput));
    }
}

void ConsoleUI::displayTypeMenu()
{
    cout << "Select the type of entries you want to work with:\n";
    cout << "scientists\n";
    cout << "computers\n";
    cout << "Choice: ";
}

void ConsoleUI::displayMenu()
{
    cout << "Enter a command:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << "add:" << "Adds an entry\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << "display:" << "Displays all entries of selected type\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << "search:" << "Search for entries of selected type\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << "change type:" << "Change the entry type\n";

    cout << "Command: ";
}

void ConsoleUI::displayAddScientistMenu()
{
    cout << "To add a scientist, type in:\n";
    cout << "Name,sex,yearBorn,yearDied (yearDied is optional)\n";
    cout << "Comma separated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAddComputerMenu()
{
    cout << "To add a computer, type in:\n";
    cout << "Name,type,wasMade,yearMade where wasMade is yes/no/unknown and yearMade is optional\n";
    cout << "Comma seperated like in the example above.\n\n";
    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displayAllScientists()
{
    vector<Scientist> scientists = scientistService.getAllScientists(sortBy, sortAscending);

    displayScientists(scientists);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displayAllComputers()
{
    vector<Computer> computers = computerService.getAllComputers(sortBy, sortAscending);

    displayComputers(computers);

    cout << '\n';

    lastCommand = command::display;
}

void ConsoleUI::displaySearchMenu()
{
    cout << "Search:\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";
    cout << "Input: ";
}

void ConsoleUI::displaySortSciMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_SEX_ASCENDING << "Sorts by sex, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_SEX_DESCENDING << "Sorts by sex, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING << "Sorts by year born, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING << "Sorts by year born, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING << "Sorts by year died, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING << "Sorts by year died, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displaySortCompMenu()
{
    cout << "How should the list be sorted:\n\n";
    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_NAME_ASCENDING << "Sorts by name, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_NAME_DESCENDING << "Sorts by name, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_TYPE_ASCENDING << "Sorts by type, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_TYPE_DESCENDING << "Sorts by type, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_WAS_MADE_ASCENDING << "Sorts by whether or not it was made, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_WAS_MADE_DESCENDING << "Sorts by whether or not it was made, descending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_YEAR_MADE_ASCENDING << "Sorts by year made, ascending.\n";

    cout << setw(constants::MENU_COMMAND_WIDTH) << left
         << constants::SORT_COMPUTER_YEAR_MADE_DESCENDING << "Sorts by year made, descending.\n\n";

    cout << "If you would like to go back to the main menu, please type: back\n";

    cout << "Command: ";
}

void ConsoleUI::displayUnknownCommandMenu()
{
    displayError("Unknown command");
    cout << "Command: ";
}

void ConsoleUI::displayScientists(vector<Scientist> scientists)
{
    if (scientists.size() == 0)
    {
        cout << "No scientist found.\n";
        return;
    }

    cout << "Printing all scientists:\n";

    cout << setw(20) << left << "Name:"
         << setw(8) << left << "Sex:"
         << setw(12) << left << "Year born:"
         << setw(12) << left << "Year died:" << endl;

    for (unsigned int i = 0; i < scientists.size(); i++)
    {
        string scientistSex = (scientists.at(i).getSex() == sexType::male) ? "Male" : "Female";

        int yearDied = scientists.at(i).getYearDied();
        string died = (yearDied == constants::YEAR_NOT_ENTERED_DEFAULT_VALUE) ? "Alive" : utils::intToString(yearDied);

        cout << setw(20) << left << scientists.at(i).getName()
             << setw(8) << left << scientistSex
             << setw(12) << left << scientists.at(i).getYearBorn()
             << setw(12) << left << died << endl;
    }
}

void ConsoleUI::displayComputers(vector<Computer> computers)
{
    if(computers.size() == 0)
    {
        cout << "No computers found.\n";
        return;
    }
    cout << "Printing all computers:\n";
    cout << setw(22) << left << "Name:"
         << setw(14) << left << "Type:"
         << setw(16) << left << "Was it made?:"
         << setw(12) << left << "Year made:" << endl;

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        string compType;
        if(computers.at(i).getType() == computerType::mechanical)
            compType = "mechanical";
        else if(computers.at(i).getType() == computerType::electronic)
            compType = "electronic";
        else if(computers.at(i).getType() == computerType::transistor)
            compType = "transistor";
        else if(computers.at(i).getType() == computerType::other)
            compType = "other";

        string wasMade = computers.at(i).getWasMade();
        int year = computers.at(i).getYearMade();
        string yearMade = (year == constants::YEAR_NOT_ENTERED_DEFAULT_VALUE) ? "N/A" : utils::intToString(year);
        cout << setw(22) << left << computers.at(i).getName()
             << setw(14) << left << compType
             << setw(16) << left << wasMade
             << setw(12) << left << yearMade << endl;
    }
}

bool ConsoleUI::addScientist(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum sexType sex;
        if (fields.at(1) == "male"||fields.at(1) == " male")
        {
            sex = sexType::male;
        }
        else if (fields.at(1) == "female")
        {
            sex = sexType::female;
        }
        else
        {
            return false;
        }
        int yearBorn = utils::stringToInt(fields.at(2));

        if (fields.size() == 3)
        {
            return scientistService.addScientist(Scientist(name, sex, yearBorn));
        }
        else
        {
            int yearDied = utils::stringToInt(fields.at(3));

            return scientistService.addScientist(Scientist(name, sex, yearBorn, yearDied));
        }
    }

    return false;
}

bool ConsoleUI::addComputer(string data)
{
    vector<string> fields = utils::splitString(data, ',');

    if (fields.size() > 2 && fields.size() < 5)
    {
        string name = fields.at(0);

        enum computerType compType;
        if(fields.at(1) == "mechanical")
        {
            compType = computerType::mechanical;
        }
        else if (fields.at(1) == "electronic")
        {
            compType = computerType::electronic;
        }
        else if( fields.at(1) == "transistor")
        {
            compType = computerType::transistor;
        }
        else if( fields.at(1) == "other")
        {
            compType = computerType::other;
        }
        else
        {
            return false;
        }

        string wasBuilt = utils::stringToLower(fields.at(2));
        if(wasBuilt != "yes" && wasBuilt != "no" && wasBuilt != "unknown")
        {
            return false;
        }
        if (fields.size() == 3)
        {
            return computerService.addComputer(Computer(name, compType, wasBuilt));
        }
        else if(fields.size() == 4 && wasBuilt == "yes")
        {
            int yearMade = utils::stringToInt(fields.at(3));
            return computerService.addComputer(Computer(name, compType, wasBuilt, yearMade));
        }
    }
    return false;
}

bool ConsoleUI::setSciSort(string sortCommand)
{
    if (sortCommand == constants::SORT_SCIENTIST_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_SEX_ASCENDING)
    {
        sortBy = "sex";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_SEX_DESCENDING)
    {
        sortBy = "sex";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_ASCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_BORN_DESCENDING)
    {
        sortBy = "yearBorn";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_ASCENDING)
    {
        sortBy = "yearDied";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_SCIENTIST_YEAR_DIED_DESCENDING)
    {
        sortBy = "yearDied";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

bool ConsoleUI::setCompSort(string sortCommand)
{
    if (sortCommand == constants::SORT_COMPUTER_NAME_ASCENDING)
    {
        sortBy = "name";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_NAME_DESCENDING)
    {
        sortBy = "name";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_ASCENDING)
    {
        sortBy = "compType";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_TYPE_DESCENDING)
    {
        sortBy = "compType";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_WAS_MADE_ASCENDING)
    {
        sortBy = "wasMade";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_WAS_MADE_DESCENDING)
    {
        sortBy = "wasMade";
        sortAscending = false;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_MADE_ASCENDING)
    {
        sortBy = "yearMade";
        sortAscending = true;
    }
    else if (sortCommand == constants::SORT_COMPUTER_YEAR_MADE_DESCENDING)
    {
        sortBy = "yearMade";
        sortAscending = false;
    }
    else
    {
        return false;
    }

    return true;
}

void ConsoleUI::displayError(string error)
{
    cout << "There was an error: " << error << "\n";
    cout << "Please try again or type 'back' to go back.\n\n";
}
