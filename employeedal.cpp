#include "definitions.h"
#include "employeedal.h"
#include <QString>

EmployeeDal::EmployeeDal() {

}


QSqlDatabase& EmployeeDal::Database_get() {
    if (!m_database.isOpen()) {
        m_database = QSqlDatabase::addDatabase(OdbcDriver);
        m_database.setDatabaseName("AdventureWorks2012");
        m_database.setUserName("devusr");
        m_database.setPassword("12345");
        m_database.open();
    }
    return m_database;
}


std::vector<EmployeeDto> EmployeeDal::GetPeople() {
    std::vector<EmployeeDto> retval;
    auto db = Database_get();

    if (db.open()) {
        QString queryStr("Select  distinct top 100  'ID'=A.BusinessEntityID, 'FirstName'=A.FirstName, 'LastName'=A.LastName ");
        queryStr.append("From  [AdventureWorks2012].[Person].[Person] A ");
        queryStr.append("Order by LastName");
        QSqlQueryModel query;
        query.setQuery(queryStr, db);

        auto count = query.rowCount();

        for (auto r = 0; r < (count > 0 ? count : RowCount); r++) {
            auto record = query.record(r);

            if (!record.isEmpty()) {
                EmployeeDto newRecord;
                newRecord.Id_set(record.field("ID").value().toInt());
                newRecord.FirstName_set(QString(record.field("FirstName").value().toString()));
                newRecord.LastName_set(QString(record.field("LastName").value().toString()));
                retval.push_back(newRecord);
            }
        }
        db.close();
    }

    return retval;
}
