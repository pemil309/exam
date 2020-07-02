	#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::printOption()
{
	char op;
	std::cout << "Please select an option: " << "\n" << "A - Add an employee" << "\n" << "R - Remove an employee" << "\n" 
		<< "D - Display employees containing a substring" << "\n" << "L - Load employees" << "\n" << "E - Exit" << "\n";
	while (true)
	{
		system("@cls||clear");
		std::cin >> op;
		switch (op)
		{
			case 'a':
				this->uiAddEmployee();
				break;
			case 'r':
				this->uiRemoveEmployee();
				break;
			/*case 'd':
				this->displayEmployeesContainingSubstring();
				break;*/
			case 'l':
				this->controller.loadEmployees();
				break;
			case 'e':
				exit(0);
			default:
				std::cout << "Unknown option" << "\n";
				continue;
		}
	}
}

void UI::uiAddEmployee()
{
	int id;
	std::string name;
	int year;
	Position position;
	int p;

	int type;


	std::cout << "Employee ID:" << '\n';
	std::cin >> id;
	std::cout << "Employee name:" << '\n';
	std::cin >> name;
	std::cout << "Employee birth year:" << '\n';
	std::cin >> year;
	std::cout << "Employee position" << "\n";
	std::cout << "1. Manager" << "\n" << "2. Developer" << "\n" << "3. Tester" << "\n" << "4. Unknown" << "\n";
	std::cin >> p;
	position = static_cast<Position>(p);
	std::cout << "Employee type: " << "\n";
	std::cin >> type;

	Employee* employee = &Employee(id, name, year, position);

	if (!this->controller.addEmployee(employee, type)) {
		system("@cls||clear");
		std::cout << '\n' << "Incorrect Data!" << '\n';
	}
	else
		std::cout << "Operation completed succesfully!" << '\n';

}

void UI::uiRemoveEmployee()
{
	int index;
	std::cout << "Please give the index of the employee you want to remove: ";
	std::cin >> index;
	if (!this->controller.removeEmployee(index - 1))
		std::cout << '\n' << "Operation failed!" << '\n';
	else
		std::cout << '\n' << "Operation succesful!" << '\n';
}

void UI::addEmployee(Employee* employee, int type)
{
	if (!this->controller.addEmployee(employee, type))
		std::cout << "This employee is already in the list";
}

void UI::removeEmployee(int index)
{
	if (!this->controller.removeEmployee(index))
		std::cout << "This employee is not in the list";
}

//toDo
//void UI::displayEmployeesContainingSubstring()
//{
	/*std::string subs = "";
	std::cout << "What substring do you want to add?" << "\n";
	std::cin >> ss;

	for (gnr = 0; gnr < 6; gnr++)
		if (genre == genreToString[gnr])
			break;

	if (genre.empty())
		gnr = -1;


	int unsigned iterator = 0;
	while (iterator < this->ClientController.repo.vector.size()) {
		int i = (int)this->ClientController.repo.vector.at(iterator)->getGenre();
		if (genre == genreToString[i])
			uiDisplayBook(iterator, bookList);
		iterator++;
	}*/
//}
