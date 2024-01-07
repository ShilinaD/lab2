#include <iostream>
#include <string> 
#include "funcs.h"

// ввод int
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
            std::cout << "Ошибка ввода. Пожалуйста введите значение типа <int>." << std::endl;
        }
    }
    return value;
}


// вывод изначального меню
void PrintMenu(void) {
    std::cout << "Выберите цифру: " << std::endl;
    std::cout << "1) Работа с вагонами" << std::endl;
    std::cout << "2) Работа с поездом" << std::endl;
    std::cout << "3) Выход" << std::endl;
}

// вывод меню для вагона
void PrintMenuWagon(void) {
    std::cout << "Выберите цифру: " << std::endl;
    std::cout << "1) создать вагон" << std::endl;
    std::cout << "2) посадить людей в вагон" << std::endl;
    std::cout << "3) высадить людей из вагона" << std::endl;
    std::cout << "4) узнать процент занятности вагона" << std::endl;
    std::cout << "5) переместить людей из одного вагона в другой" << std::endl;
    std::cout << "6) Вернуться в главное меню" << std::endl;;
}

Lab2::WagonType GetTypeInput() {
    int type_input;
    std::cout << "Введите тип вагона: \n 0 - Сидячий \n 1 - Эконом \n 2 - Люкс \n 3 - Ресторан " << std::endl;
    std::cin >> type_input;

    // Проверяем корректность введенного значения
    if (type_input < 0 || type_input > 3) {
        std::cout << "Некорректный тип вагона." << std::endl;
        return Lab2::WagonType::RESTAURANT;
    }

    // Преобразуем введенное значение в WagonType
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
        std::cout << "Ошибка ввода." << std::endl;
        return Lab2::WagonType::RESTAURANT;
    }
}


 //Функция для ввода значений вагона
void InputData(Lab2::Wagon& wagon) {
    Lab2::WagonType type = GetTypeInput();
    if (type == Lab2::WagonType::RESTAURANT) {
        wagon.CreateWagon(type);
    }
    else {
        std::cout << "Введите максимальную вместительность вагона: " << std::endl;
        int capacity = InputInt();
        std::cout << "Введите количество занятых мест в вагоне: " << std::endl;
        int taken = InputInt();
        wagon.CreateWagon(capacity, taken, type);
    }
}


// Функция с циклом для класса wagon
void WagonProgram(void) {
    Lab2::Wagon new_wagon;
    while (true) {
        PrintMenuWagon();
        int answer = InputInt();

        if (answer == 1) {

            InputData(new_wagon);

         // Вывод вагона
            
            new_wagon.Get_Info();
    
        }
        else if (answer == 2) {
            std::cout << "Введите количество пассажиров для пасадки: " << std::endl;
            int cout_passenger = InputInt();
            new_wagon.Boarding(cout_passenger);
            new_wagon.Get_Info();
        }
        else if (answer == 3) {
            std::cout << "Введите количество пассажиров для высадки: " << std::endl;
            int cout_passenger = InputInt();
            new_wagon.Вisembarkation(cout_passenger);
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
            std::cout << "Вы можете ввести только  1, 2, 3, 4, 5 или 6 " << std::endl;
        }
    }
}