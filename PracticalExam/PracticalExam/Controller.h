#pragma once
#include "EmployeeRepo.h"
#include "Employee/Employee.h"
#include <vector>
#include <string>

class Controller {
private:
    EmployeeRepo repo;
    
public:
    Controller(EmployeeRepo repo);
    ~Controller();

    //loads employees into the repository
    void loadEmployees();

    /*
    D: Adds an employee to the repo repository
    I: A pointer to the employee to be added
    O: True if the employee was added succesfully, false if the employee was already in the repository
    */
    bool addEmployee(Employee* employee);

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
    D: Checks if there's an employee with the specified ID
    I: The ID of the employee
    O: True if the employee exists, otherwise false
    */
    bool hasEmployee(int id);

    /*
    D: Removes an employee from the repo repository
    I: The ID of the employee to be removed
    O: -
    */
    void removeEmployee(int id);

    /*
    D: Gives a string representation of the object found at a certain index in the repo repository
    I: A string display and an integer index
    O: The formatted text stored in the string display; Returns false if the index is out of bounds, true otherwise
    */
    bool displayEmployee(std::string* display, int index);

    /*
    D: Displays all employees whose name contains the specified pattern
    I: The string pattern
    O: -
    */
    std::vector<Employee*> filterEmployeesByName(std::string pattern);
};
