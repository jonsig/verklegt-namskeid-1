#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

using namespace std;

/**
 * This file contains constants that this application uses
 */

namespace constants {
    const string FILE_NAME = "repository.sqlite";
    const string DATA_BASE = "QSQLITE";
    const char FILE_DELIMETER = '\t';
    const int YEAR_NOT_ENTERED_DEFAULT_VALUE = 13337;

    const unsigned int MENU_COMMAND_WIDTH = 17;

    const string SORT_SCIENTIST_NAME_ASCENDING = "name-asc";
    const string SORT_SCIENTIST_NAME_DESCENDING = "name-desc";
    const string SORT_SCIENTIST_SEX_ASCENDING = "sex-asc";
    const string SORT_SCIENTIST_SEX_DESCENDING = "sex-desc";
    const string SORT_SCIENTIST_YEAR_BORN_ASCENDING = "born-asc";
    const string SORT_SCIENTIST_YEAR_BORN_DESCENDING = "born-desc";
    const string SORT_SCIENTIST_YEAR_DIED_ASCENDING = "died-asc";
    const string SORT_SCIENTIST_YEAR_DIED_DESCENDING = "died-desc";

    const string SORT_COMPUTER_NAME_ASCENDING = "name-asc";
    const string SORT_COMPUTER_NAME_DESCENDING = "name-desc";
    const string SORT_COMPUTER_TYPE_ASCENDING = "type-asc";
    const string SORT_COMPUTER_TYPE_DESCENDING = "type-desc";
    const string SORT_COMPUTER_WAS_MADE_ASCENDING = "wasMade-asc";
    const string SORT_COMPUTER_WAS_MADE_DESCENDING = "wasMade-desc";
    const string SORT_COMPUTER_YEAR_MADE_ASCENDING = "yearMade-asc";
    const string SORT_COMPUTER_YEAR_MADE_DESCENDING = "yearMade-desc";

}

#endif // CONSTANTS_H

