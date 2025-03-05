#include <gtest/gtest.h>
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

// 2.2 Тесты для contains
TEST(CandleTest, Contains_InsideFullRange) {
  Candle candle(100, 110, 95, 105);
  EXPECT_TRUE(candle.contains(96));
}

TEST(CandleTest, Contains_AtLowerBound) {
  Candle candle(100, 110, 95, 105);
  EXPECT_TRUE(candle.contains(95)); // low
}

TEST(CandleTest, Contains_OutsideRange) {
  Candle candle(100, 110, 95, 105);
  EXPECT_FALSE(candle.contains(111));
}

// 2.3 Тесты для full_size
TEST(CandleTest, FullSize_Normal) {
  Candle candle(100, 110, 95, 105);
  EXPECT_DOUBLE_EQ(candle.full_size(), 15.0);
}

TEST(CandleTest, FullSize_SinglePrice) {
  Candle candle(100, 100, 100, 100);
  EXPECT_DOUBLE_EQ(candle.full_size(), 0.0);
}

TEST(CandleTest, FullSize_Inverted) {
  Candle candle(100, 95, 95, 100);
  EXPECT_DOUBLE_EQ(candle.full_size(), 0.0);
}

// 2.4 Тесты для body_size
TEST(CandleTest, BodySize_Green) {
  Candle candle(100, 110, 95, 105);
  EXPECT_DOUBLE_EQ(candle.body_size(), 5.0);
}

TEST(CandleTest, BodySize_Red) {
  Candle candle(105, 110, 95, 100);
  EXPECT_DOUBLE_EQ(candle.body_size(), 5.0);
}

TEST(CandleTest, BodySize_Flat) {
  Candle candle(100, 110, 95, 100);
  EXPECT_DOUBLE_EQ(candle.body_size(), 0.0);
}

// 2.5 Тесты для is_red
TEST(CandleTest, IsRed_True) {
  Candle candle(105, 110, 95, 100);
  EXPECT_TRUE(candle.is_red());
}

TEST(CandleTest, IsRed_False) {
  Candle candle(100, 110, 95, 105);
  EXPECT_FALSE(candle.is_red());
}

TEST(CandleTest, IsRed_Flat) {
  Candle candle(100, 110, 95, 100);
  EXPECT_FALSE(candle.is_red());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}