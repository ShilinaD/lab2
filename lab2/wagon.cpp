#include "wagon.h"

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
}
