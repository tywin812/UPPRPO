﻿#include <gtest/gtest.h>
#include "./candle.h"

// 2.1 Тесты для body_contains
TEST(CandleTest, BodyContains_GreenCandle_InsideBody) {
    Candle candle(100, 110, 95, 105); // green: open < close
    EXPECT_TRUE(candle.body_contains(103));
}

TEST(CandleTest, BodyContains_GreenCandle_OutsideBody) {
    Candle candle(100, 110, 95, 105); 
    EXPECT_FALSE(candle.body_contains(97));  // ниже open
}

TEST(CandleTest, BodyContains_RedCandle_InsideBody) {
    Candle candle(105, 110, 95, 100); // red: open > close
    EXPECT_TRUE(candle.body_contains(103));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}