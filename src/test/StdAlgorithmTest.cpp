#ifndef CPP_SNIPPET_SRC_TEST_STDMINMAX_TEST_CPP_
#define CPP_SNIPPET_SRC_TEST_STDMINMAX_TEST_CPP_

#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <boost/operators.hpp>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GTestColorPrint.h"

using namespace std;
class StdMinMaxTestClass : public boost::less_than_comparable<StdMinMaxTestClass>,
    public boost::equality_comparable<StdMinMaxTestClass>
{
public:
    friend bool operator< (const StdMinMaxTestClass &lhs, const StdMinMaxTestClass &rhs)
    {
        return (lhs.m_nMem < rhs.m_nMem);
    }
    friend bool operator== (const StdMinMaxTestClass &lhs, const StdMinMaxTestClass &rhs)
    {
        return !(lhs < rhs) && !(rhs < lhs);
    }
    // friend bool operator> (const StdMinMaxTestClass& lhs, const StdMinMaxTestClass& rhs);
    explicit StdMinMaxTestClass(const int num) : m_nMem(num)
    {}

private:
    int m_nMem;
}; // class StdMinMaxTestClass

TEST(StdAlgorithmTest, MaxAndMin)
{
    int lesserInt = 0;
    int biggerInt = 1;
    int equalInt = 0;

    EXPECT_EQ(lesserInt, std::min(lesserInt, biggerInt));
    EXPECT_EQ(lesserInt, std::min(biggerInt, lesserInt));
    EXPECT_GT(biggerInt, std::min(lesserInt, biggerInt));
    EXPECT_GT(biggerInt, std::min(biggerInt, lesserInt));

    EXPECT_EQ(biggerInt, std::max(lesserInt, biggerInt));
    EXPECT_EQ(biggerInt, std::max(biggerInt, lesserInt));
    EXPECT_LT(lesserInt, std::max(lesserInt, biggerInt));
    EXPECT_LT(lesserInt, std::max(biggerInt, lesserInt));

    EXPECT_EQ(equalInt, std::min(equalInt, equalInt));
    EXPECT_EQ(equalInt, std::min(equalInt, equalInt));
    EXPECT_EQ(equalInt, std::min(equalInt, equalInt));
    EXPECT_EQ(equalInt, std::min(equalInt, equalInt));

    EXPECT_EQ(equalInt, std::max(equalInt, equalInt));
    EXPECT_EQ(equalInt, std::max(equalInt, equalInt));
    EXPECT_EQ(equalInt, std::max(equalInt, equalInt));
    EXPECT_EQ(equalInt, std::max(equalInt, equalInt));

    StdMinMaxTestClass lesserObject(0);
    StdMinMaxTestClass biggerObject(1);
    StdMinMaxTestClass equalObject(0);
    EXPECT_EQ(lesserObject, std::min(lesserObject, biggerObject));
    EXPECT_EQ(lesserObject, std::min(biggerObject, lesserObject));
    EXPECT_GT(biggerObject, std::min(lesserObject, biggerObject));
    EXPECT_GT(biggerObject, std::min(biggerObject, lesserObject));

    EXPECT_EQ(biggerObject, std::max(lesserObject, biggerObject));
    EXPECT_EQ(biggerObject, std::max(biggerObject, lesserObject));
    EXPECT_LT(lesserObject, std::max(lesserObject, biggerObject));
    EXPECT_LT(lesserObject, std::max(biggerObject, lesserObject));

    EXPECT_EQ(equalObject, std::min(equalObject, biggerObject));
    EXPECT_EQ(equalObject, std::min(biggerObject, equalObject));
    EXPECT_EQ(equalObject, std::min(equalObject, equalObject));
    EXPECT_EQ(equalObject, std::min(equalObject, equalObject));

    EXPECT_EQ(equalObject, std::max(equalObject, equalObject));
    EXPECT_EQ(equalObject, std::max(equalObject, equalObject));
    EXPECT_EQ(equalObject, std::max(equalObject, equalObject));
    EXPECT_EQ(equalObject, std::max(equalObject, equalObject));
}

void doubleFun(int& num)
{
    num *= 2;
}

class doubleFunctor
{
    public:
        void operator() (int& num)
        {
             num *= 2;
        }
}; // class doubleFunctor

TEST(StdAlgorithmTest, Foreach)
{
    vector<int> vec = {-100, -1, 0, 1, 100};
    vector<int> vecFunction(vec);
    vector<int> vecFunctor(vec);
    for_each(vecFunction.begin(), vecFunction.end(), doubleFun);
    for (vector<int>::size_type n = 0; n < vec.size(); ++n) {
        EXPECT_EQ(vecFunction[n], 2 * vec[n]);
    }
    for_each(vecFunctor.begin(), vecFunctor.end(), doubleFunctor());
    for (vector<int>::size_type n = 0; n < vec.size(); ++n) {
        EXPECT_EQ(vecFunctor[n], 2 * vec[n]);
    }
}

TEST(StdAlgorithmTest, Find)
{
    vector<int> vec = {-100, -1, 0, 1, 100};
    typedef vector<int>::const_iterator VectorIter;
    VectorIter vec_it = find(vec.begin(), vec.end(), 0);
    EXPECT_NE(vec_it, vec.end());
    EXPECT_EQ(*vec_it, 0);
    vec_it = find(vec.begin(), vec.end(), 10);
    EXPECT_EQ(vec_it, vec.end());

    string str("abcdefg");
    typedef string::const_iterator StringIter;
    StringIter str_it = find(str.begin(), str.end(), 'e');
    EXPECT_NE(str_it, str.end());
    EXPECT_EQ(*str_it, 'e');
    str_it = find(str.begin(), str.end(), 'h');
    EXPECT_EQ(str_it, str.end());

    typedef string::size_type StringSizeType;
    StringSizeType pos = str.find("e");
    EXPECT_EQ(pos, 4);
    pos = str.find("h");
    EXPECT_EQ(pos, string::npos);

    map<int, string> dict = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
    typedef map<int, string>::const_iterator MapIter;
    MapIter map_it = dict.find(3);
    EXPECT_EQ(map_it->second, "three");
}

TEST(StdAlgorithmTest, FindIf)
{
    vector<int> vec = {-100, -1, 0, 1, 100};
    typedef vector<int>::const_iterator VectorIter;
    VectorIter vec_it = find_if(vec.begin(), vec.end(),
            [](int& n){return (n == 0);});
    EXPECT_EQ(*vec_it, 0);

    map<int, string> dict = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}};
    typedef map<int, string>::const_iterator MapIter;
    MapIter map_it = find_if(dict.begin(), dict.end(),
            [](pair<int, string> kv){return (kv.first == 3);});
    EXPECT_EQ(map_it->second, "three");
}

TEST(StdAlgorithmTest, FindFirstOf)
{
    typedef vector<int>::const_iterator VectorIter;
    vector<int> haystack = {-100, -1, 0, 1, 100};
    vector<int> needle = {-1, 1};
    VectorIter vec_it = find_first_of(haystack.begin(), haystack.end(),
            needle.begin(), needle.end());

    EXPECT_EQ(*vec_it, -1);

    vec_it = find_first_of(
            haystack.begin(), haystack.end(),
            needle.begin(), needle.end(),
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, -1);

    needle = {1, -1};
    vec_it = find_first_of(haystack.begin(), haystack.end(),
            needle.begin(), needle.end());

    EXPECT_EQ(*vec_it, -1);

    vec_it = find_first_of(
            haystack.begin(), haystack.end(),
            needle.begin(), needle.end(),
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, -1);
}

TEST(StdAlgorithmTest, FindEnd)
{
    typedef vector<int>::const_iterator VectorIter;
    vector<int> haystack = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> needle = {1, 2, 3};
    VectorIter vec_it = find_end(haystack.begin(), haystack.end(),
            needle.begin(), needle.end());

    EXPECT_EQ(*vec_it, 1);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 5);

    vec_it = find_end(
            haystack.begin(), haystack.end(),
            needle.begin(), needle.end(),
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, 1);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 5);

    needle = {2, 3, 4};
    vec_it = find_end(haystack.begin(), haystack.end(),
            needle.begin(), needle.end());

    EXPECT_EQ(*vec_it, 2);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 6);


    vec_it = find_end(
            haystack.begin(), haystack.end(),
            needle.begin(), needle.end(),
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, 2);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 6);

}

TEST(StdAlgorithmTest, Search)
{
    typedef vector<int>::const_iterator VectorIter;
    vector<int> haystack = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> needle = {1, 2, 3};
    VectorIter vec_it = search(haystack.begin(), haystack.end(),
            needle.begin(), needle.end());

    EXPECT_EQ(*vec_it, 1);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 0);

    vec_it = search(
            haystack.begin(), haystack.end(),
            needle.begin(), needle.end(),
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, 1);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 0);

    needle = {2, 3, 4};
    vec_it = search(haystack.begin(), haystack.end(),
            needle.begin(), needle.end());

    EXPECT_EQ(*vec_it, 2);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 1);


    vec_it = search(
            haystack.begin(), haystack.end(),
            needle.begin(), needle.end(),
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, 2);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 1);
}

TEST(StdAlgorithmTest, SearchN)
{
    typedef vector<int>::const_iterator VectorIter;
    vector<int> haystack = {1, 2, 3, 4, 4, 1, 2, 3, 4, 5};
    VectorIter vec_it = search_n(haystack.begin(), haystack.end(), 2, 4);

    EXPECT_EQ(*vec_it, 4);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 3);

    vec_it = search_n(haystack.begin(), haystack.end(), 2, 4,
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, 4);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 3);
}

TEST(StdAlgorithmTest, AdjacentFind)
{
    typedef vector<int>::const_iterator VectorIter;
    vector<int> haystack = {1, 2, 3, 4, 4, 1, 2, 3, 4, 5};
    VectorIter vec_it = adjacent_find(haystack.begin(), haystack.end());

    EXPECT_EQ(*vec_it, 4);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 3);

    vec_it = adjacent_find(haystack.begin(), haystack.end(),
            [](int lhs, int rhs){return (lhs == rhs);}
            );
    EXPECT_EQ(*vec_it, 4);
    EXPECT_EQ(distance(haystack.cbegin(), vec_it), 3);
}

TEST(StdAlgorithmTest, Count)
{
    typedef vector<int>::const_iterator VectorIter;
    vector<int> haystack = {1, 2, 3, 4, 4, 1, 2, 3, 4, 5};
    iterator_traits<VectorIter>::difference_type num = count(haystack.begin(), haystack.end(), 4);
    EXPECT_EQ(num, 3);

    num = count_if(haystack.begin(), haystack.end(), [](int n){return (n == 4);});
    EXPECT_EQ(num, 3);
}

TEST(StdAlgorithmTest, Mismatch)
{
    typedef vector<int>::const_iterator VectorIter;
    vector<int> haystack1 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> haystack2 = {1, 2, 3, 4, 4, 1, 2, 3, 4, 5};
    pair<VectorIter, VectorIter> its = mismatch(haystack1.begin(), haystack2.end(), haystack2.begin());
    EXPECT_EQ(*(its.first), 5);
    EXPECT_EQ(*(its.second), 4);

    its = mismatch(haystack1.begin(), haystack2.end(), haystack2.begin(),
            [](int lhs, int rhs){return (lhs == rhs);});
    EXPECT_EQ(*(its.first), 5);
    EXPECT_EQ(*(its.second), 4);
}

TEST(StdAlgorithmTest, Equal)
{
    vector<int> haystack1 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    vector<int> haystack2 = {1, 2, 3, 4, 4, 1, 2, 3, 4, 5};
    vector<int> haystack3 = {1, 2, 3, 4, 4, 1, 2, 3, 4, 5};
    EXPECT_FALSE(equal(haystack1.begin(), haystack1.end(), haystack2.begin()));
    EXPECT_TRUE(equal(haystack2.begin(), haystack2.end(), haystack3.begin()));
    EXPECT_FALSE(equal(haystack1.begin(), haystack1.end(), haystack2.begin(),
                [](int lhs, int rhs){return (lhs == rhs);}));
    EXPECT_TRUE(equal(haystack2.begin(), haystack2.end(), haystack3.begin(),
                [](int lhs, int rhs){return (lhs == rhs);}));
}
#endif /* CPP_SNIPPET_SRC_TEST_STDMINMAX_TEST_CPP_ */
