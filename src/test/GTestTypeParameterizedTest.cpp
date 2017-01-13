#include <iostream>
#include <list>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

template <typename T>
class FooTest : public ::testing::Test
{
public:
    typedef std::list<T> List;
    static T shared_;
    T value_;
};

template<typename T>
T FooTest<T>::shared_;
// typedef ::testing::Types<char, int, unsigned int> MyTypes;
// typedef ::testing::Types<char> MyTypes;
typedef ::testing::Types<int, unsigned int> MyTypes;
TYPED_TEST_CASE(FooTest, MyTypes);

TYPED_TEST(FooTest, DoesBlah)
{
    // Inside a test, refer to the special name TypeParam to get the type
    // parameter.  Since we are inside a derived class template, C++ requires
    // us to visit the members of FooTest via 'this'.
    TypeParam n = this->value_;

    // To visit static members of the fixture, add the 'TestFixture::'
    // prefix.
    // n += TestFixture::shared_;
    n += TestFixture::shared_;

    // To refer to typedefs in the fixture, add the 'typename TestFixture::'
    // prefix.  The 'typename' is required to satisfy the compiler.
    typename TestFixture::List values;
    values.push_back(n);
}

template <typename T>
class BarTest : public ::testing::Test
{
};
TYPED_TEST_CASE_P(BarTest);

TYPED_TEST_P(BarTest, DoesBlah)
{
    // Inside a test, refer to TypeParam to get the type parameter.
    TypeParam n = 0;
}

TYPED_TEST_P(BarTest, HasPropertyA)
{
}

REGISTER_TYPED_TEST_CASE_P(BarTest,
                           DoesBlah, HasPropertyA);

typedef ::testing::Types<char, int, unsigned int> BarTypes;
INSTANTIATE_TYPED_TEST_CASE_P(My, BarTest, BarTypes);

// INSTANTIATE_TYPED_TEST_CASE_P(My, BarTest, int);
