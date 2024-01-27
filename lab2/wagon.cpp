#include "wagon.h"
#include <iostream>

namespace Lab2 {
    std::string WagonTypeToString(WagonType type) {
        switch (type) {
        case WagonType::SITTING:
            return "�������";
        case WagonType::ECONOMY:
            return "������";
        case WagonType::LUXURY:
            return "����";
        case WagonType::RESTAURANT:
            return "��������";
        default:
            return "����������� ���";
        }
    }

	//������������
    Wagon::Wagon() {}

	Wagon::Wagon(int capacity, int taken, WagonType type) {
		if (capacity < 0 || taken < 0 || taken > capacity) {
			throw std::invalid_argument("������������ ������.");
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

	//������
	int Wagon::GetCapacity() const {
		return capacity;
	}
	int Wagon::GetTaken() const {
		return taken;
	}
	WagonType  Wagon::GetType() const {
		return type;
	}

	//������
	void Wagon::SetCapacity(int capacity) {
		if (capacity < 0) {
			throw std::invalid_argument("������������ �������� �����������. �������� ������ ���� ���������������.");
		}
		this->capacity = capacity;
	}
	void Wagon::SetTaken(int taken) {
		if (taken > capacity ||  taken < 0) {
			throw std::invalid_argument("������������ �������� ����������.");
		}
		this->taken = taken;
	}
	void Wagon::SetType(WagonType type) {
		this->type = type;
	}

	//������
	int Wagon::Get_Percent_Taken() {
		int percent_taken;
		if (type == WagonType::RESTAURANT) {
			throw std::invalid_argument("������� ��������� �� ����� ���� ��������, ��� ��� ������ �� ���������.");
		}
		if (capacity == 0) {
			throw std::invalid_argument("������� ��������� �� ����� ���� ��������, ��� ��� ����������� ������ 0.");
		}
		percent_taken = static_cast<int>(static_cast<float>(taken) / static_cast<float> (capacity) * 100);
		return percent_taken;
	}

	void Wagon::Boarding(const int cout_passenger) {
		if (cout_passenger < 0 || taken + cout_passenger > capacity) {
			throw std::invalid_argument("������������ ���������� ����������");
		}
		taken += cout_passenger;
	}

	void Wagon::Disembarkation(int cout_passenger) {
		if (cout_passenger < 0 || taken - cout_passenger < 0) {
			throw std::invalid_argument("������������ ���������� ����������");
		}
		taken -= cout_passenger;
	}

	void Wagon::operator >> (Wagon& otherWagon) {	

		std::cout << "������� ��������� ������ 1: " << Get_Percent_Taken() << "%" << std::endl;
		std::cout << "������� ��������� ������ 2: " << otherWagon.Get_Percent_Taken() << "%" << std::endl;

		if (type == WagonType::RESTAURANT || otherWagon.type == WagonType::RESTAURANT) {
			throw std::runtime_error("���������� ����������� ���������� ��� ������ ���������.");
		}

		int percent_this = Get_Percent_Taken();
		int percent_other = otherWagon.Get_Percent_Taken();

		int difference = percent_this - percent_other;

		int passenger_transfer = (difference / 2 * capacity / 100);

		if (passenger_transfer > 0 && passenger_transfer <= taken) {
			taken -= passenger_transfer;
			otherWagon.taken += passenger_transfer;
			std::cout << "���������� " << passenger_transfer << " ���������� �� "
				<< WagonTypeToString(type) << " � " << WagonTypeToString(otherWagon.type) << " �����" << std::endl;
			std::cout << "������� ��������� ������ 1: " << Get_Percent_Taken() << "%" << std::endl;
			std::cout << "������� ��������� ������ 2: " << otherWagon.Get_Percent_Taken() << "%" << std::endl;

		}
		else {
			throw std::runtime_error("���������� ����������� ���������� ����� ����� ��������.");
		}
	}

	void Wagon::Get_Info()
	{
		std::cout << "=============================================" << std::endl;
		std::cout << "���:" << WagonTypeToString(type) << "\n�����������:" << capacity << "\n������:" << taken << std::endl;
		std::cout << "=============================================" << std::endl;
	}

}
