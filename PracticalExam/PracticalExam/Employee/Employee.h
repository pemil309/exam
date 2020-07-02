#pragma once

#include <string>

typedef enum {
	MANAGER,
	DEVELOPER,
	TESTER,
	UNKNOWN
} Position;

class Employee
{
private:
	int id;
	std::string name;
	int year;
	Position position;

public:
	Employee(int id, std::string name, int year, Position position);
	Employee();
	~Employee();

	bool operator==(const Employee& other);

	//getters
	int getID();
	std::string getName();
	int getYear();
	int getPosition();

	/*
	D: Gives a string representation of the object
	I: A string str
	O: The formatted text stored in the string str
	*/
	virtual void toString(std::string* str);
};