#include <iostream>
#include <string>
#include <limits>
#include <boost/algorithm/string.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/Function.h"

using std::string;
using namespace std;
using boost::to_upper;
using boost::to_upper_copy;

TEST(FunctionTest, IsPowerTest)
{
    EXPECT_TRUE(isPower(0));
    EXPECT_TRUE(isPower(1));
    EXPECT_TRUE(isPower(2));
    EXPECT_TRUE(isPower(4));
    EXPECT_TRUE(isPower(8));
    EXPECT_FALSE(isPower(3));
    EXPECT_FALSE(isPower(5));
}

TEST(FunctionTest, GetNextPowerTest)
{
    // EXPECT_EQ(getNextPower(1), 2);
    // EXPECT_EQ(getNextPower(2), 2);
    // EXPECT_EQ(getNextPower(3), 4);
    // EXPECT_EQ(getNextPower(4), 4);
    // EXPECT_EQ(getNextPower(5), 8);
    // EXPECT_EQ(getNextPower(6), 8);
    // EXPECT_EQ(getNextPower(8), 8);
}
