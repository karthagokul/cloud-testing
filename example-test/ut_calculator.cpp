/* Copyright (C) <2014>  Gokul Kartha <kartha.gokul@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**/

#include "gtest/gtest.h"
#include "calculator.h"

TEST(CalculatorTest, cublic)
{
    Calculator<int> c1;
    EXPECT_EQ(1000, c1.cubic(10));

    Calculator<float> c2;
    EXPECT_EQ(1000.00, c2.cubic(10.00));
}

TEST(CalculatorTest, multiply)
{
    Calculator<int> c1;
    EXPECT_EQ(200, c1.multiply(10,20));

    Calculator<float> c2;
    EXPECT_EQ(350.00, c2.multiply(10,35));
}

TEST(CalculatorTest, sum)
{
    Calculator<int> c1;
    EXPECT_EQ(30, c1.sum(10,20));

    Calculator<float> c2;
    EXPECT_EQ(45, c2.sum(10,35));
}

TEST(CalculatorTest, divide)
{
    Calculator<int> c1;
    EXPECT_EQ(2, c1.divide(20,10));

    Calculator<float> c2;
    EXPECT_EQ(5, c2.divide(35,7));
}
