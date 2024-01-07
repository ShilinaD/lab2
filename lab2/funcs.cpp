#include <iostream>
#include <string> 
#include "funcs.h"

// ���� int
int InputInt(void) {
    int value;
    while (true) {
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        else if (std::cin.eof()) {
            std::cout << "End of file (EOF) reached. The program is completed." << std::endl;
            exit(0);
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������ �����. ���������� ������� �������� ���� <int>." << std::endl;
        }
    }
    return value;
}


// ����� ������������ ����
void PrintMenu(void) {
    std::cout << "�������� �����: " << std::endl;
    std::cout << "1) ������ � ��������" << std::endl;
    std::cout << "2) ������ � �������" << std::endl;
    std::cout << "3) �����" << std::endl;
}

// ����� ���� ��� ������
void PrintMenuWagon(void) {
    std::cout << "�������� �����: " << std::endl;
    std::cout << "1) ������� �����" << std::endl;
    std::cout << "2) �������� ����� � �����" << std::endl;
    std::cout << "3) �������� ����� �� ������" << std::endl;
    std::cout << "4) ������ ������� ���������� ������" << std::endl;
    std::cout << "5) ����������� ����� �� ������ ������ � ������" << std::endl;
    std::cout << "6) ��������� � ������� ����" << std::endl;;
}

Lab2::WagonType GetTypeInput() {
    int type_input;
    std::cout << "������� ��� ������: \n 0 - ������� \n 1 - ������ \n 2 - ���� \n 3 - �������� " << std::endl;
    std::cin >> type_input;

    // ��������� ������������ ���������� ��������
    if (type_input < 0 || type_input > 3) {
        std::cout << "������������ ��� ������." << std::endl;
        return Lab2::WagonType::RESTAURANT;
    }

    // ����������� ��������� �������� � WagonType
    Lab2::WagonType type;
    switch (type_input) {
    case 0:
        return Lab2::WagonType::SITTING;
    case 1:
        return Lab2::WagonType::ECONOMY;
    case 2:
        return Lab2::WagonType::LUXURY;
    case 3:
        return Lab2::WagonType::RESTAURANT;
    default:
        std::cout << "������ �����." << std::endl;
        return Lab2::WagonType::RESTAURANT;
    }
}


 //������� ��� ����� �������� ������
void InputData(Lab2::Wagon& wagon) {
    Lab2::WagonType type = GetTypeInput();
    if (type == Lab2::WagonType::RESTAURANT) {
        wagon.CreateWagon(type);
    }
    else {
        std::cout << "������� ������������ ��������������� ������: " << std::endl;
        int capacity = InputInt();
        std::cout << "������� ���������� ������� ���� � ������: " << std::endl;
        int taken = InputInt();
        wagon.CreateWagon(capacity, taken, type);
    }
}


// ������� � ������ ��� ������ wagon
void WagonProgram(void) {
    Lab2::Wagon new_wagon;
    while (true) {
        PrintMenuWagon();
        int answer = InputInt();

        if (answer == 1) {

            InputData(new_wagon);

         // ����� ������
            
            new_wagon.Get_Info();
    
        }
        else if (answer == 2) {
            std::cout << "������� ���������� ���������� ��� �������: " << std::endl;
            int cout_passenger = InputInt();
            new_wagon.Boarding(cout_passenger);
            new_wagon.Get_Info();
        }
        else if (answer == 3) {
            std::cout << "������� ���������� ���������� ��� �������: " << std::endl;
            int cout_passenger = InputInt();
            new_wagon.�isembarkation(cout_passenger);
            new_wagon.Get_Info();
        }
        else if (answer == 4) {
            new_wagon.Get_Percent_Taken();
            new_wagon.Get_Info();
        }
       else if (answer == 6) {
            break;
        }
        else {
            std::cout << "�� ������ ������ ������  1, 2, 3, 4, 5 ��� 6 " << std::endl;
        }
    }
}