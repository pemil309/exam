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
    return 
        this->id == other.id &&
        this->name == other.name && 
        this->year == other.year;
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
