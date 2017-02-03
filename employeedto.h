#ifndef EMPLOYEEDTO
#define EMPLOYEEDTO

#endif // EMPLOYEEDTO


#include <QString>

class EmployeeDto {
private:
    int m_id;
    QString m_lastName;
    QString m_firstName;

public:
    EmployeeDto();
    EmployeeDto(int id, QString firstname, QString lastname);

    int Id_get() const;
    QString FirstName_get() const;
    QString LastName_get() const;
    void Id_set(int value);
    void FirstName_set(QString value);
    void LastName_set(QString value);
};
