#include "UI.h"
#include "Employee/InternEmployee.h"
#include "Employee/PartTimeEmployee.h"

int read_int();

UI::UI(Controller* controller)
{
    this->controller = controller;
}

UI::~UI()
{
}

void UI::printOption()
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
				this->uiAddEmployee();
				break;
			case 'r':
				this->uiRemoveEmployee();
				break;
			case 'd':
				this->displayFilteredEmployees();
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

void UI::uiAddEmployee()
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
        while(duration == -1) {
            duration = read_int();
            if(duration == -1) {
                std::cout << "Please input a number.\n";
                continue;
            }
        }
    }
    else if(type == 3) {
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
        employee = new InternEmployee(id, name, year, position, duration);
        break;
    case 3:
        employee = new PartTimeEmployee(id, name, year, position, duration);
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

void UI::uiRemoveEmployee()
{
	int index;
	std::cout << "Please give the index of the employee you want to remove: ";
	std::cin >> index;
	if (!this->controller->removeEmployee(index - 1))
		std::cout << '\n' << "Operation failed!" << '\n';
	else
		std::cout << '\n' << "Operation succesful!" << '\n';
}

void UI::addEmployee(Employee* employee)
{
	if (!this->controller->addEmployee(employee))
		std::cout << "This employee is already in the list";
}

void UI::removeEmployee(int index)
{
	if (!this->controller->removeEmployee(index))
		std::cout << "This employee is not in the list";
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

void UI::displayFilteredEmployees()
{
	std::string filter;
	std::cout << "What substring do you want to add?" << "\n";
    read_string(&filter);
    
    if(filter.empty())
        std::cout << "\n" << "Display everything" << "\n";
    else
        std::cout << "\n" << "Filter is:" << filter << "\n";

    std::cin >> filter;
    this->controller->filterEmployeesByName(filter);
	
	// int unsigned iterator = 0;
	// while (iterator < this->ClientController.repo.vector.size()) {
	// 	int i = (int)this->ClientController.repo.vector.at(iterator)->getGenre();
	// 	if (genre == genreToString[i])
	// 		uiDisplayBook(iterator, bookList);
	// 	iterator++;
	// }
}
