#include "funcs.h"
#include "train.h"
#include "wagon.h"
#include <cstddef>
namespace Lab2 {
	Train::Train(){}

	/*Train::Train(const std::vector<Wagon>& wagons_vector) : wagons(wagons_vector){}*/

	Train::Train(const std::vector<Wagon>& wagons_vector) {
		// Проверка, что вагон ресторана добавлен только один раз
		int restaurantCount = 0;
		for (const Wagon& wagon : wagons_vector) {
			if (wagon.GetType() == WagonType::RESTAURANT) {
				restaurantCount++;
			}
		}

		if (restaurantCount > 1) {
			throw std::invalid_argument("Поезд должен содержать только один вагон ресторана.");
		}

		wagons = wagons_vector;
	}

	Train::Train(const Wagon& wagon) {
		wagons.push_back(wagon);
	}

	Train::~Train(){}

	Train&Train::operator+=(const Wagon& new_wagon) {
		if (new_wagon.GetType() == WagonType::RESTAURANT) {
			// Проверка, что в поезде нет вагона ресторана
			auto restaurantWagonIter = std::find_if(wagons.begin(), wagons.end(), [](const Wagon& wagon) {
				return wagon.GetType() == WagonType::RESTAURANT;
				});

			if (restaurantWagonIter != wagons.end()) {
				std::cout << "В поезде уже есть вагон ресторана. Нельзя добавить еще один." << std::endl;
				return *this;
			}
		}

		// Если проверки прошли успешно, добавляем вагон в поезд
		wagons.push_back(new_wagon);
		return *this;
		
	}

	Wagon& Train::operator[](int num_wagon) {
		if (num_wagon >= 0 && num_wagon < wagons.size()) {
			return wagons[num_wagon];
		}
		else {
			throw std::out_of_range("Неккоректный номер вагона");
		}
	}

	void Train::RemoveWagon(int num_wagon) {
		if (num_wagon >= 1 && num_wagon <= wagons.size()) {
			wagons.erase(wagons.begin() + num_wagon - 1);
			std::cout << "Вагон с номером " << num_wagon << " был удален" << std::endl;
		}
		else {
			throw std::out_of_range("Не существует такой вагон, удаление не возможно.");
		}
	}

	void Train::SeatPassengers(int num_passengers, WagonType wagon_type) {
		if (num_passengers <= 0) {
			throw std::invalid_argument("Неккоректное количество пассажиров");
		}

		if (wagon_type == WagonType::RESTAURANT) {
			throw std::invalid_argument("Пассажиров в ресторан посадить нельзя");
		}

		std::vector<Wagon*> wagons_type;
		for (Wagon& wagon : wagons) {
			if (wagon.GetType() == wagon_type) {
				wagons_type.push_back(&wagon);
			}
		}
		if (wagons_type.empty()) {
			throw std::invalid_argument("Вагона такого класса нет");
		}
		Wagon* most_free = wagons_type[0];
		for (size_t i = 1; i < wagons_type.size(); i++) {
			if (wagons_type[i]->Get_Percent_Taken() < most_free->Get_Percent_Taken()) {
				most_free = wagons_type[i];
			}
		}
		most_free->Boarding(num_passengers);
		std::cout << "Пассажиры посажены в вагон типа" << static_cast<int>(wagon_type) << std::endl;
	}

	void Train::RedistributePassengers() {
		if (wagons.empty()) {
			throw std::runtime_error("Нет вагонов с пассажирами для перераспределения");
		}

		std::vector<std::pair<Wagon*, int>> wagon_percentages;
		for (Wagon& wagon : wagons) {
			if (wagon.GetType() != WagonType::RESTAURANT && wagon.Get_Percent_Taken() > 0 && wagon.Get_Percent_Taken() < 100) {
				int percent_taken = wagon.Get_Percent_Taken();
				wagon_percentages.push_back({ &wagon, percent_taken });
			}
		}

		if (wagon_percentages.size() < 2) {
			throw std::runtime_error("Недостаточно вагонов для перераспределения пассажиров");
		}

		// Сортировка вагонов по проценту занятости (в порядке убывания)
		std::sort(wagon_percentages.begin(), wagon_percentages.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
			});

		// Итерирование по вагонам и перераспределение пассажиров
		for (size_t i = 0; i < wagon_percentages.size(); ++i) {
			for (size_t j = i + 1; j < wagon_percentages.size(); ++j) {
				Wagon* source_wagon = wagon_percentages[i].first;
				Wagon* target_wagon = wagon_percentages[j].first;

				
				WagonType source_type = source_wagon->GetType();
				WagonType target_type = target_wagon->GetType();


				if ((source_type == WagonType::SITTING) ||
					(source_type == WagonType::ECONOMY && target_type != WagonType::SITTING) ||
					(source_type == WagonType::LUXURY && target_type == WagonType::LUXURY)) {

					if (source_wagon->GetTaken() > target_wagon->GetTaken()) {
						(*source_wagon) >> (*target_wagon);
					}
					else if (source_wagon->GetTaken() < target_wagon->GetTaken()) {
						(*target_wagon) >> (*source_wagon);
					}

					// Обновление процентов занятости после перемещения
					wagon_percentages[i].second = source_wagon->Get_Percent_Taken();
					wagon_percentages[j].second = target_wagon->Get_Percent_Taken();
				}
			}
		}
	}
	

	void Train::MinimizeTrains() {
		std::vector<std::pair<Wagon*, int>> wagon_percentages;

		auto validateWagon = [&](Wagon& wagon) {
			if (wagon.GetCapacity() < 0) {
				throw std::invalid_argument("Отрицательная вместимость вагона.");
			}

			if (wagon.GetTaken() < 0) {
				throw std::invalid_argument("Отрицательное количество занятых мест в вагоне.");
			}

			int percent_taken = wagon.Get_Percent_Taken();
			if (percent_taken < 0 || percent_taken > 100) {
				throw std::invalid_argument("Процент занятости вагона должен быть в диапазоне [0, 100].");
			}
			};

		for (Wagon& wagon : wagons) {
			if (wagon.GetType() != WagonType::RESTAURANT && wagon.Get_Percent_Taken() > 0 && wagon.Get_Percent_Taken() < 100) {
				int percent_taken = wagon.Get_Percent_Taken();
				wagon_percentages.push_back({ &wagon, percent_taken });
			}
		}

		std::sort(wagon_percentages.begin(), wagon_percentages.end(), [](const auto& a, const auto& b) {
			return a.second > b.second;
			});

		std::vector<Wagon> new_wagons;

		for (size_t i = 0; i < wagons.size(); ++i) {
			Wagon& current_wagon = wagons[i];

			if (current_wagon.GetType() == WagonType::RESTAURANT) {
				new_wagons.push_back(current_wagon);
				continue;
			}

			// Проходим по оставшимся вагонам для поиска места, куда можно переместить текущий вагон
			for (size_t j = i + 1; j < wagons.size(); ++j) {
				Wagon& target_wagon = wagons[j];

				if (target_wagon.GetType() != WagonType::RESTAURANT && current_wagon.Get_Percent_Taken() > 0) {
					int passenger_transfer = std::min(current_wagon.GetTaken(), target_wagon.GetCapacity() - target_wagon.GetTaken());
					if (passenger_transfer > 0) {
						current_wagon.SetTaken(current_wagon.GetTaken() - passenger_transfer);
						target_wagon.SetTaken(target_wagon.GetTaken() + passenger_transfer);
					}
				}
			}

			if (current_wagon.Get_Percent_Taken() > 0) {
				new_wagons.push_back(current_wagon);
			}
		}

		// Заменяем текущий вектор вагонов новым
		wagons = new_wagons;
	}
	

	void Train::insertRestaurantWagon() {

		std::vector<Wagon> temp_wagons;

		// Создаем временный вектор без вагонов-ресторанов и вагонов класса "люкс"
		for (const auto& wagon : wagons) {
			if (wagon.GetType() != WagonType::RESTAURANT && wagon.GetType() != WagonType::LUXURY) {
				temp_wagons.push_back(wagon);
			}
		}

		if (temp_wagons.size() < 2) {
			throw std::runtime_error("Недостаточно вагонов для реализации метода.");
		}

		// Сортируем временный вектор по количеству пассажиров
		std::sort(temp_wagons.begin(), temp_wagons.end(), [](const Wagon& a, const Wagon& b) {
			return a.GetTaken() < b.GetTaken();
		});

		// Находим индекс для вставки вагона-ресторана
		size_t insert_index = 0;
		int passengers_left = 0;
		int passengers_right = 0;

		for (size_t i = 0; i < temp_wagons.size(); ++i) {
			if (i < temp_wagons.size() / 2) {
				passengers_left += temp_wagons[i].GetTaken();
			}
			else {
				passengers_right += temp_wagons[i].GetTaken();
			}
		}

		if (passengers_left > passengers_right) {
			insert_index = temp_wagons.size() / 2;
		}
		else {
			insert_index = temp_wagons.size() / 2 + 1;
		}

		auto wagon_iterator = std::find_if(wagons.begin(), wagons.end(),
			[](const Wagon& wagon) { return wagon.GetType() == WagonType::RESTAURANT; });

		if (wagon_iterator != wagons.end()) {
			// Удаляем вагон из его текущего места
			wagons.erase(wagon_iterator);

			// Вставляем вагон-ресторан в поезд
			wagons.insert(wagons.begin() + insert_index, Wagon(0, 0, WagonType::RESTAURANT));
		}
		else {
			throw std::runtime_error("Вагон ресторан не был найден.");
		}
	}
}
