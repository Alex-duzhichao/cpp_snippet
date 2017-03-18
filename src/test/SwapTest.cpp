#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using std::string;

namespace cpp
{
    class Foo
    {
    public:
        Foo(const int n) : m_n(n) {}
        void swap(Foo &)
        {
        }
        int m_n;
    };

    inline void swap(Foo &lhs, Foo &rhs)
    {
        lhs.swap(rhs);
    }

    template<typename T>
    class Bar
    {
    public:
        Bar(const int n) : m_n(n) {}
        // template<typename T>
        void swap(Bar<T> &)
        {
        }
        int m_n;
    };

    template<typename T>
    inline void swap(Bar<T> &lhs, Bar<T> &rhs)
    {
        lhs.swap(rhs);
    }
} // namespace cpp

namespace std
{
    template<>
    void swap(cpp::Foo &lhs, cpp::Foo &rhs)
    {
        cpp::swap(lhs, rhs);
    }
} // namespace std

TEST(SwapTest, ClassTest)
{
    using std::swap;
    int n1 = 1, n2 = 2;
    swap(n1, n2);
    EXPECT_EQ(n1, 2);
    EXPECT_EQ(n2, 1);

    cpp::Foo f1(1), f2(2);
    swap(f1, f2);
    EXPECT_EQ(f1.m_n, 1);
    EXPECT_EQ(f2.m_n, 2);

    std::swap(f1, f2);
    EXPECT_EQ(f1.m_n, 1);
    EXPECT_EQ(f2.m_n, 2);
}

TEST(SwapTest, TemplateTest)
{
    using std::swap;
    int n1 = 1, n2 = 2;
    swap(n1, n2);
    EXPECT_EQ(n1, 2);
    EXPECT_EQ(n2, 1);

    cpp::Bar<int> f1(1), f2(2);
    swap(f1, f2);
    EXPECT_EQ(f1.m_n, 1);
    EXPECT_EQ(f2.m_n, 2);

    std::swap(f1, f2);
    EXPECT_EQ(f1.m_n, 2);
    EXPECT_EQ(f2.m_n, 1);
}
