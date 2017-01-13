#include <iostream>
#include <string>
#include <limits>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/TypeTransform.h"

using namespace std;
using namespace cpp;

class TypeTransformTest : public ::testing::Test
{
public:
    static vector<int> IntVec;
    static vector<long> LongVec;
    static vector<float> FloatVec;
    static vector<double> DoubleVec;
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
vector<int> TypeTransformTest::IntVec = {numeric_limits<int>::min(),
                                      -100,
                                      -1,
                                      0,
                                      1,
                                      100,
                                      numeric_limits<int>::max()
                                     };
vector<long> TypeTransformTest::LongVec = {numeric_limits<long>::min(),
                                      -100,
                                      -1,
                                      0,
                                      1,
                                      100,
                                      numeric_limits<long>::max()
                                     };
vector<float> TypeTransformTest::FloatVec = {numeric_limits<float>::min(),
                                      -100.011,
                                      -100.911,
                                      -1.011,
                                      -1.311,
                                      0.011,
                                      0.311,
                                      1.011,
                                      100.011,
                                      100.811,
                                      numeric_limits<float>::max()
                                     };
vector<double> TypeTransformTest::DoubleVec = {numeric_limits<double>::min(),
                                      -100.011,
                                      -100.911,
                                      -1.011,
                                      -1.311,
                                      0.011,
                                      0.311,
                                      1.011,
                                      100.011,
                                      100.811,
                                      numeric_limits<double>::max()
                                     };

TEST_F(TypeTransformTest, IntToString)
{
    for (vector<int>::iterator it = IntVec.begin(); it != IntVec.end(); ++it) {
        EXPECT_EQ(boost::lexical_cast<string>(*it), TypeTransform::IntToString(*it));
    }
}

TEST_F(TypeTransformTest, StringToInt)
{
    for (vector<int>::iterator it = IntVec.begin(); it != IntVec.end(); ++it) {
        EXPECT_EQ(TypeTransform::StringToInt(boost::lexical_cast<string>(*it)), *it);
    }
}

TEST_F(TypeTransformTest, LongToString)
{
    for (vector<long>::iterator it = LongVec.begin(); it != LongVec.end(); ++it) {
        EXPECT_EQ(boost::lexical_cast<string>(*it), TypeTransform::LongToString(*it));
    }
}

TEST_F(TypeTransformTest, StringToLong)
{
    for (vector<long>::iterator it = LongVec.begin(); it != LongVec.end(); ++it) {
        EXPECT_EQ(TypeTransform::StringToLong(boost::lexical_cast<string>(*it)), *it);
    }
}

TEST_F(TypeTransformTest, FloatToString)
{
    for (vector<float>::iterator it = FloatVec.begin(); it != FloatVec.end(); ++it) {
        string boostStr = boost::lexical_cast<string>(*it);
        string transStr = TypeTransform::FloatToString(*it);
        EXPECT_EQ(boostStr.substr(boostStr.find("."), 3), transStr.substr(transStr.find("."), 3));
    }
}

TEST_F(TypeTransformTest, StringToFloat)
{
    for (vector<float>::iterator it = FloatVec.begin(); it != FloatVec.end(); ++it) {
        EXPECT_EQ(TypeTransform::StringToFloat(boost::lexical_cast<string>(*it)), *it);
    }
}

TEST_F(TypeTransformTest, DoubleToString)
{
    for (vector<double>::iterator it = DoubleVec.begin(); it != DoubleVec.end(); ++it) {
        string boostStr = boost::lexical_cast<string>(*it);
        string transStr = TypeTransform::DoubleToString(*it);
        EXPECT_EQ(boostStr.substr(boostStr.find("."), 3), transStr.substr(transStr.find("."), 3));
    }
}

TEST_F(TypeTransformTest, StringToDouble)
{
    for (vector<double>::iterator it = DoubleVec.begin(); it != DoubleVec.end(); ++it) {
        EXPECT_EQ(TypeTransform::StringToDouble(boost::lexical_cast<string>(*it)), *it);
    }
}
