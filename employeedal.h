#ifndef EMPLOYEEDAL_H
#define EMPLOYEEDAL_H

#include <vector>
#include "employeedto.h"
#include "../include/qt5/QtSql/QSqlError"
#include "../include/qt5/QtSql/QSqlRecord"
#include "../include/qt5/QtSql//QSqlField"
#include "../include/qt5/QtSql/QSqlDatabase"
#include "../include/qt5/QtSql/QSqlQueryModel"

class EmployeeDal {
public:
    EmployeeDal();
    std::vector<EmployeeDto> GetPeople();

private:
    QSqlDatabase m_database;

protected:
    QSqlDatabase& Database_get();
};

#endif // EMPLOYEEDAL_H
