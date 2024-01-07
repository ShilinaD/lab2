#include "funcs.h"

int main()
{
	setlocale(LC_ALL, "ru");
	while (true) {
		// Вывод меню программы
		PrintMenu();
		int answer = InputInt();

		if (answer == 1) {
			WagonProgram();
		}
		if (answer == 2) {
			break;
		}
		else if (answer == 3) {
			break;
		}
		else {
			std::cout << "Вы можете ввести только числа 1,2 или 3!!!" << std::endl;
		}
	}
	

	//Lab2::Wagon first_wagon;
	//Lab2::Wagon second_wagon;
	//

	//first_wagon.CreateWagon(45, 15, Lab2::WagonType::ECONOMY);
	//first_wagon.Get_Info();
	//first_wagon.Get_Percent_Taken();
	///*first_wagon.Boarding(20);
	//first_wagon.Get_Info();
	//first_wagon.Get_Percent_Taken();
	//first_wagon.Вisembarkation(5);
	//first_wagon.Get_Info();
	//first_wagon.Get_Percent_Taken();*/

	//second_wagon.CreateWagon(55, 25, Lab2::WagonType::ECONOMY);
	//second_wagon.Get_Info();
	//second_wagon.Get_Percent_Taken();

	///*first_wagon >> second_wagon;
	//std::cout << "DDDD" << std::endl;
	//first_wagon.Get_Info();
	//first_wagon.Get_Percent_Taken();
	//second_wagon.Get_Info();
	//second_wagon.Get_Percent_Taken();*/



	return 0;
}
