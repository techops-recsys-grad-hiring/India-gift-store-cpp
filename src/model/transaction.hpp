#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

class Transaction {
private:
    std::vector<std::string> gifts;

public:
    Transaction(std::vector<std::string> gifts) : gifts(gifts) {}

    std::string toString() {
        std::string result = std::to_string(sizeof(gifts)) + " gifts: ";
        for (const auto& gift : gifts) {
            result += gift + ", ";
        }
        return result.substr(0, result.length() - 2);  // remove the last comma and space
    }
};

#endif // TRANSACTION_H