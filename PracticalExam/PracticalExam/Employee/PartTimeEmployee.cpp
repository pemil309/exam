#include "PartTimeEmployee.h"

PartTimeEmployee::PartTimeEmployee(int id, std::string name, int year, Position position, int workingHour) : Employee(id, name, year, position)
{
	this->workingHour = workingHour;
}

void PartTimeEmployee::toString(std::string* str)
{
	Employee::toString(str);
	str->append("WorkingHour: ");
	str->append(std::to_string(this->workingHour));
	str->append("\n");
}

int PartTimeEmployee::getWorkingHour()
{
	return this->workingHour;
}