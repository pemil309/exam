#include "EmployeeRepo.h"

EmployeeRepo::EmployeeRepo(std::vector<Employee*> vector)
{
	this->vector = vector;
}

EmployeeRepo::EmployeeRepo()
{

}

EmployeeRepo::~EmployeeRepo()
{

}

bool EmployeeRepo::displayEmployee(std::string* display, int index)
{
	if (index >= 0 && index <= this->vector.size())
		this->vector.at(index)->toString(display);
	else
		return 0;
	return 1;
}

bool EmployeeRepo::add(Employee* employee)
{
	if (search(employee) == -1)
	{
		this->vector.push_back(employee);
		return 1;
	}
	else
		return 0;
}

bool EmployeeRepo::remove(int index)
{
	if (index >= 0 && index <= this->vector.size())
	{
		this->vector.erase(vector.begin() + index);
		return 1;
	}
	return 0;
}

bool EmployeeRepo::search(Employee* employee)
{	
	unsigned int i;
	for (i = 0; i < this->vector.size(); i++)
	{
		if (*employee == *this->vector.at(i))
			return i;
	}
	return -1;
}