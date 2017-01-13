#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/ReverseGuard.h"

using namespace cpp;

TEST(ReverseGuardTest, ReverseBool)
{
    bool bVal = false;
    {
        ReverseGuard<bool> guard(&bVal);
    }
    EXPECT_TRUE(bVal);

    {
        ReverseGuard<bool> guard(&bVal);
    }
    EXPECT_FALSE(bVal);
}
