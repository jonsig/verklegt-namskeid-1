#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>
#include <QtSql>

#include "models/computer.h"

class ComputerRepository
{
public:
    ComputerRepository();
    std::vector<Computer> getComputer(std::string filter);
    bool addComputer(Computer computer);
private:
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
