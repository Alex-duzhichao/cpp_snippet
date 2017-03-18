#include <iostream>
#include <string>
#include <limits>
#include <boost/algorithm/string.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/CGI.h"

using std::string;
using cpp::CGI;
using namespace std;
using boost::to_upper;
using boost::to_upper_copy;

TEST(CGITEST, EncodeWithSpace)
{
    string str = "   ";
    string emptyEncodedStr = "%20%20%20";
    string encodeStr = CGI::Encode(str);
    ASSERT_EQ(to_upper_copy(encodeStr), to_upper_copy(emptyEncodedStr));
}

TEST(CGITEST, EncodeWithChinese)
{
    string str = "你好";
    string chineseEncodedStr = "%e4%bd%a0%e5%a5%bd";
    string encodeStr = CGI::Encode(str);
    ASSERT_EQ(to_upper_copy(encodeStr), to_upper_copy(chineseEncodedStr));
}

TEST(CGITEST, DecodeWithSpace)
{
    string str = "   ";
    string emptyEncodedStr = "%20%20%20";
    string decodeStr = CGI::Decode(emptyEncodedStr);
    ASSERT_EQ(to_upper_copy(str), to_upper_copy(decodeStr));
}

TEST(CGITEST, DecodeWithChinese)
{
    string str = "你好";
    string chineseEncodedStr = "%e4%bd%a0%e5%a5%bd";
    string decodeStr = CGI::Decode(str);
    ASSERT_EQ(to_upper_copy(str), to_upper_copy(decodeStr));
}
