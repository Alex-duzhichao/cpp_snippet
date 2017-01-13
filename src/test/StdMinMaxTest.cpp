#ifndef CPP_SNIPPET_SRC_TEST_STDMINMAX_TEST_CPP_
#define CPP_SNIPPET_SRC_TEST_STDMINMAX_TEST_CPP_

#include <algorithm>
#include <boost/operators.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GTestColorPrint.h"

TEST(StdMinMaxTest, MinOfDifferentInt)
{
    int lesser = 0;
    int bigger = 1;
    EXPECT_EQ(lesser, std::min(lesser, bigger));
    EXPECT_EQ(lesser, std::min(bigger, lesser));
    EXPECT_GT(bigger, std::min(lesser, bigger));
    EXPECT_GT(bigger, std::min(bigger, lesser));
}

TEST(StdMinMaxTest, MinOfEqualInt)
{
    int lesser = 0;
    int bigger = 0;
    EXPECT_EQ(lesser, std::min(lesser, bigger));
    EXPECT_EQ(lesser, std::min(bigger, lesser));
    EXPECT_EQ(bigger, std::min(lesser, bigger));
    EXPECT_EQ(bigger, std::min(bigger, lesser));
}

TEST(StdMinMaxTest, MaxOfDifferentInt)
{
    int lesser = 0;
    int bigger = 1;
    EXPECT_EQ(bigger, std::max(lesser, bigger));
    EXPECT_EQ(bigger, std::max(bigger, lesser));
    EXPECT_LT(lesser, std::max(lesser, bigger));
    EXPECT_LT(lesser, std::max(bigger, lesser));
}

TEST(StdMinMaxTest, MaxOfEqualInt)
{
    int lesser = 0;
    int bigger = 0;
    EXPECT_EQ(lesser, std::max(lesser, bigger));
    EXPECT_EQ(lesser, std::max(bigger, lesser));
    EXPECT_EQ(bigger, std::max(lesser, bigger));
    EXPECT_EQ(bigger, std::max(bigger, lesser));
}

class StdMinMaxTestClass : public boost::less_than_comparable<StdMinMaxTestClass>,
    public boost::equality_comparable<StdMinMaxTestClass>
{
public:
    friend bool operator< (const StdMinMaxTestClass &lhs, const StdMinMaxTestClass &rhs);
    friend bool operator== (const StdMinMaxTestClass &lhs, const StdMinMaxTestClass &rhs);
    // friend bool operator> (const StdMinMaxTestClass& lhs, const StdMinMaxTestClass& rhs);
    explicit StdMinMaxTestClass(const int num) : m_nMem(num)
    {}

private:
    int m_nMem;
}; // class StdMinMaxTestClass

bool operator< (const StdMinMaxTestClass &lhs, const StdMinMaxTestClass &rhs)
{
    return (lhs.m_nMem < rhs.m_nMem);
}

bool operator== (const StdMinMaxTestClass &lhs, const StdMinMaxTestClass &rhs)
{
    return !(lhs < rhs) && !(rhs < lhs);
}

// bool operator> (const StdMinMaxTestClass& lhs, const StdMinMaxTestClass& rhs)
// {
// return (rhs < lhs) && !(rhs == lhs);
// }

TEST(StdMinMaxTest, MinOfDifferentUserDefineClass)
{
    StdMinMaxTestClass lesser(0);
    StdMinMaxTestClass bigger(1);
    EXPECT_EQ(lesser, std::min(lesser, bigger));
    EXPECT_EQ(lesser, std::min(bigger, lesser));
    EXPECT_GT(bigger, std::min(lesser, bigger));
    EXPECT_GT(bigger, std::min(bigger, lesser));
}

TEST(StdMinMaxTest, MinOfEqualUserDefineClass)
{
    StdMinMaxTestClass lesser(0);
    StdMinMaxTestClass bigger(0);
    EXPECT_EQ(lesser, std::min(lesser, bigger));
    EXPECT_EQ(lesser, std::min(bigger, lesser));
    EXPECT_EQ(bigger, std::min(lesser, bigger));
    EXPECT_EQ(bigger, std::min(bigger, lesser));
}

TEST(StdMinMaxTest, MaxOfDifferentUserDefineClass)
{
    StdMinMaxTestClass lesser(0);
    StdMinMaxTestClass bigger(1);
    EXPECT_EQ(bigger, std::max(lesser, bigger));
    EXPECT_EQ(bigger, std::max(bigger, lesser));
    EXPECT_LT(lesser, std::max(lesser, bigger));
    EXPECT_LT(lesser, std::max(bigger, lesser));
}

TEST(StdMinMaxTest, MaxOfEqualUserDefineClass)
{
    StdMinMaxTestClass lesser(0);
    StdMinMaxTestClass bigger(0);
    EXPECT_EQ(lesser, std::max(lesser, bigger));
    EXPECT_EQ(lesser, std::max(bigger, lesser));
    EXPECT_EQ(bigger, std::max(lesser, bigger));
    EXPECT_EQ(bigger, std::max(bigger, lesser));
}


#endif /* CPP_SNIPPET_SRC_TEST_STDMINMAX_TEST_CPP_ */
