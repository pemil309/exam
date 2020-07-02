#include "Employee.h"

class PartTimeEmployee : public Employee
{
public:
	PartTimeEmployee(int id, std::string name, int year, Position position, int workingHour);

	void toString(std::string* str) override;

	int getWorkingHour();
private:
	int workingHour;
};