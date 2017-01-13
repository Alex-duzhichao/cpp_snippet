/**
 * @File : randomGenerator.h
 * @Brief : Generate random
 * @Author : Name:AlexDu Email:duzhichaomail@gmail.com
 * @Version : 1.0.0
 * @Date : 2017-01-02
 */
#ifndef CPP_SNIPPET_SRC_RANDOMGENERATOR_H_
#define CPP_SNIPPET_SRC_RANDOMGENERATOR_H_

#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <limits>

namespace cpp
{
    using std::vector;
    using std::numeric_limits;
// TODO : 特化更多类型
    template<typename T>
    class RandomGenerator
    {
    public:
        static void setSeed(const unsigned int seed);

        /**
         * @Brief : getRandom 返回 size 个 [lowerBound, upperBound)
                              中的随机数 (upperBound > lowerBound)
         *
         * @Param : size
         * @Param : lowerBound
         * @Param : upperBound
         *
         * @Return :
         */
        static vector<T> getRandom(const unsigned int size,
                                   /* const int lowerBound = numeric_limits<int>::min(),*/
                                   const int lowerBound = 0,
                                   const int upperBound = numeric_limits<int>::max());
    }; // class RandomGenerator

    template<typename T>
    void RandomGenerator<T>::setSeed(const unsigned int seed)
    {
        srand(seed);
    }

    template<>
    vector<int> RandomGenerator<int>::getRandom(const unsigned int size,
            const int lowerBound,
            const int upperBound)
    {
        assert(size > 0);
        assert(lowerBound < upperBound);
        assert((upperBound - lowerBound) <= numeric_limits<int>::max());

        vector<int> randomVec;

        for (unsigned int num = 0; num < size; ++num) {
            // TODO : 注意截断的不均匀(truncate)
            int randomNum = lowerBound + rand() % (upperBound - lowerBound);
            randomVec.push_back(randomNum);
        }

        return randomVec;
    }

} // namespace cpp

#endif /* CPP_SNIPPET_SRC_RANDOMGENERATOR_H_ */
