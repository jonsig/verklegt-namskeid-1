#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <QtSql>

#include "models/scientist.h"
#include "models/computer.h"

using namespace std;

/**
 * This file contains reusable utility functions used throughout the application
 */

namespace utils {    
    vector<string> splitString(string line, char delimeter);

    int stringToInt(string str);

    string stringToLower(string str);

    string intToString(int number);

    enum sexType intToSex(int number);

    enum sexType stringToSex(string str);

    enum computerType intToComp(int number);

    enum computerType stringToComp(string str);

    QSqlDatabase getDatabaseConnection();
}

#endif // UTILS_H

