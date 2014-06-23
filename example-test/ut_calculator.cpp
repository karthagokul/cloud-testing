#include "gtest/gtest.h"
#include "calculator.h"

TEST(CalculatorTest, cubictest)
{
    Calculator c;
    EXPECT_EQ(1000, c.cubic(10));
}
