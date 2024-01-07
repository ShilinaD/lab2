#include "wagon.h"

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
}
