#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/TypeTransform.h"

using namespace std;
using namespace cpp;

class TypeTransformTest : public ::testing::TestWithParam<int>
{
public:
    static void SetUpTestCase()
    {
    }

    static void TearDownTestCase()
    {
    }

protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
};

TEST_P(TypeTransformTest, IntToString)
{
    EXPECT_EQ(boost::lexical_cast<string>(GetParam()), TypeTransform::IntToString(GetParam()));
}

INSTANTIATE_TEST_CASE_P(InstantiationByRange,
                        TypeTransformTest,
                        ::testing::Range(1, 30));

#if 0
TEST_P(TypeTransformTest, StringToInt)
{
    EXPECT_EQ(n, TypeTransform::StringToInt(str));
}

TEST_F(TypeTransformTest, LongToString)
{
    EXPECT_EQ(str, TypeTransform::LongToString(l));
}

TEST_F(TypeTransformTest, StringToLong)
{
    EXPECT_EQ(l, TypeTransform::StringToLong(str));
}

TEST_F(TypeTransformTest, FloatToString)
{
    EXPECT_EQ(str, TypeTransform::FloatToString(f));
}

TEST_F(TypeTransformTest, StringToFloat)
{
    EXPECT_FLOAT_EQ(f, TypeTransform::StringToFloat(str));
}

TEST_F(TypeTransformTest, DoubleToString)
{
    EXPECT_EQ(str, TypeTransform::DoubleToString(d));
}

TEST_F(TypeTransformTest, StringToDouble)
{
    EXPECT_DOUBLE_EQ(d, TypeTransform::StringToDouble(str));
}
#endif
