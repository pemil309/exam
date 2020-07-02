#include "Employee.h"
#include "EmployeeRepo.h"
#include <iostream>

int main()
{
	Employee* emp1 = new Employee(1, "Adam", 1999, MANAGER);
	std::cout << emp1->getID();
	
	return 0;
}	