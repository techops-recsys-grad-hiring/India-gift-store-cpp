#ifndef GIFTSERVICE_H
#define GIFTSERVICE_H

#include <vector>
#include "../model/gift.cpp"
#include "../model/transaction.hpp"

class GiftService {
public:
    static std::vector<Gift> giftStoreItems;

    static void initialize() {
        giftStoreItems.push_back(Gift(GiftType::STANDARD, "Teddy bear", 600));
        giftStoreItems.push_back(Gift(GiftType::STANDARD, "Chocolates", 1000));
        giftStoreItems.push_back(Gift(GiftType::STANDARD, "Novel", 800));
        giftStoreItems.push_back(Gift(GiftType::PREMIUM, "Photo frame", 1500));
        giftStoreItems.push_back(Gift(GiftType::PREMIUM, "Ornaments", 2000));
        giftStoreItems.push_back(Gift(GiftType::PREMIUM, "Personalized Caricature", 1800));
    }

    double calculatePrice(Transaction transaction) {
        //TODO: logic to calculate the price of items purchased
        return 0;
    }
};

std::vector<Gift> GiftService::giftStoreItems = {};

static const int GST_PERCENTAGE = 5;

#endif //GIFTSERVICE_H