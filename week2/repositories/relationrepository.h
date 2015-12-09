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

    bool addRelation(string compName, string sciName);

private:
    QSqlDatabase db;
};

#endif // CONNECTIONREPOSITORY_H
