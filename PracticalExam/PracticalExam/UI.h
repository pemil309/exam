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


	void printOption();
	void uiAddEmployee();
	void uiRemoveEmployee();
	/*
	D: Adds an employee to the controller's repo repository
	I: A pointer to the employee to be added
	O: A message stating if the employee was added or not 
	*/
	void addEmployee(Employee* employee);
	
	/*
	D: Removes an employee form the controller's repo repository
	I: A pointer to the employee to be removed
	O: A message stating if the employee was removed or not
	*/
	void removeEmployee(int index);

	/*
	D: Displays all employees whose name contains a certain substring
	I: -
	O: Displays the employees containing filtered by a name pattern
	*/
	void displayFilteredEmployees();
};