#include "../../src/service/gift_service.h"
#include <gtest/gtest.h>

TEST(GiftServiceTest, ShouldCalculatePriceOfGifts) {
    std::vector<std::string> gifts = {"Teddy bear", "Ornaments", "Novel"};
    Transaction transaction(gifts);
    GiftService service;
    double actualTransactionAmount = service.calculatePrice(transaction);

    double expectedTransactionAmount = 3570;
    ASSERT_DOUBLE_EQ(expectedTransactionAmount, actualTransactionAmount);
}

TEST(GiftServiceTest, ShouldRaiseExceptionForInvalidNumberOfGifts) {
    std::vector<std::string> gifts = {};
    Transaction transaction(gifts);
    GiftService service;

    ASSERT_THROW(service.calculatePrice(transaction), std::invalid_argument);
}