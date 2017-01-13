#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/Singleton.h"
#include "src/ReverseGuard.h"

using namespace std;
using namespace cpp;

class SingletonTest : public ::testing::Test
{
public:
    class CTest
    {
    public:
        CTest() : m_nMem(0)
        {
            /* cout << "CTest ctor \n"; */
        };
        ~CTest()
        {
            /* cout << "CTest dtor \n";*/
        };
        int m_nMem;
    }; // class CTest

protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
}; // class SingletonTest

//////////////// NewPolicy //////////////////////////
TEST_F(SingletonTest, NewPolicyNotReturnNull)
{
    EXPECT_TRUE(Singleton<CTest>::getInstance());
}

TEST_F(SingletonTest, NewPolicyIsGetSameInstance)
{
    EXPECT_EQ(Singleton<CTest>::getInstance(),
              Singleton<CTest>::getInstance());
}

TEST_F(SingletonTest, NewPolicyDestroyInstance)
{
    Singleton<CTest>::destroyInstance();
    CTest *ptr_1 = Singleton<CTest>::getInstance();
    ptr_1->m_nMem += 1;
    EXPECT_EQ(ptr_1->m_nMem, 1);
    Singleton<CTest>::destroyInstance();
    CTest *ptr_2 = Singleton<CTest>::getInstance();
    EXPECT_EQ(ptr_2->m_nMem, 0);
}

TEST_F(SingletonTest, NewPolicyGetBySetInstance)
{
    Singleton<CTest>::destroyInstance();
    CTest *p = new CTest;
    Singleton<CTest>::setInstance(p);
    EXPECT_EQ(Singleton<CTest>::getInstance(), p);
}

//////////////// StaticPolicy //////////////////////////
TEST_F(SingletonTest, StaticPolicyNotReturnNull)
{
    EXPECT_NE((Singleton<CTest, StaticPolicy>::getInstance()), nullptr);
}

TEST_F(SingletonTest, StaticPolicyIsGetSameInstance)
{
    EXPECT_EQ((Singleton<CTest, StaticPolicy>::getInstance()),
              (Singleton<CTest, StaticPolicy>::getInstance()));
}

//////////////// NewAndDeletePolicy //////////////////////////
TEST_F(SingletonTest, NewAndDeletePolicyNotReturnNull)
{
    EXPECT_NE((Singleton<CTest, NewAndDeletePolicy>::getInstance()), nullptr);
}

TEST_F(SingletonTest, NewAndDeletePolicyIsGetSameInstance)
{
    EXPECT_EQ((Singleton<CTest, NewAndDeletePolicy>::getInstance()),
              (Singleton<CTest, NewAndDeletePolicy>::getInstance()));
}

TEST_F(SingletonTest, NewAndDeletePolicyGetBySetInstance)
{
    Singleton<CTest, NewAndDeletePolicy>::destroyInstance();
    CTest *p = new CTest;
    Singleton<CTest, NewAndDeletePolicy>::setInstance(p);
    EXPECT_EQ((Singleton<CTest, NewAndDeletePolicy>::getInstance()), p);
}
