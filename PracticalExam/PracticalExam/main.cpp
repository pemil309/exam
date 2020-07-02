#include "./Employee/PartTimeEmployee.h"
#include "./Employee/InternEmployee.h"
#include "Employee.h"
#include "EmployeeRepo.h"
#include "Controller.h"
#include "UI.h"
#include <iostream>

int main()
{
	// Employee* emp1 = new Employee(1, "Adam", 1999, MANAGER);
	// InternEmployee* emp2 = new InternEmployee(1, "Emi", 1999, MANAGER, 2);
	// PartTimeEmployee* emp3 = new PartTimeEmployee(1, "Tony", 1999, MANAGER, 8);
    // std::string str;
    // emp1->toString(&str);
	// std::cout << str;
    // emp2->toString(&str);
	// std::cout << str;
    // emp3->toString(&str);
	// std::cout << str;

    Controller ctrl = Controller(EmployeeRepo());
    UI ui = UI(&ctrl);
    ui.printOption();
	
	return 0;
}	