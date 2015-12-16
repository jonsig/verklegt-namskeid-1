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

    /**
     * @brief splitString turns strings into a vector of the strings words
     * @param line input string
     * @param delimeter sign seperating words
     * @return vector of strings containing seperate words
     */
    vector<string> splitString(string line, char delimeter);

    /**
     * @brief stringToInt converts strings to integers
     * @param str input string
     * @return equivalent integer
     */
    int stringToInt(string str);

    /**
     * @brief stringToLower turns any upper case letters in a string to lower case
     * @param str input string
     * @return entirely lower case string
     */
    string stringToLower(string str);

    /**
     * @brief intToString converts integers to strings
     * @param number input integer
     * @return equivalent string
     */
    string intToString(int number);

    /**
     * @brief intToSex converts integers 0/1 to sexType::female/male respectively
     * @param number input integer
     * @return sexType::female/male
     */
    enum sexType intToSex(int number);

    /**
     * @brief stringToSex converts string to int and calls intToSex
     * @param str input string containing '0' or '1'
     * @return sexType::female/male
     */
    enum sexType stringToSex(string str);

    /**
     * @brief intToComp converts integers 0/1/2/3 to computerType::electronic/mechanical/transistor/other respectively
     * @param number input integer
     * @return computerType
     */
    enum computerType intToComp(int number);

    /**
     * @brief stringToComp converts string to integer and calls intToComp
     * @param str input string containing '0'/'1'/'2'/'3'
     * @return computerType
     */
    enum computerType stringToComp(string str);

    /**
     * @brief getDatabaseConnection establishes a non conflicting database connection
     * @return database connection
     */
    QSqlDatabase getDatabaseConnection();
}

#endif // UTILS_H

