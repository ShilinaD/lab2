#ifndef WAGON
#define WAGON

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
			percent_taken = (float(taken) / float(capacity)) * 100;
			return percent_taken;
		}

		void Boarding(const int cout_passenger) {
			if (cout_passenger < 0) {
				std::cout << "Error!";
				return;
			}
			if (taken + cout_passenger > capacity) {
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
			if (taken - cout_passenger < 0) {
				std::cout << "Error!";
				return;
			}
			taken -= cout_passenger;
		}

		void operator >> (Wagon& otherWagon) {
			std::cout << "Процент занятости вагона 1: " << Get_Percent_Taken() << "%" << std::endl;
			std::cout << "Процент занятости вагона 2: " << otherWagon.Get_Percent_Taken() << "%" << std::endl;

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
				std::cout << "Невозможно переместить пассажиров между этими вагонами." << std::endl;
			}
		}

		void Get_Info() 
		{
			std::cout << "=============================================" << std::endl;
			std::cout << "Тип:" << WagonTypeToString(type) << "\nВместимость:" << capacity << "\nЗанято:" << taken << std::endl;
			std::cout << "=============================================" << std::endl;
		}
		
		
	};
}
#endif WAGON