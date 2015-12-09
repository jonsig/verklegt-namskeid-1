#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

/**
 * This file contains constants that this application uses
 */

namespace constants {
    const std::string FILE_NAME = "repository.sqlite";
    const std::string DATA_BASE = "QSQLITE";
    const char FILE_DELIMETER = '\t';
    const int YEAR_NOT_ENTERED_DEFAULT_VALUE = 13337;

    const unsigned int MENU_COMMAND_WIDTH = 15;

    const std::string SORT_SCIENTIST_NAME_ASCENDING = "name-asc";
    const std::string SORT_SCIENTIST_NAME_DESCENDING = "name-desc";
    const std::string SORT_SCIENTIST_SEX_ASCENDING = "sex-asc";
    const std::string SORT_SCIENTIST_SEX_DESCENDING = "sex-desc";
    const std::string SORT_SCIENTIST_YEAR_BORN_ASCENDING = "born-asc";
    const std::string SORT_SCIENTIST_YEAR_BORN_DESCENDING = "born-desc";
    const std::string SORT_SCIENTIST_YEAR_DIED_ASCENDING = "died-asc";
    const std::string SORT_SCIENTIST_YEAR_DIED_DESCENDING = "died-desc";

    const std::string SORT_COMPUTER_NAME_ASCENDING = "name-asc";
    const std::string SORT_COMPUTER_NAME_DESCENDING = "name-desc";
    const std::string SORT_COMPUTER_TYPE_ASCENDING = "type-asc";
    const std::string SORT_COMPUTER_TYPE_DESCENDING = "type-desc";
    const std::string SORT_COMPUTER_WAS_MADE_ASCENDING = "wasMade-asc";
    const std::string SORT_COMPUTER_WAS_MADE_DESCENDING = "wasMade-desc";
    const std::string SORT_COMPUTER_YEAR_MADE_ASCENDING = "yearMade-asc";
    const std::string SORT_COMPUTER_YEAR_MADE_DESCENDING = "yearMade-desc";

}

#endif // CONSTANTS_H

