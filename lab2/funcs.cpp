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
    std::cout << "5) ��������� � ������� ����" << std::endl;;
}

// ����� ���� ��� ������
void PrintMenuTrain(void) {
    std::cout << "�������� �����: " << std::endl;
    std::cout << "1) ������� ����� � ����������� ��������" << std::endl;
    std::cout << "2) ������� ����� � ����� �������" << std::endl;
    std::cout << "3) �������� ����� ����� � �����" << std::endl;
    std::cout << "4) �������� ����� �� ��� ������" << std::endl;
    std::cout << "5) ������� ����� � �������� �������" << std::endl;
    std::cout << "6) �������� �������� ����� ���������� � ����� ������ ����� ��������� ������" << std::endl;
    std::cout << "7) ���������������� ���������� ����� ��������, ����� ������� ��������� ���� ������� ��� ����������� ������; " << std::endl;
    std::cout << "8) �������������� ���������� �������, ��������� ������ ���� ��������� ���������� ����� ������� " << std::endl;
    std::cout << "9) ��������� �����-�������� ����������� �������, ����� �� � ����� ���� � ������ ���� �������� ���������� ���������� ����������" << std::endl;
    std::cout << "10) ��������� � ������� ����" << std::endl;
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
        wagon = Lab2::Wagon(0, 0, type);
        /*wagon = Lab2::Wagon(type);*/
    }
    else {
        std::cout << "������� ������������ ��������������� ������: " << std::endl;
        int capacity = InputInt();
        std::cout << "������� ���������� ������� ���� � ������: " << std::endl;
        int taken = InputInt();
        wagon = Lab2::Wagon(capacity, taken, type);
        /*wagon.CreateWagon(capacity, taken, type);*/
    }
}


// ������� � ������ ��� ������ wagon
void WagonProgram(void) {
    Lab2::Wagon new_wagon;
    while (true) {
        PrintMenuWagon();
        int answer = InputInt();

        if (answer == 1) {
            try {
                InputData(new_wagon);
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
            
            new_wagon.Get_Info();
    
        }
        else if (answer == 2) {
            std::cout << "������� ���������� ���������� ��� �������: " << std::endl;
            int cout_passenger = InputInt();
            try {
                new_wagon.Boarding(cout_passenger);
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
            new_wagon.Get_Info();
        }
        else if (answer == 3) {
            std::cout << "������� ���������� ���������� ��� �������: " << std::endl;
            int cout_passenger = InputInt();
            try {
                new_wagon.Disembarkation(cout_passenger);
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
            new_wagon.Get_Info();
        }
        else if (answer == 4) {
            try {
                new_wagon.Get_Percent_Taken();
                std::cout << "������� ��������� ������ 1: " << new_wagon.Get_Percent_Taken() << "%" << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
            new_wagon.Get_Info();
        }
       else if (answer == 5) {
            break;
        }
        else {
            std::cout << "�� ������ ������ ������  1, 2, 3, 4 ��� 5 " << std::endl;
        }
    }
}

//������� � ������ ��� ������ train
void TrainProgram(void) {
    Lab2::Wagon wagon_train;
    Lab2::Train train;

    std::vector<Lab2::Wagon> wagons_vector;
    while (true) {
        PrintMenuTrain();
        int answer = InputInt();
        if (answer == 1) {
            std::cout << "������� ���������� �������: " << std::endl;
            int num_wagons = InputInt();
            try {
                for (int i = 0; i < num_wagons; i++) {
                    InputData(wagon_train);
                    wagons_vector.push_back(wagon_train);
                }
                train = Lab2::Train(wagons_vector);
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
         
            train.Get_Info_Train();
        }
        else if (answer == 2) {
            try {
                InputData(wagon_train);
                train = Lab2::Train(wagon_train);
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 3) {
            try {
                InputData(wagon_train);
                train += wagon_train;
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 4) {
            std::cout << "������� ����� ������: " << std::endl;
            int wagon_number = InputInt();
            try {
                Lab2::Wagon& find_wagon = train[wagon_number - 1];
                find_wagon.Get_Info();
            }
            catch (const std::exception& e) {
                std::cout << "������: " << e.what() << std::endl;
            }
        }
        else if (answer == 5) {
            std::cout << "������� ����� ������: " << std::endl;
            int wagon_number = InputInt();
            try {
                train.RemoveWagon(wagon_number);
            }
            catch (const std::exception& e) {
                std::cout << "������: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 6) {
            Lab2::WagonType wagon_type;
            std::cout << "������� ���������� ����������: " << std::endl;
            int num_passengers = InputInt();
            wagon_type = GetTypeInput();
            try {
                train.SeatPassengers(num_passengers, wagon_type);
            }
            catch (const std::exception& e) {
                std::cerr << "��������� ����������: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 7) {
            std::cout << "�� �������������: " << std::endl;
            train.Get_Info_Train();
            try {
                train.RedistributePassengers();
                std::cout << "����� �������������: " << std::endl;
                train.Get_Info_Train();
            }
            catch (const std::exception& e) {
                std::cout << "������: " << e.what() << std::endl;
            }
            
        }
        else if (answer == 8) {
            std::cout << "���������� � ������ �� �����������:" << std::endl;
            train.Get_Info_Train();
            try {
                train.MinimizeTrains();
                std::cout << "���������� � ������ ����� �����������:" << std::endl;
                train.Get_Info_Train();
            }
            catch (const std::exception& e) {
                std::cout << "������: " << e.what() << std::endl;
            }
            
        }
        else if (answer == 9) {
            std::cout << "���������� � ������ �� �����������:" << std::endl;
            train.Get_Info_Train();
            try {
                train.insertRestaurantWagon();

                std::cout << "���������� � ������ ����� �����������:" << std::endl;
                train.Get_Info_Train();
            }
            catch (const std::exception& e) {
                std::cout << "������: " << e.what() << std::endl;
            }
            
        }
        else if (answer == 10) {
            break;
        }
        else {
            std::cout << "�� ������ ������ ������  1, 2, 3, 4, 5 ��� 6 " << std::endl;
        }
    }
}