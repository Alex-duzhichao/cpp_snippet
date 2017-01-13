/**
 * @File : gtestColorPrint.h
 * @Brief : 使用 gtest 的输出 http://stackoverflow.com/a/29155677/4942921
 * @Author : Name:AlexDu Email:duzhichaomail@gmail.com
 * @Version : 1.0.0
 * @Date : 2017-01-02
 */

#ifndef CPP_SNIPPET_SRC_GTESTCOLORPRINT_H_
#define CPP_SNIPPET_SRC_GTESTCOLORPRINT_H_
#include <iostream>
using namespace std;
namespace testing
{
    namespace internal
    {
        enum GTestColor {
            COLOR_DEFAULT,
            COLOR_RED,
            COLOR_GREEN,
            COLOR_YELLOW
        };

        extern void ColoredPrintf(
            GTestColor color,
            const char *fmt,
            ...
        );
    }
}

// ("[" + string(::testing::UnitTest::GetInstance()->current_test_info()->test_case_name()) + "] ").c_str());
#define GPRINTF(...)  \
    do { \
        testing::internal::ColoredPrintf(testing::internal::COLOR_YELLOW, "[  output  ] "); \
        testing::internal::ColoredPrintf(testing::internal::COLOR_YELLOW, __VA_ARGS__); \
    } while(0)

// C++ stream interface
class TestCout : public std::stringstream
{
public:
    ~TestCout()
    {
        GPRINTF("%s", str().c_str());
    }
};

//http://stackoverflow.com/questions/41425325/cout-a-stringstream-but-print-a-pointer?answertab=oldest#41425959
#define GCOUT TestCout tc;tc

#endif /* CPP_SNIPPET_SRC_GTESTCOLORPRINT_H_ */
