#include "wagon.h"
#include <iostream>

namespace Lab2 {
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
    }

	//конструкторы
    Wagon::Wagon() {}

	Wagon::Wagon(int capacity, int taken, WagonType type) {
		if (capacity < 0 || taken < 0 || taken > capacity) {
			throw std::invalid_argument("Некорректные данные.");
		}
		if (type == WagonType::RESTAURANT) {
			capacity = 0;
			taken = 0;
			this->type = type;
		}
		else {
			this->capacity = capacity;
			this->taken = taken;
			this->type = type;
		}
		
	}

	//гетеры
	int Wagon::GetCapacity() const {
		return capacity;
	}
	int Wagon::GetTaken() const {
		return taken;
	}
	WagonType  Wagon::GetType() const {
		return type;
	}

	//сетеры
	void Wagon::SetCapacity(int capacity) {
		if (capacity < 0) {
			throw std::invalid_argument("Некорректное значение вмещаемости. Значение должно быть неотрицательным.");
		}
		this->capacity = capacity;
	}
	void Wagon::SetTaken(int taken) {
		if (taken > capacity ||  taken < 0) {
			throw std::invalid_argument("Некорректное значение занятности.");
		}
		this->taken = taken;
	}
	void Wagon::SetType(WagonType type) {
		this->type = type;
	}

	//методы
	int Wagon::Get_Percent_Taken() {
		int percent_taken;
		if (type == WagonType::RESTAURANT) {
			throw std::invalid_argument("Процент зантности не может быть вычислен, так как билеты не продаются.");
		}
		if (capacity == 0) {
			throw std::invalid_argument("Процент зантности не может быть вычислен, так как вмещаемость вагона 0.");
		}
		percent_taken = static_cast<int>(static_cast<float>(taken) / static_cast<float> (capacity) * 100);
		return percent_taken;
	}

	void Wagon::Boarding(const int cout_passenger) {
		if (cout_passenger < 0 || taken + cout_passenger > capacity) {
			throw std::invalid_argument("Неккоректное количество пассажиров");
		}
		taken += cout_passenger;
	}

	void Wagon::Disembarkation(int cout_passenger) {
		if (cout_passenger < 0 || taken - cout_passenger < 0) {
			throw std::invalid_argument("Неккоректное количество пассажиров");
		}
		taken -= cout_passenger;
	}

	void Wagon::operator >> (Wagon& otherWagon) {	

		std::cout << "Процент занятости вагона 1: " << Get_Percent_Taken() << "%" << std::endl;
		std::cout << "Процент занятости вагона 2: " << otherWagon.Get_Percent_Taken() << "%" << std::endl;

		if (type == WagonType::RESTAURANT || otherWagon.type == WagonType::RESTAURANT) {
			throw std::runtime_error("Невозможно переместить пассажиров для вагона ресторана.");
		}

		int percent_this = Get_Percent_Taken();
		int percent_other = otherWagon.Get_Percent_Taken();

		int difference = percent_this - percent_other;

		int passenger_transfer = (difference / 2 * capacity / 100);

		if (passenger_transfer > 0 && passenger_transfer <= taken) {
			taken -= passenger_transfer;
			otherWagon.taken += passenger_transfer;
			std::cout << "Перемещено " << passenger_transfer << " пассажиров из "
				<< WagonTypeToString(type) << " в " << WagonTypeToString(otherWagon.type) << " вагон" << std::endl;
			std::cout << "Процент занятости вагона 1: " << Get_Percent_Taken() << "%" << std::endl;
			std::cout << "Процент занятости вагона 2: " << otherWagon.Get_Percent_Taken() << "%" << std::endl;

		}
		else {
			throw std::runtime_error("Невозможно переместить пассажиров между этими вагонами.");
		}
	}

	void Wagon::Get_Info()
	{
		std::cout << "=============================================" << std::endl;
		std::cout << "Тип:" << WagonTypeToString(type) << "\nВместимость:" << capacity << "\nЗанято:" << taken << std::endl;
		std::cout << "=============================================" << std::endl;
	}

}
