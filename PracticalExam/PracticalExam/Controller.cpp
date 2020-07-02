#include "Controller.h"

Controller::Controller(EmployeeRepo repo, EmployeeRepo substring)
{
	this->repo = repo;
	this->substring = substring;
}

Controller::Controller()
{

}

Controller::~Controller()
{

}

void Controller::loadEmployees()
{
	Employee* a1 = new Employee(1, "Adam", 1999, DEVELOPER);
	Employee* a2 = new Employee(2, "Marcus", 1980, MANAGER);
	Employee* a3 = new Employee(3, "Erika", 1997, DEVELOPER);
	//Employee* b = new InternEmployee(4, "Ares", 1998, DEVELOPER, 130);
	//Employee* c = new PartTimeEmployee(5, "Ana", 1993, TESTER, 4);

	this->addEmployee(a1, 1);
	this->addEmployee(a2, 1);
	this->addEmployee(a3, 1);
	//this->addEmployee(b, 2);
	//this->addEmployee(c, 3);
}

bool Controller::addEmployee(Employee* employee, int type)
{
	if (type == 1)
		return this->repo.add(employee);
	else if (type == 2)
		this->addInternEmployee(employee);
	else if (type == 3)
		this->addPartTimeEmployee(employee);
}

bool Controller::addInternEmployee(Employee* employee) {
	return this->repo.add(employee);
}

bool Controller::addPartTimeEmployee(Employee* employee) {
	return this->repo.add(employee);
}

bool Controller::removeEmployee(int index)
{
	return this->repo.remove(index);
}

bool Controller::displayEmployee(std::string* display, int index)
{
	return this->repo.displayEmployee(display, index);
}

//TO DO: DISPLAYED SORTED BY YEAR
void Controller::displayEmployeesContainingSubstring(std::string ss)
{
	if (ss == "")
	{
		for (int i = 0; i <= this->repo.vector.size(); i++)
		{
			std::string* display1 = NULL;
			this->displayEmployee(display1, i);
		}
	}
	else
	{
		for (int i = 0; i <= this->repo.vector.size(); i++)
		{
			if (this->repo.vector.at(i)->getName().find(ss) != std::string::npos)
				this->substring.add(this->repo.vector.at(i));
		}
	}

	for (int i = 0; i <= this->substring.vector.size(); i++)
	{
		std::string* display2 = NULL;
		this->displayEmployee(display2, i);
	}
}