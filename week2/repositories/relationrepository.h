#ifndef CONNECTIONREPOSITORY_H
#define CONNECTIONREPOSITORY_H

#include <vector>
#include <string>
#include <QtSql>

#include "models/computer.h"
#include "models/scientist.h"

using namespace std;

class RelationRepository
{
public:
    RelationRepository();

    bool addConnection(string compName, string sciName);

    bool connectThe(Scientist scientist, Computer computer);

private:
    QSqlDatabase db;
};

#endif // CONNECTIONREPOSITORY_H
