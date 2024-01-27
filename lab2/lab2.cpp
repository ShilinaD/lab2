#include <iostream>
#include <string>
#include "funcs.h"

int main()
{
	setlocale(LC_ALL, "ru");

	// Демонстрация перемещения
	Lab2::Wagon first_wagon;
	Lab2::Wagon second_wagon;
	first_wagon = Lab2::Wagon(60, 55, Lab2::WagonType::ECONOMY);
	second_wagon = Lab2::Wagon(55, 10, Lab2::WagonType::ECONOMY);

	/*std::cout << "До перемещения:" << std::endl;
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();
	second_wagon.Get_Info();
	second_wagon.Get_Percent_Taken();
	first_wagon >> second_wagon;
	std::cout << "После перемещения:" << std::endl;
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();
	second_wagon.Get_Info();
	second_wagon.Get_Percent_Taken();*/

	while (true) {
		// Вывод меню программы
		PrintMenu();
		int answer = InputInt();

		if (answer == 1) {
			WagonProgram();
		}
		if (answer == 2) {
			TrainProgram();
		}
		else if (answer == 3) {
			break;
		}
		else {
			std::cout << "Вы можете ввести только числа 1,2 или 3!!!" << std::endl;
		}
	}

	return 0;
}
