#include <time.h>
#include <string>
#include <sstream>
#include <boost/algorithm/string/join.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GTestColorPrint.h"
#include "src/RandomGenerator.h"

using namespace std;
using namespace cpp;
class RandomGeneratorTest: public ::testing::Test
{
public:
    void printVec(const vector<int> &randomVec)
    {
        for (vector<int>::const_iterator it = randomVec.begin();
                it != randomVec.end(); ++it) {
            GCOUT << *it << endl;
        }
    }

    static void SetUpTestCase()
    {
        // GCOUT << "SetUpTestCase" << std::endl;
    }

    static void TearDownTestCase()
    {
        // GCOUT << "TearDownTestCase" << std::endl;
    }

protected:
    virtual void SetUp()
    {
        RandomGenerator<int>::setSeed(static_cast<unsigned int>(time(0)));
    }
    virtual void TearDown() {}
};

TEST_F(RandomGeneratorTest, CheckResultSize)
{
    int size = 100;
    EXPECT_EQ(size, RandomGenerator<int>::getRandom(size).size());
}

// TODO : 测试更多的case
TEST_F(RandomGeneratorTest, PrintResult)
{
    int size = 10;
    vector<int> randomVec = RandomGenerator<int>::getRandom(size);
    // printVec(randomVec);
    // string joined = boost::algorithm::join(randomVec, ", ");
    // GCOUT << joined << endl;
}

TEST_F(RandomGeneratorTest, CheckRandomRange)
{
    int size = 10;
    int min = -100;
    int max = 100;
    vector<int> randomVec = RandomGenerator<int>::getRandom(size, min, max);

    for (vector<int>::const_iterator it = randomVec.begin();
            it != randomVec.end(); ++it) {
        EXPECT_LE(min, *it);
        EXPECT_GT(max, *it);
    }

    // GCOUT << "===== CheckRandomRange =====" << endl;
    // printVec(randomVec);
    // string joined = boost::algorithm::join(randomVec, ", ");
    // GCOUT << joined << endl;
}
