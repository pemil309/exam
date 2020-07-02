#pragma once

#include <vector>
#include <string>

#include "Employee.h"

class EmployeeRepo
{
public:
	std::vector<Employee*> vector;

	EmployeeRepo(std::vector<Employee*> vector);
	EmployeeRepo();
	~EmployeeRepo();

	/*
	D: Gives a string representation of the object found at a certain index in the list
	I: A string display and an integer index
	O: The formatted text stored in the string display; Returns false if the index is out of bounds, true otherwise
	*/
	bool displayEmployee(std::string* display, int index);

	/*
	D: Adds an employee to the repository
	I: A pointer to the employee to be added
	O: True if the employee was added, false otherwise
	*/
	bool add(Employee* employee);

	/*
	D: Removes an employee from the repository
	I: An integer index
	O: True if the employee was removed, false otherwise
	*/
	bool remove(int index);

	/*
	D: Searches for an employee in the repository
	I: A pointer to the employee to be searched for
	O: True if the employee was found, false otherwise
	*/
	bool search(Employee* employee);
};