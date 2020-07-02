#include "UI.h"
#include "Employee/InternEmployee.h"
#include "Employee/PartTimeEmployee.h"
#include <algorithm>

int read_int();
void read_string(std::string* str);
bool sort_by_year(Employee* a, Employee* b);

UI::UI(Controller* controller)
{
    this->controller = controller;
}

UI::~UI()
{
}

void UI::printOptions()
{
	char op;
	while (true)
	{
        std::cout 
        << "Please select an option: " << "\n" 
        << "A - Add an employee" << "\n" 
        << "R - Remove an employee" << "\n" 
		<< "D - Display employees containing a substring" << "\n" 
        << "L - Load employees" << "\n" 
        << "E - Exit" << "\n";
        
		std::cin >> op;
		switch (op)
		{
			case 'a':
				this->addEmployee();
				break;
			case 'r':
				this->removeEmployee();
				break;
			case 'd':
				this->displayEmployeesFilteredByNameAndSortedByYear();
				break;
			case 'l':
				this->controller->loadEmployees();
				break;
			case 'e':
				exit(0);
			default:
				std::cout << "Unknown option" << "\n";
				continue;
		}
		system("@cls||clear");
	}
}

void UI::addEmployee()
{	
    std::cout << "Employee type: " << "\n";
    std::cout << "1. Full-time employee" << "\n";
    std::cout << "2. Part-time employee" << "\n";
    std::cout << "3. Intern" << "\n";

	int type = -1;
    std::string type_str;
    while(type == -1) {
        type = read_int();
        if(type == -1) {
            std::cout << "Please input a number.\n";
            continue;
        }
    }

    int id = -1;
	std::cout << "Employee ID:" << '\n';
    while(id == -1) {
        id = read_int();
        if(id == -1) {
            std::cout << "Please input a number.\n";
            continue;
        }
    }

    std::string name;
	std::cout << "Employee name:" << '\n';
	std::cin >> name;

    int year = -1;
	std::cout << "Employee birth year:" << '\n';
	while(year == -1) {
        year = read_int();
        if(year == -1) {
            std::cout << "Please input a number.\n";
            continue;
        }
    }

    int p = -1;
    Position position;
	std::cout << "Employee position" << "\n";
	std::cout 
    << "1. Manager" << "\n" 
    << "2. Developer" << "\n" 
    << "3. Tester" << "\n" 
    << "4. Unknown" << "\n";

	while(p == -1) {
        p = read_int();
        if(p == -1) {
            std::cout << "Please input a number.\n";
            continue;
        }
        p--;
    }
	position = static_cast<Position>(p);

    int duration = -1;
    if(type == 2) {
	    std::cout << "Working hours: " << "\n";
        while(duration == -1) {
            duration = read_int();
            if(duration == -1) {
                std::cout << "Please input a number.\n";
                continue;
            }
        }
    }
    else if(type == 3) {
	    std::cout << "Internship duration (years): " << "\n";
        while(duration == -1) {
            duration = read_int();
            if(duration == -1) {
                std::cout << "Please input a number.\n";
                continue;
            }
        }
    }
	
    Employee* employee;
    switch (type)
    {
    case 1:
        employee = new Employee(id, name, year, position);
        break;
    case 2:
        employee = new PartTimeEmployee(id, name, year, position, duration);
        break;
    case 3:
        employee = new InternEmployee(id, name, year, position, duration);
        break;
    default:
        break;
    }

	if (!this->controller->addEmployee(employee)) {
		system("@cls||clear");
		std::cout << '\n' << "Incorrect Data!" << '\n';
	}
	else {
        char ok;
		std::cout << "Operation completed succesfully!" << '\n';
        std::cin >> ok;
    }

}

void UI::removeEmployee()
{
	std::cout << "Employee's ID: ";
    int id = -1;
    while(id == -1) {
        id = read_int();
        if(id == -1) {
            std::cout << "Please input a number.\n";
            continue;
        }
    }

    bool exists = this->controller->hasEmployee(id);
    if(exists) {
        std::string id_str;
        bool should_delete = false;
        id_str = std::cin.get();
        while(true) {
            std::cout << "Are you sure you want to remove this employee? ";
            id_str = std::cin.get();
            should_delete = id_str == "y";
            break;
            // if(id_str == "y") {
            //     should_delete = true;
            //     break;
            // } else if(id_str == "n") {
            //     should_delete = false;
            //     break;
            // }
        }

        if(should_delete) {
	        this->controller->removeEmployee(id);
            std::cout << "The employee has been removed." << "\n";
        } else {
            std::cout << "Removal operation canceled." << "\n";
        }
    } else {
        std::cout << "There's no employee matching that ID." << "\n";
    }

    while(true) {
        std::cin.get();
        break;
    }
}

void UI::displayEmployeesFilteredByNameAndSortedByYear()
{
	std::string filter;
	std::cout << "What substring do you want to add?" << "\n";
    read_string(&filter);

    std::string output;
    std::string employee_str;
    
    std::vector<Employee*> filteredEmployees = this->controller->filterEmployeesByName(filter);
	std::sort(filteredEmployees.begin(), filteredEmployees.end(), sort_by_year);
    
    uint32_t count = filteredEmployees.size();
    if(count > 0) {
        for (uint32_t i = 0; i < count; i++) {
            filteredEmployees.at(i)->toString(&employee_str);
            output.append(employee_str);
            output.append("\n");
        }
    }
    else
        output = "No employees found matching the specified pattern..";

    std::cout << output;
    while(true) {
        filter = std::cin.get();
        break;
    }
}

bool sort_by_year(Employee* a, Employee* b) {
    return a->getYear() < b->getYear();
}

int read_int() {
    int result;
    std::string result_str;
    std::cin >> result_str;
    try {
        result = std::stoi(result_str);
    } catch (std::invalid_argument ex) {
        result = -1;
    }

    return result;
}

void read_string(std::string* str) {
    std::string in;
    in = std::cin.get();
    while(true) {
        in = std::cin.get();
        if(in == "\n")
            break;
        else
            str->append(in);
    }
}
