#include "../Employee.h"

class InternEmployee : public Employee
{
public:
	InternEmployee(
        int id, 
        std::string name, 
        int year, 
        Position position, 
        int internshipDuration);

	void toString(std::string* str) override;

	int getInternshipDuration();
private:
	int internshipDuration;
};