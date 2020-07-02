#pragma once

#include <vector>
#include <string>

#include "Employee/Employee.h"

class EmployeeRepo
{
private:
    std::vector<Employee*> employees;

public:

	EmployeeRepo(std::vector<Employee*> employees);
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
	D: Searches for an employee by id
	I: The employee's id
	O: True if the employee was found, false otherwise
	*/
	bool contains(int id);

    /*
	D: Returns a pointer to an employee
	I: The employee's id
	O: Pointer to the employee if found, null otherwise
	*/
	Employee* get(int id);

    /*
	D: Returns a list of employees
	I: -
	O: A list of employees
	*/
	std::vector<Employee*> getList();

	/*
	D: Removes an employee from the repository
	I: The ID of the employee
	O: -
	*/
	void remove(int id);
};