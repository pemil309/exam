#pragma once

#include "Controller.h"

#include <string>
#include <iostream>

class UI
{
private:
	Controller* controller;

public:
	UI(Controller* controller);
	~UI();


	void printOptions();
	/*
	D: Adds an employee to the controller's repo repository
	I: A pointer to the employee to be added
	O: A message stating if the employee was added or not 
	*/
	void addEmployee();
	
	/*
	D: Removes an employee form the controller's repo repository
	I: A pointer to the employee to be removed
	O: A message stating if the employee was removed or not
	*/
	void removeEmployee();

	/*
	D: Asks for a name pattern and displays the employees matching that pattern
	I: -
	O: -
	*/
	void displayEmployeesFilteredByNameAndSortedByYear();
};