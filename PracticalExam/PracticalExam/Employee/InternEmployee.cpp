#include "InternEmployee.h"

InternEmployee::InternEmployee(int id, std::string name, int year, Position position, int internshipDuration) : Employee(id, name, year, position)
{
	this->internshipDuration = internshipDuration;
}

void InternEmployee::toString(std::string* str)
{
    Employee::toString(str);
	str->append("InternshipDuration: ");
	str->append(std::to_string(this->internshipDuration));
	str->append("\n");
}

int InternEmployee::getInternshipDuration()
{
	return this->internshipDuration;
}