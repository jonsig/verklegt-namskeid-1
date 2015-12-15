#include "utilities/utils.h"
#include "utilities/constants.h"

#include <sstream>
#include <cstdlib>

using namespace std;

namespace utils {
    vector<string> splitString(string line, char delimeter)
    {
        vector<string> result;

        string currentWord = "";

        for (unsigned int i = 0; i < line.length(); i++) 
        {
            char currentChar = line[i];

            if (currentChar == delimeter) 
            {
                if  (currentWord.length()) {
                    result.push_back(currentWord);
                    currentWord = "";
                }
            } 
            else 
            {
                if (currentChar != '\n') 
                {
                    currentWord += currentChar;
                }
            }
        }

        if (currentWord.length()) 
        {
            result.push_back(currentWord);
        }

        return result;
    }

    int stringToInt(string str)
    {
        return atoi(str.c_str());
    }

    string stringToLower(string str)
    {
        string result = "";

        for (unsigned int i = 0; i < str.length(); i++)
        {
            char currentCharacter = str[i];

            // http://www.asciitable.com/
            if (currentCharacter <= 90 && currentCharacter >= 65)
            {
                result += currentCharacter + 32;
            }
            else
            {
                result += currentCharacter;
            }
        }

        return result;
    }

    string intToString(int number)
    {
        stringstream stream;
        stream << number;
        return stream.str();
    }

    enum sexType intToSex(int number) 
    {
        return static_cast<enum sexType>(number);
    }

    enum sexType stringToSex(string str)
    {
        return intToSex(stringToInt(str));
    }

    enum computerType intToComp(int number)
    {
        return static_cast<enum computerType>(number);
    }

    enum computerType stringToComp(string str)
    {
        return intToComp(stringToInt(stringToLower(str)));
    }

    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "Smuu";
        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase(constants::DATABASE_TYPE.c_str(), connectionName);
            db.setDatabaseName(constants::DATABASE_NAME.c_str());

            db.open();
        }

        return db;
    }
}
