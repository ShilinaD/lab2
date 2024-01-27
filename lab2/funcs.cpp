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
    std::cout << "5) Вернуться в главное меню" << std::endl;;
}

// вывод меню для поезда
void PrintMenuTrain(void) {
    std::cout << "Выберите цифру: " << std::endl;
    std::cout << "1) создать поезд с нескольками вагонами" << std::endl;
    std::cout << "2) создать поезд с одним вагоном" << std::endl;
    std::cout << "3) добавить новый вагон в поезд" << std::endl;
    std::cout << "4) получить вагон по его номеру" << std::endl;
    std::cout << "5) удалить вагон с заданным номером" << std::endl;
    std::cout << "6) посадить заданное число пассажиров в самый пустой вагон заданного класса" << std::endl;
    std::cout << "7) перераспределить пассажиров между вагонами, чтобы процент занятости всех вагонов был максимально близок; " << std::endl;
    std::cout << "8) минимизировать количество вагонов, освободив лишние путём пересадки пассажиров между вагонам " << std::endl;
    std::cout << "9) поместить вагон-ресторан оптимальным образом, чтобы до и после него в поезде было примерно одинаковое количество пассажиров" << std::endl;
    std::cout << "10) Вернуться в главное меню" << std::endl;
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
        wagon = Lab2::Wagon(0, 0, type);
        /*wagon = Lab2::Wagon(type);*/
    }
    else {
        std::cout << "Введите максимальную вместительность вагона: " << std::endl;
        int capacity = InputInt();
        std::cout << "Введите количество занятых мест в вагоне: " << std::endl;
        int taken = InputInt();
        wagon = Lab2::Wagon(capacity, taken, type);
        /*wagon.CreateWagon(capacity, taken, type);*/
    }
}


// Функция с циклом для класса wagon
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
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
            
            new_wagon.Get_Info();
    
        }
        else if (answer == 2) {
            std::cout << "Введите количество пассажиров для посадки: " << std::endl;
            int cout_passenger = InputInt();
            try {
                new_wagon.Boarding(cout_passenger);
            }
            catch (const std::exception& e) {
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
            new_wagon.Get_Info();
        }
        else if (answer == 3) {
            std::cout << "Введите количество пассажиров для высадки: " << std::endl;
            int cout_passenger = InputInt();
            try {
                new_wagon.Disembarkation(cout_passenger);
            }
            catch (const std::exception& e) {
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
            new_wagon.Get_Info();
        }
        else if (answer == 4) {
            try {
                new_wagon.Get_Percent_Taken();
                std::cout << "Процент занятости вагона 1: " << new_wagon.Get_Percent_Taken() << "%" << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
            new_wagon.Get_Info();
        }
       else if (answer == 5) {
            break;
        }
        else {
            std::cout << "Вы можете ввести только  1, 2, 3, 4 или 5 " << std::endl;
        }
    }
}

//функция к циклом для класса train
void TrainProgram(void) {
    Lab2::Wagon wagon_train;
    Lab2::Train train;

    std::vector<Lab2::Wagon> wagons_vector;
    while (true) {
        PrintMenuTrain();
        int answer = InputInt();
        if (answer == 1) {
            std::cout << "Введите количество вагонов: " << std::endl;
            int num_wagons = InputInt();
            try {
                for (int i = 0; i < num_wagons; i++) {
                    InputData(wagon_train);
                    wagons_vector.push_back(wagon_train);
                }
                train = Lab2::Train(wagons_vector);
            }
            catch (const std::exception& e) {
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
         
            train.Get_Info_Train();
        }
        else if (answer == 2) {
            try {
                InputData(wagon_train);
                train = Lab2::Train(wagon_train);
            }
            catch (const std::exception& e) {
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 3) {
            try {
                InputData(wagon_train);
                train += wagon_train;
            }
            catch (const std::exception& e) {
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 4) {
            std::cout << "Введите номер вагона: " << std::endl;
            int wagon_number = InputInt();
            try {
                Lab2::Wagon& find_wagon = train[wagon_number - 1];
                find_wagon.Get_Info();
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
        }
        else if (answer == 5) {
            std::cout << "Введите номер вагона: " << std::endl;
            int wagon_number = InputInt();
            try {
                train.RemoveWagon(wagon_number);
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 6) {
            Lab2::WagonType wagon_type;
            std::cout << "Введите количество пассажиров: " << std::endl;
            int num_passengers = InputInt();
            wagon_type = GetTypeInput();
            try {
                train.SeatPassengers(num_passengers, wagon_type);
            }
            catch (const std::exception& e) {
                std::cerr << "Произошло исключение: " << e.what() << std::endl;
            }
            train.Get_Info_Train();
        }
        else if (answer == 7) {
            std::cout << "До распределения: " << std::endl;
            train.Get_Info_Train();
            try {
                train.RedistributePassengers();
                std::cout << "После распределения: " << std::endl;
                train.Get_Info_Train();
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            
        }
        else if (answer == 8) {
            std::cout << "Информация о поезде до минимизации:" << std::endl;
            train.Get_Info_Train();
            try {
                train.MinimizeTrains();
                std::cout << "Информация о поезде после минимизации:" << std::endl;
                train.Get_Info_Train();
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            
        }
        else if (answer == 9) {
            std::cout << "Информация о поезде до перемещения:" << std::endl;
            train.Get_Info_Train();
            try {
                train.insertRestaurantWagon();

                std::cout << "Информация о поезде после перемещения:" << std::endl;
                train.Get_Info_Train();
            }
            catch (const std::exception& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            
        }
        else if (answer == 10) {
            break;
        }
        else {
            std::cout << "Вы можете ввести только  1, 2, 3, 4, 5 или 6 " << std::endl;
        }
    }
}