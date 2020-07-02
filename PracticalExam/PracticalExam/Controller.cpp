#include "Employee/InternEmployee.h"
#include "Employee/PartTimeEmployee.h"
#include "Controller.h"
#include <string>

std::string* to_lower(std::string* str);

Controller::Controller(EmployeeRepo repo)
{
	this->repo = repo;
}

Controller::~Controller()
{

}

void Controller::loadEmployees()
{
	Employee* a1 = new Employee(1, "Adam", 1999, DEVELOPER);
	Employee* a2 = new Employee(2, "Marcus", 1980, MANAGER);
	Employee* a3 = new Employee(3, "Erika", 1997, DEVELOPER);
	Employee* b = new InternEmployee(4, "Ares", 1998, DEVELOPER, 130);
	Employee* c = new PartTimeEmployee(5, "Ana", 1993, TESTER, 4);

	this->addEmployee(a1);
	this->addEmployee(a2);
	this->addEmployee(a3);
	this->addEmployee(b);
	this->addEmployee(c);
}

bool Controller::addEmployee(Employee* employee)
{
    return this->repo.add(employee);
}

void Controller::removeEmployee(int id)
{
	this->repo.remove(id);
}

bool Controller::displayEmployee(std::string* display, int index)
{
	return this->repo.displayEmployee(display, index);
}

std::vector<Employee*> Controller::filterEmployeesByName(std::string pattern) {
    std::vector<Employee*> results;
    std::vector<Employee*> employees = this->repo.getList();
    uint32_t count = employees.size();

    for (uint32_t i = 0; i < count; i++)
    {
        Employee* emp = employees.at(i);
        std::string name = emp->getName();
        size_t idx = to_lower(&name)->find(pattern);
        if(idx != std::string::npos)
            results.push_back(emp);
    }
    
    return results;
}

bool Controller::hasEmployee(int id) {
    return this->repo.contains(id);
}

std::string* to_lower(std::string* str) {
    uint32_t count = str->size();
    for (uint32_t i = 0; i < count; i++)
        (*str)[i] = tolower((*str)[i]);

    return str;
}