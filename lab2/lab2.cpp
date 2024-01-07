#include "lab2.h"

//(>> ) переместить пассажиров из одного вагона в другой так, чтобы их процент занятости был примерно равен;


enum class WagonType {
	SITTING,
	ECONOMY,
	LUXURY,
	RESTAURANT
};

std::string WagonTypeToString(WagonType type) {
	switch (type) {
	case WagonType::SITTING:
		return "Сидячий";
	case WagonType::ECONOMY:
		return "Эконом";
	case WagonType::LUXURY:
		return "Люкс";
	case WagonType::RESTAURANT:
		return "Ресторан";
	default:
		return "Неизвестный тип";
	}
};

class Wagon {
private:
	int capacity = 1;
	int taken = 1;
	WagonType type = WagonType::SITTING;

public:
	// конструктор
	Wagon() {

	}

	// get-ры
	int GetCapacity() {
		return capacity;
	}
	int GetTaken() {
		return taken;
	}
	WagonType GetType() {
		return type;
	}


	// set-ры
	void SetCapacity(int capacity) {
		this->capacity = capacity;
	}
	void SetTaken(int taken) {
		if (taken > capacity) {
			std::cout << "Error" << std::endl;
			return;
		}
		this->taken = taken;
	}
	void SetType(WagonType type) {
		this->type = type;
	}


	// методы
	void CreateWagon(int capacity, int taken, WagonType type) {
		if (taken > capacity) {
			std::cout << "Error" << std::endl;
			return;
		}
		this->capacity = capacity;
		this->taken = taken;
		this->type = type;
	}

	void CreateWagon(WagonType type) {
		if (type == WagonType::RESTAURANT) {
			capacity = 0;
			taken = 0;
			this->type = type;
		}
		else {
			std::cout << "Введите дополнительные занчения" << std::endl;
		}
	}

	int Get_Percent_Taken() {
		int percent_taken;
		percent_taken = (double(taken) / double(capacity)) * 100;
		std::cout << "Процент занятости вагона: " << percent_taken <<"%"<< std::endl;
		return percent_taken;
	}

	void Boarding(int cout_passenger) {
		if (cout_passenger < 0) {
			std::cout << "Error!";
			return;
		}
		if (taken+cout_passenger > capacity) {
			std::cout << "Error!";
			return;
		}
		taken += cout_passenger;
	}

	void Вisembarkation(int cout_passenger) {
		if (cout_passenger < 0) {
			std::cout << "Error!";
			return;
		}
		if (taken-cout_passenger < 0) {
			std::cout << "Error!";
			return;
		}
		taken -= cout_passenger;
	}

	void operator >> (Wagon& otherWagon) {
		int percent_this = Get_Percent_Taken();
		int percent_other = otherWagon.Get_Percent_Taken();

		int difference = percent_this - percent_other;

		int passenger_transfer = (difference/2 * capacity / 100);

		if (passenger_transfer > 0 && passenger_transfer <= taken) {
			taken -= passenger_transfer;
			otherWagon.taken += passenger_transfer;
			std::cout << "Перемещено " << passenger_transfer << " пассажиров из "
				<< WagonTypeToString(type) << " в " << WagonTypeToString(otherWagon.type) << " вагон" << std::endl;
		}
		else {
			std::cout << "Невозможно переместить пассажиров между этими вагонами." << std::endl;
		}
	}

	void Get_Info() {
		std::cout << "Вагон:" << WagonTypeToString(type) << "\nВместимость:" << capacity << "\nЗанято:" << taken << std::endl;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");

	Wagon first_wagon;
	Wagon second_wagon;
	

	first_wagon.CreateWagon(45, 15, WagonType::ECONOMY);
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();
	/*first_wagon.Boarding(20);
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();
	first_wagon.Вisembarkation(5);
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();*/

	second_wagon.CreateWagon(55, 25, WagonType::ECONOMY);
	second_wagon.Get_Info();
	second_wagon.Get_Percent_Taken();

	/*first_wagon >> second_wagon;
	std::cout << "DDDD" << std::endl;
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();
	second_wagon.Get_Info();
	second_wagon.Get_Percent_Taken();*/



	return 0;
}
