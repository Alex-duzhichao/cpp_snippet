#include <iostream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <limits>
#include <boost/algorithm/string.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/Sort.h"

using std::vector;
using namespace std;

class SortTest : public ::testing::Test
{
public:

protected:
    virtual void SetUp()
    {
        // vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10000; ++i) {
            vec.push_back(i);
        }
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(vec.begin(), vec.end());
        // printVec(vec);
    }
    virtual void TearDown()
    {
        // printVec(vec);
        vector<int> sorted = vec;
        sort(sorted.begin(), sorted.end());
        EXPECT_EQ(vec, sorted);
    }
    vector<int> vec;
}; // class SingletonTest


TEST_F(SortTest, StdSortTest)
{
    sort(vec.begin(), vec.end());
}

TEST_F(SortTest, BubbleSortTest)
{
    BubbleSort(vec);
}

TEST_F(SortTest, SelectSortTest)
{
    SelectSort(vec);
}

TEST_F(SortTest, InsertSortTest)
{
    InsertSort(vec);
}

#if 0
TEST_F(SortTest, ShellBubbleSortTest)
{
    ShellBubbleSort(vec);
}

TEST_F(SortTest, ShellSelectSortTest)
{
    ShellSelectSort(vec);
}

TEST_F(SortTest, ShellInsertSortTest)
{
    ShellInsertSort(vec);
}
#endif

TEST_F(SortTest, ShellSortTest)
{
    ShellSort(vec);
}

TEST_F(SortTest, HeapSortTest)
{
    HeapSort(vec);
}

TEST_F(SortTest, MergeSortTest)
{
    int arr[vec.size()];
    for (int n = 0; n < vec.size(); ++n) {
        arr[n] = vec[n];
    }
    MergeSort(arr, 0, vec.size() - 1);
    vector<int> temp(arr, arr + vec.size());
    vec = temp;
}

TEST_F(SortTest, QuickSortTest)
{
    int arr[vec.size()];
    for (int n = 0; n < vec.size(); ++n) {
        arr[n] = vec[n];
    }
    QuickSort(arr, 0, vec.size() - 1);
    vector<int> temp(arr, arr + vec.size());
    vec = temp;
}

// TEST_F(SortTest, HeapTest)
// {
    // Heap heap;
    // for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        // heap.insert(*it);
    // }
    // sort(vec.begin(), vec.end());
    // EXPECT_TRUE(is_heap(heap.m_vec.begin(), heap.m_vec.end()));
    // EXPECT_EQ(heap.getMin(), *max_element(vec.begin(), vec.end()));
    // int min = heap.extractMin();
    // EXPECT_EQ(min, *max_element(vec.begin(), vec.end()));
    // EXPECT_TRUE(is_heap(heap.m_vec.begin(), heap.m_vec.end()));
// }
