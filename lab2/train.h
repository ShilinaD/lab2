#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include "wagon.h"


namespace Lab2 {
	class Train {
	private:
		std::vector<Wagon> wagons; // ������ ������� � ������
	public:

		// ������������
		Train();
		Train(const std::vector<Wagon>& wagons_vector);
		Train(const Wagon& wagon);

		~Train(); 

		//������

		Train& operator+=(const Wagon& new_wagon);

		Wagon& operator[](int num_wagon);

		void RemoveWagon(int num_wagon);

		void SeatPassengers(int num_passengers, WagonType wagon_type);

		void RedistributePassengers();

		void MinimizeTrains();

		void insertRestaurantWagon();


		void Get_Info_Train()
		{
			std::cout << "=============================================" << std::endl;
			std::cout << "����� � : " << wagons.size() << " ��������" << std::endl;
			std::cout << "=============================================" << std::endl;
			for (int j = 0; j < wagons.size(); j++) {
				wagons[j].Get_Info();
			}
		}
	};
}