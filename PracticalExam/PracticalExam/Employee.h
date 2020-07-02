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
	void toString(std::string* str);
};

//class InternEmployee : public Employee
//{
//public:
//	InternEmployee(int id, std::string name, int year, Position position, int internshipDuration);
//
//	void toString(std::string* str);
//
//	int getInternshipDuration();
//private:
//	int internshipDuration;
//};
//
//class PartTimeEmployee : public Employee
//{
//public:
//	PartTimeEmployee(int id, std::string name, int year, Position position, int workingHour);
//
//	void toString(std::string* str);
//
//	int getWorkingHour();
//private:
//	int workingHour;
//};