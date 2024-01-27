// если передаю кол-во людей занятность и тип ресторан проверка на ресторан
#ifndef WAGON
#define WAGON
#pragma once
#include <iostream>

namespace Lab2 {
	enum class WagonType {
		SITTING,
		ECONOMY,
		LUXURY,
		RESTAURANT
	};

	std::string WagonTypeToString(WagonType type);

	class Wagon {
	private:
		int capacity = 0;
		int taken = 0;
		WagonType type = WagonType::SITTING;

	public:
		// конструкторы
		Wagon();
		Wagon(int capacity, int taken, WagonType type);
		/*Wagon(WagonType type);*/


		// get-ры
		int GetCapacity() const;
		int GetTaken() const;
		WagonType GetType() const;


		// set-ры
		void SetCapacity(int capacity);
		void SetTaken(int taken);
		void SetType(WagonType type);


		// методы
		int Get_Percent_Taken();
		void Boarding(const int cout_passenger);
		void Disembarkation(int cout_passenger);
		void operator >> (Wagon& otherWagon);
		void Get_Info();
		
	};
}
#endif WAGON