#include "Employee.h"

Employee::Employee(int id, std::string name, int year, Position position)
{
	this->id = id;
	this->name.assign(name);
	this->year = year;
	this->position = position;
}

Employee::Employee()
{
	this->id = 0;
	this->name.assign("UNKNOWN");
	this->year = 0;
	this->position = UNKNOWN;
}

Employee::~Employee()
{
}

bool Employee::operator==(const Employee& other)
{
	if (this->id == other.id)
		if (this->name == other.name)
			if (this->year == other.year)
				return true;
	return false;
}

int Employee::getID()
{
	return this->id;
}

std::string Employee::getName()
{
	return this->name;
}

int Employee::getYear()
{
	return this->year;
}

int Employee::getPosition()
{
	return this->position;
}

void Employee::toString(std::string* str)
{
	std::string id, year;
	id = std::to_string(this->id);
	year = std::to_string(this->year);

	char positionToString[5][10]{
		"MANAGER",
		"DEVELOPER",
		"TESTER",
		"UNKNOWN"
	};

	str->clear();
	str->append("ID: ");
	str->append(id);
	str->append("\n");
	str->append("Name: ");
	str->append(this->name);
	str->append("\n");
	str->append("Year: ");
	str->append(year);
	str->append("\n");
	str->append("Position: ");
	str->append(positionToString[(int)this->position]);
	str->append("\n");
}


////subclass1
//InternEmployee::InternEmployee(int id, std::string name, int year, Position position, int internshipDuration) : Employee(id, name, year, position)
//{
//	this->internshipDuration = internshipDuration;
//}
//
//void InternEmployee::toString(std::string* str) : toString(id, name, year, position)
//{
//	std::string internshipDuration;
//	internshipDuration = std::to_string(this->internshipDuration);
//	
//	str->append("InternshipDuration: ");
//	str->append(internshipDuration);
//	str->append("\n");
//}
//
//int InternEmployee::getInternshipDuration()
//{
//	return this->internshipDuration;
//}
//
////subclass2
//PartTimeEmployee::PartTimeEmployee(int id, std::string name, int year, Position position, int workingHour) : Employee(id, name, year, position)
//{
//	this->workingHour = workingHour;
//}
//
//void PartTimeEmployee::toString(std::string* str) : toString(id, name, year, position)
//{
//	std::string workingHour;
//	workingHour = std::to_string(this->workingHour);
//	str->append("WorkingHour: ");
//	str->append(workingHour);
//	str->append("\n");
//}
//
//int PartTimeEmployee::getWorkingHour()
//{
//	return this->workingHour;
//}