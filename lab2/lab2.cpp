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
		this->taken = taken;
	}
	void SetType(WagonType type) {
		this->type = type;
	}


	// методы
	void CreateWagon(int capacity, int taken, WagonType type) {
		this->capacity = capacity;
		this->taken = taken;
		this->type = type;
	}

	void CreateWagon(WagonType type) {
		capacity = 0;
		taken = 0;
		this->type = type;
	}

	void Get_Percent_Taken() {
		int percent_taken;
		percent_taken = (double(taken) / double(capacity)) * 100;
		std::cout << "Процент занятости вагона: " << percent_taken <<"%"<< std::endl;
	}

	void Boarding(int cout_passenger) {
		// сделать отлов ошибки !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		taken += cout_passenger;
		if (taken > capacity) {
			std::cout << "Error!";
		}
	}

	void Вisembarkation(int cout_passenger) {
		// сделать отлов ошибки !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		taken -= cout_passenger;
		if (taken < 0) {
			std::cout << "Error!";
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
	

	first_wagon.CreateWagon(50, 10, WagonType::ECONOMY);
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();
	first_wagon.Boarding(20);
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();
	first_wagon.Вisembarkation(5);
	first_wagon.Get_Info();
	first_wagon.Get_Percent_Taken();

	second_wagon.CreateWagon(WagonType::RESTAURANT);
	second_wagon.Get_Info();
	



	return 0;
}
