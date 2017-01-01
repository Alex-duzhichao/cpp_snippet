#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/Singleton.h"

using namespace cpp;

class SingletonTest : public ::testing::Test
{
    public:
        class CTest
        {
            public:
                CTest(){};
        }; // class CTest

    protected:
        virtual void SetUp() {}
        virtual void TearDown() {}
}; // class SingletonTest

TEST_F(SingletonTest, NotReturnNull)
{
    EXPECT_TRUE(Singleton<CTest>::getInstance());
}

TEST_F(SingletonTest, IsGetSameInstance)
{
    EXPECT_EQ(Singleton<CTest>::getInstance(), Singleton<CTest>::getInstance());
}

TEST_F(SingletonTest, GetBySetInstance)
{
    CTest* p = new CTest;
    Singleton<CTest>::setInstance(p);
    EXPECT_EQ(Singleton<CTest>::getInstance(), p);
    EXPECT_EQ(Singleton<CTest>::getInstance(), p);
}


