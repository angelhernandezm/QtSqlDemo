#include "employeedto.h"

int EmployeeDto::Id_get() const {
    return m_id;
}

QString EmployeeDto::FirstName_get() const {
    return m_firstName;
}

QString EmployeeDto::LastName_get() const {
    return m_lastName;
}

void EmployeeDto::Id_set(int value) {
    m_id = value;
}

void EmployeeDto::FirstName_set(QString value) {
    m_firstName = value;
}

void EmployeeDto::LastName_set(QString value) {
    m_lastName = value;
}

EmployeeDto::EmployeeDto() {

}

EmployeeDto::EmployeeDto(int id, QString firstname, QString lastname): EmployeeDto() {
    m_id = id;
    m_lastName = lastname;
    m_firstName = firstname;
}
