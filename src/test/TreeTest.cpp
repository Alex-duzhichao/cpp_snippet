#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "src/CGI.h"
#include "src/tree.h"
#include "GTestColorPrint.h"

using std::string;
using cpp::CGI;
using namespace std;
using boost::to_upper;
using boost::to_upper_copy;

const int TREE_NODE_NO = 10000;
//const int TREE_NODE_NO = 10;

class TreeTest : public ::testing::Test
{
public:
    static void SetUpTestCase()
    {
        // vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < TREE_NODE_NO; ++i) {
            vec.push_back(i);
        }

        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(vec.begin(), vec.end());
        // printVec(vec);
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
    static vector<int> vec;
    static Tree<int> intTree;
};
vector<int> TreeTest::vec;
Tree<int> TreeTest::intTree;

TEST_F(TreeTest, TreeTestInsert)
{
    for (int i = 0; i < vec.size(); ++i) {
        TreeNode<int> *p = new TreeNode<int>(vec[i]);
        intTree.insert(p);
    }
    vector<int> out;
    intTree.treeMiddleTraversal(out);
    // for (vector<int>::const_iterator it = out.begin(); it != out.end(); ++it) {
    // cout << *it << " ";
    // }
    // cout << endl;
    sort(vec.begin(), vec.end());
    EXPECT_EQ(vec, out);
}

TEST_F(TreeTest, TreeHeightTest)
{
    int height = intTree.getHeight();
    GCOUT << "tree size : " << TREE_NODE_NO << "    height : " << height << endl;
}

TEST_F(TreeTest, TreeFindTest)
{
    // int height = intTree.getHeight();
    // cout << "height : " << height << endl;

    for (int i = 0; i < 2 * vec.size(); ++i) {
        TreeNode<int> *find = intTree.find(i);
        if(i < vec.size()) {
            // cout << "RbTree find : " << i << "   " << find << endl;
            EXPECT_TRUE(find);
        } else {
            EXPECT_FALSE(find);
        }
    }

    TreeNode<int> *findMin = intTree.findMin();
    EXPECT_EQ(findMin->getValue(), 0);
    TreeNode<int> *findMax = intTree.findMax();
    EXPECT_EQ(findMax->getValue(), vec.size() - 1);
}

TEST_F(TreeTest, TreeGetNextAndPrevTest)
{
    for (int i = 0; i < 2 * vec.size(); ++i) {
        TreeNode<int> *next = intTree.getNext(i);
        if(i < vec.size() - 1) {
            EXPECT_TRUE(next);
            EXPECT_EQ(next->getValue(), i + 1);
        } else {
            EXPECT_FALSE(next);
        }
    }

    for (int i = 0; i < 2 * vec.size(); ++i) {
        TreeNode<int> *prev = intTree.getPrev(i);
        if(i == 0) {
            EXPECT_FALSE(prev);
        }else if(i < vec.size()) {
            EXPECT_TRUE(prev);
            EXPECT_EQ(prev->getValue(), i - 1);
        } else {
            EXPECT_FALSE(prev);
        }
    }
}

TEST_F(TreeTest, TreeDelTest)
{
    for (int i = 0; i < 2 * vec.size(); ++i) {
        if(i < vec.size()) {
            TreeNode<int> *min = intTree.findMin();
            EXPECT_EQ(min->getValue(), i);
        }

        TreeNode<int> *del = intTree.del(i);

        if(i < vec.size()) {
            EXPECT_TRUE(del);
            EXPECT_EQ(del->getValue(), i);
        } else {
            EXPECT_FALSE(del);
        }
    }
}

class RbTreeTest : public ::testing::Test
{
public:
    static void SetUpTestCase()
    {
        // vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < TREE_NODE_NO; ++i) {
            vec.push_back(i);
        }

        srand(static_cast<unsigned int>(time(0)));
        // random_shuffle(vec.begin(), vec.end());
        // printVec(vec);
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
    static vector<int> vec;
    static RbTree<int> intTree;
};
vector<int> RbTreeTest::vec;
RbTree<int> RbTreeTest::intTree;

TEST_F(RbTreeTest, RbTreeInsertTest)
{
    for (int i = 0; i < vec.size(); ++i) {
        RbTreeNode<int> *p = new RbTreeNode<int>(vec[i]);
        intTree.insert(p);
        // EXPECT_TRUE(intTree.isRbTree());
    }

    // vector<RbTreeStat> stat;

    // intTree.stat(stat);

    // for (int i = 0; i < stat.size(); ++i) {
        // for (int j = 0; j < stat.size(); ++j) {
            // if(stat[j].level == i) {
                // cout << stat[j].value;
                // if(stat[j].color == BLACK) {
                    // cout << "b";
                // } else {
                    // cout << "r";
                // }
                // cout << " ";
            // }
        // }
        // cout << endl;
    // }

    // int height = intTree.getHeight();
    // cout << "height : " << height << endl;

    vector<int> out;
    intTree.treeMiddleTraversal(out);
    sort(vec.begin(), vec.end());
    EXPECT_EQ(vec, out);
    // for (vector<int>::const_iterator it = out.begin(); it != out.end(); ++it) {
    // cout << *it << " ";
    // }
    // cout << endl;
}

TEST_F(RbTreeTest, RbTreeHeightTest)
{
    int height = intTree.getHeight();
    GCOUT << "rbtree size : " << TREE_NODE_NO << "     height : " << height << endl;
}

TEST_F(RbTreeTest, RbTreeFindTest)
{
    for (int i = 0; i < 2 * vec.size(); ++i) {
        RbTreeNode<int> *find = intTree.find(i);
        if(i < vec.size()) {
            // cout << "RbTree find : " << i << "   " << find << endl;
            EXPECT_TRUE(find);
        } else {
            EXPECT_FALSE(find);
        }
    }

    RbTreeNode<int> *findMin = intTree.findMin();
    EXPECT_EQ(findMin->getValue(), 0);
    RbTreeNode<int> *findMax = intTree.findMax();
    EXPECT_EQ(findMax->getValue(), vec.size() - 1);
}

TEST_F(RbTreeTest, RbTreeIsRbTreeTest)
{
    EXPECT_TRUE(intTree.isRbTree());
    // int height = intTree.getHeight();
    // cout << "height : " << height << endl;

    // vector<int> out;
    // intTree.treeMiddleTraversal(out);
    // for (vector<int>::const_iterator it = out.begin(); it != out.end(); ++it) {
    // cout << *it << " ";
    // }
    // cout << endl;
}

#if 0
TEST_F(RbTreeTest, RbTreeInsertTest)
{
    RbTree<int> intTree;

    for (int i = 0; i < vec.size(); ++i) {
        RbTreeNode<int> *p = new RbTreeNode<int>(vec[i]);
        intTree.insert(p);
        EXPECT_TRUE(intTree.isRbTree());
    }

    vector<RbTreeStat> stat;

    // intTree.stat(stat);

    // for (int i = 0; i < stat.size(); ++i) {
        // for (int j = 0; j < stat.size(); ++j) {
            // if(stat[j].level == i) {
                // cout << stat[j].value;
                // if(stat[j].color == BLACK) {
                    // cout << "b";
                // } else {
                    // cout << "r";
                // }
                // cout << " ";
            // }
        // }
        // cout << endl;
    // }

    int height = intTree.getHeight();
    // cout << "height : " << height << endl;

    vector<int> out;
    intTree.treeMiddleTraversal(out);
    vec = out;
    // for (vector<int>::const_iterator it = out.begin(); it != out.end(); ++it) {
    // cout << *it << " ";
    // }
    // cout << endl;

    for (int i = 0; i < 2 * vec.size(); ++i) {
        RbTreeNode<int> *find = intTree.find(i);
        EXPECT_TRUE(intTree.isRbTree());

        if(i < vec.size()) {
            EXPECT_TRUE(find);
        } else {
            EXPECT_FALSE(find);
        }
    }

    RbTreeNode<int> *findMin = intTree.findMin();
    EXPECT_EQ(findMin->getValue(), 0);
    RbTreeNode<int> *findMax = intTree.findMax();
    EXPECT_EQ(findMax->getValue(), vec.size() - 1);
}
#endif
