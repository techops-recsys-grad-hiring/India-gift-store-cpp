#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "model/transaction.hpp"
#include "service/gift_service.h"

// Function to split a string by a delimiter
std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to trim leading and trailing spaces from a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {
    std::cout << "Welcome to Gift Store!" << std::endl;
    std::cout << "Enter number of gifts: ";
    int numberOfGifts;
    std::cin >> numberOfGifts;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore newline
    std::cout << "Enter gift names: ";
    std::string gifts_input;
    std::getline(std::cin, gifts_input);
    std::vector<std::string> gifts = split(gifts_input, ',');
    for (std::string& gift : gifts) {
        gift = trim(gift);
    }
    if (gifts.size() != numberOfGifts) {
        std::cout << "Please enter correct number of gifts!\n";
        return 0;
    }

    Transaction transaction(gifts);

    GiftService giftService;
    double transactionAmount = giftService.calculatePrice(transaction);
    std::cout << "Thanks for Transaction of amount: ₹ " << transactionAmount << std::endl;
    return 0;
}