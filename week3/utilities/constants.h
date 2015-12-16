#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

using namespace std;

/**
 * This file contains constants that this application uses
 */

namespace constants {
    const string DATABASE_NAME = "repository.sqlite";   //database file name
    const string DATABASE_TYPE = "QSQLITE";

    const int YEAR_NOT_ENTERED_DEFAULT_VALUE = 13337;   //default year value
}

#endif // CONSTANTS_H

