#include "EmployeeRepo.h"
#include "Employee.h"
#include <vector>
#include <string>

class Controller {
public:
    EmployeeRepo repo;
    EmployeeRepo substring;

    Controller(EmployeeRepo repo, EmployeeRepo substring);
    Controller();
    ~Controller();

    //loads employees into the repository
    void loadEmployees();

    /*
    D: Adds an employee to the repo repository
    I: A pointer to the employee to be added
    O: True if the employee was added succesfully, false if the employee was already in the repository
    */
    bool addEmployee(Employee* employee, int type);

    /*
    D: Adds an employee to the repo repository
    I: A pointer to the employee to be added
    O: True if the employee was added succesfully, false if the employee was already in the repository
    */
    bool addInternEmployee(Employee* employee);

    /*
    D: Adds an employee to the repo repository
    I: A pointer to the employee to be added
    O: True if the employee was added succesfully, false if the employee was already in the repository
    */
    bool addPartTimeEmployee(Employee* employee);

    /*
    D: Removes an employee from the repo repository
    I: The index of the employee to be removed
    O: True if the employee was removed succesfully, false if the employee was not in the repository
    */
    bool removeEmployee(int index);

    /*
    D: Gives a string representation of the object found at a certain index in the repo repository
    I: A string display and an integer index
    O: The formatted text stored in the string display; Returns false if the index is out of bounds, true otherwise
    */
    bool displayEmployee(std::string* display, int index);

    /*
    D: Displays all employees whose name contains the substring ss
    I: The string ss
    O: -
    */
    void displayEmployeesContainingSubstring(std::string ss);
};