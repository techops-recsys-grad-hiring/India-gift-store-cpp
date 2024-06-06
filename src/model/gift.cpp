#include <string>

enum class GiftType {
    STANDARD,
    PREMIUM
};

class Gift {
private:
    GiftType type;
    std::string item;
    double priceInRupees;

public:
    Gift(GiftType type, std::string item, double priceInRupees) : type(type), item(item), priceInRupees(priceInRupees) {}

    std::string getItem() {
        return item;
    }

    double getPriceInRupees() {
        return priceInRupees;
    }

    std::string toString() {
        return std::string("Gift{") +
                       "type=" + std::to_string(static_cast<int>(type)) +
                       ", item='" + item + '\'' +
                       ", price=" + std::to_string(priceInRupees) +
                       '}';
    }
};