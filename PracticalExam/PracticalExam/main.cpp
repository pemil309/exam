#include "EmployeeRepo.h"
#include "Controller.h"
#include "UI.h"

int main()
{
    Controller ctrl = Controller(EmployeeRepo());
    UI ui = UI(&ctrl);
    ui.printOptions();
	
	return 0;
}	