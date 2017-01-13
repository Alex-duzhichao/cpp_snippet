#include <gtest/gtest.h>
#include <iostream>

using namespace std;
class GlobalEnviroment : public ::testing::Environment
{
public:
    virtual ~GlobalEnviroment()
    {
    }

    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
}; // class GlobalEnviroment : public ::testing::Environment


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(new GlobalEnviroment);
    return RUN_ALL_TESTS();
}
