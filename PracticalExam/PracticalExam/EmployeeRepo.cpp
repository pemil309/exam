#include "EmployeeRepo.h"

EmployeeRepo::EmployeeRepo(std::vector<Employee*> employees)
{
	this->employees = employees;
}

EmployeeRepo::EmployeeRepo()
{
    
}

EmployeeRepo::~EmployeeRepo()
{

}

bool EmployeeRepo::displayEmployee(std::string* display, int index)
{
    if(index < 0 || index >= this->employees.size())
        return false;

    this->employees.at(index)->toString(display);
	return true;
}

bool EmployeeRepo::add(Employee* employee)
{
	if (contains(employee->getID()))
        return false;

    this->employees.push_back(employee);
    return true;
}

void EmployeeRepo::remove(int id)
{
    uint32_t count = this->employees.size();
    bool found = false;
    while(!found && count--)
        found = this->employees.at(count)->getID() == id;

    if(found)
        this->employees.erase(employees.begin() + count);
}

bool EmployeeRepo::contains(int id)
{
    int len = this->employees.size();
	for (uint32_t i = 0; i < len; i++)
		if (id == this->employees.at(i)->getID())
			return true;

	return false;
}

std::vector<Employee*> EmployeeRepo::getList() {
    return std::vector<Employee*>(this->employees);
}
