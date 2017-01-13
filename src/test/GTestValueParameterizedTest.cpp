#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

// template <typename T>
class FooTest : public ::testing::TestWithParam<int>
{
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from class
    // TestWithParam<T>.
};

TEST_P(FooTest, DoesBlah)
{
    // Inside a test, access the test parameter with the GetParam() method
    // of the TestWithParam<T> class:
    // EXPECT_TRUE(foo.Blah(GetParam()));
    cout << GetParam() << endl;
}

INSTANTIATE_TEST_CASE_P(InstantiationByValues,
                        FooTest,
                        ::testing::Values(1, 2, 3));

INSTANTIATE_TEST_CASE_P(InstantiationByRange,
                        FooTest,
                        ::testing::Range(1, 3));

vector<int> vec = {1, 2, 3, 4};
INSTANTIATE_TEST_CASE_P(InstantiationByVector,
                        FooTest,
                        ::testing::ValuesIn(vec.begin(), vec.end()));

int arr[4] = {1, 2, 3, 4};
INSTANTIATE_TEST_CASE_P(InstantiationByArray,
                        FooTest,
                        ::testing::ValuesIn(arr));


