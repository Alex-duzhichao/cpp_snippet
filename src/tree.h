/**
 * @File : tree.h
 * @Brief :
 * @Author : Name:AlexDu Email:duzhichaomail@gmail.com
 * @Version : 1.0.0
 * @Date : 2017-03-08
 */
#include <stddef.h>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class Tree;

template<typename T>
class TreeNode
{
    friend class Tree<T>;
public:
    typedef TreeNode<T> this_type;
    TreeNode() : m_oValue(), m_pParent(NULL), m_pLeftChild(NULL), m_pRightChild(NULL)
    {}

    TreeNode(const T &value) : m_oValue(value), m_pParent(NULL), m_pLeftChild(NULL), m_pRightChild(NULL)
    {}

    void setValue(const T &value)
    {
        m_oValue = value;
    }

    T getValue()
    {
        return m_oValue;
    }

    void setParent(TreeNode<T> *ptr)
    {
        m_pParent = ptr;
    }

    void setLeftChild(TreeNode<T> *ptr)
    {
        m_pLeftChild = ptr;
    }

    void setRightChild(TreeNode<T> *ptr)
    {
        m_pRightChild = ptr;
    }

private:
    T m_oValue;
    TreeNode<T> *m_pParent;
    TreeNode<T> *m_pLeftChild;
    TreeNode<T> *m_pRightChild;
};

template<typename T>
class Tree
{
public:
    typedef TreeNode<T> node_type;

    Tree() : m_pRoot(NULL)
    {}

    void treeMiddleTraversalAux(vector<T> &vec, node_type *root)
    {
        if(root->m_pLeftChild) {
            treeMiddleTraversalAux(vec, root->m_pLeftChild);
        }

        vec.push_back(root->m_oValue);

        if(root->m_pRightChild) {
            treeMiddleTraversalAux(vec, root->m_pRightChild);
        }

    }

    void treeMiddleTraversal(vector<T> &vec)
    {
        treeMiddleTraversalAux(vec, m_pRoot);
    }

    int getHeightAux(node_type *root)
    {
        if(!root) {
            return 0;
        }

        int leftHeight = getHeightAux(root->m_pLeftChild);
        int rightHeight = getHeightAux(root->m_pRightChild);
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }

    int getHeight()
    {
        return getHeightAux(m_pRoot);
    }

    void insert(TreeNode<T> *pNode)
    {
        if(!m_pRoot) {
            m_pRoot = pNode;
            return;
        }

        node_type *pTemp = m_pRoot;

        while(1) {
            if(pTemp && pNode->m_oValue < pTemp->m_oValue) {
                if(!pTemp->m_pLeftChild) {
                    break;
                }

                pTemp = pTemp->m_pLeftChild;
            }

            if(pTemp && pNode->m_oValue > pTemp->m_oValue) {
                if(!pTemp->m_pRightChild) {
                    break;
                }

                pTemp = pTemp->m_pRightChild;
            }
        }

        if(pNode->m_oValue < pTemp->m_oValue) {
            pTemp->setLeftChild(pNode);
            pNode->setParent(pTemp);
        } else {
            pTemp->setRightChild(pNode);
            pNode->setParent(pTemp);
        }
    }

    node_type *findAux(node_type *root, const T &value)
    {
        node_type *ret = NULL;
        node_type *pTemp = root;

        while(pTemp) {
            if(pTemp && value < pTemp->m_oValue) {
                if(!pTemp->m_pLeftChild) {
                    break;
                }

                pTemp = pTemp->m_pLeftChild;
            }

            if(pTemp && value > pTemp->m_oValue) {
                if(!pTemp->m_pRightChild) {
                    break;
                }

                pTemp = pTemp->m_pRightChild;
            }

            if(pTemp && value == pTemp->m_oValue) {
                ret = pTemp;
                break;
            }
        }

        return ret;
    }

    node_type *find(const T &value)
    {
        return findAux(m_pRoot, value);
    }

    node_type *findMinAux(node_type *node)
    {
        node_type *pTemp = node;

        while(pTemp && pTemp->m_pLeftChild) {
            pTemp = pTemp->m_pLeftChild;
        }

        return pTemp;
    }

    node_type *findMin()
    {
        return findMinAux(m_pRoot);
    }

    node_type *findMaxAux(node_type *node)
    {
        node_type *pTemp = node;

        while(pTemp && pTemp->m_pRightChild) {
            pTemp = pTemp->m_pRightChild;
        }

        return pTemp;
    }

    node_type *findMax()
    {
        return findMaxAux(m_pRoot);
    }

    node_type *delAux(node_type *root, const T &value)
    {
        node_type *pFind = findAux(root, value);

        if(pFind) {
            if(pFind->m_pLeftChild == NULL) {
                if(pFind == m_pRoot) {
                    m_pRoot = pFind->m_pRightChild;
                } else {
                    if(pFind == pFind->m_pParent->m_pLeftChild) {
                        pFind->m_pParent->setLeftChild(pFind->m_pRightChild);
                    } else {
                        pFind->m_pParent->setRightChild(pFind->m_pRightChild);
                    }

                    if(pFind->m_pRightChild) {
                        pFind->m_pRightChild->setParent(pFind->m_pParent);
                    }
                }
            } else if(pFind->m_pRightChild == NULL) {
                if(pFind == m_pRoot) {
                    m_pRoot = pFind->m_pLeftChild;
                } else {
                    if(pFind == pFind->m_pParent->m_pLeftChild) {
                        pFind->m_pParent->setLeftChild(pFind->m_pLeftChild);
                    } else {
                        pFind->m_pParent->setRightChild(pFind->m_pLeftChild);
                    }

                    if(pFind->m_pLeftChild) {
                        pFind->m_pLeftChild->setParent(pFind->m_pParent);
                    }

                }
            } else {
                node_type *pMax = findMaxAux(pFind->m_pLeftChild);
                swap(pFind->m_oValue, pMax->m_oValue);
                pFind = delAux(pMax, value);
            }
        }

        return pFind;
    }

    node_type *del(const T &value)
    {
        return delAux(m_pRoot, value);
    }

    node_type *getNext(const T &value)
    {
        node_type *node = find(value);

        if(!node) {
            return NULL;
        }

        if(node->m_pRightChild) {
            node = node->m_pRightChild;

            while(node->m_pLeftChild) {
                node = node->m_pLeftChild;
            }
        } else {
            node_type *temp = node->m_pParent;

            while(temp && node == temp->m_pRightChild) {
                node = temp;
                temp = node->m_pParent;
            }

            if(node != temp) {
                node = temp;
            }
        }

        return node;
    }

    node_type *getPrev(const T &value)
    {
        node_type *node = find(value);

        if(!node) {
            return NULL;
        }

        if(node->m_pLeftChild) {
            node = node->m_pLeftChild;

            while(node->m_pRightChild) {
                node = node->m_pRightChild;
            }
        } else {
            node_type *temp = node->m_pParent;

            while(temp && node == temp->m_pLeftChild) {
                node = temp;
                temp = node->m_pParent;
            }

            if(node != temp) {
                node = temp;
            }
        }

        return node;
    }
private:
    node_type *m_pRoot;

}; // class Tree

enum {
    BLACK,
    RED
};
template<typename T>
class RbTree;

struct RbTreeStat {
    int level;
    int value;
    int color;
    RbTreeStat(int l = -1, int v = -1, int c = BLACK) : level(l), value(v), color(c) {}
};

template<typename T>
class RbTreeNode
{
    typedef RbTreeNode<T> this_type;
    friend class RbTree<T>;
public:
    RbTreeNode() : m_oValue(), m_nColor(RED), m_pParent(NULL), m_pLeftChild(NULL), m_pRightChild(NULL)
    {}

    RbTreeNode(const T &value) : m_oValue(value), m_nColor(RED), m_pParent(NULL), m_pLeftChild(NULL), m_pRightChild(NULL)
    {}

    void setValue(const T &value)
    {
        m_oValue = value;
    }

    T getValue()
    {
        return m_oValue;
    }

    void setColor(const int color)
    {
        m_nColor = color;
    }

    void setParentColor(const int color)
    {
        if(m_pParent) {
            m_pParent->m_nColor = color;
        }
    }

    int getParentColor()
    {
        return m_pParent ? m_pParent->m_nColor : RED;
    }

    void setUncleColor(const int color)
    {
        if(m_pParent == m_pParent->m_pParent->m_pLeftChild) {
            m_pParent->m_pParent->m_pRightChild->m_nColor = color;
        } else {
            m_pParent->m_pParent->m_pLeftChild->m_nColor = color;
        }
    }
    int getUncleColor()
    {
        if(m_pParent == m_pParent->m_pParent->m_pLeftChild) {
            return m_pParent->m_pParent->m_pRightChild ? m_pParent->m_pParent->m_pRightChild->m_nColor : BLACK;
        } else {
            return m_pParent->m_pParent->m_pLeftChild ? m_pParent->m_pParent->m_pLeftChild->m_nColor : BLACK;
        }
    }

    void setGrandParentColor(const int color)
    {
        if(m_pParent && m_pParent->m_pParent) {
            m_pParent->m_pParent->m_nColor = color;
        }
    }

    int getGrandParentColor()
    {
        return m_pParent && m_pParent->m_pParent ? m_pParent->m_pParent->m_nColor : RED;
    }

    void setParent(RbTreeNode<T> *ptr)
    {
        m_pParent = ptr;
    }

    void setLeftChild(RbTreeNode<T> *ptr)
    {
        m_pLeftChild = ptr;
    }

    void setRightChild(RbTreeNode<T> *ptr)
    {
        m_pRightChild = ptr;
    }

private:
    T m_oValue;
    char m_nColor;
    RbTreeNode<T> *m_pParent;
    RbTreeNode<T> *m_pLeftChild;
    RbTreeNode<T> *m_pRightChild;
};

template<typename T>
class RbTree
{
    friend class RbTreeNode<T>;
public:
    typedef RbTreeNode<T> node_type;

    RbTree() : m_pRoot(NULL)
    {}

    int getBlackCount(node_type *root)
    {
        if(!root) {
            return 0;
        }

        if(!root->m_pLeftChild && !root->m_pRightChild) {
            if(root->m_nColor == RED) {
                return 0;
            } else {
                return 1;
            }
        }

        if(root->m_nColor == RED) {
            return std::max(getBlackCount(root->m_pLeftChild), getBlackCount(root->m_pRightChild));
        } else {
            return 1 + std::max(getBlackCount(root->m_pLeftChild), getBlackCount(root->m_pRightChild));
        }
    }

    bool isRbTreeAux(node_type *root)
    {
        if(!root) {
            return true;
        }

        if(root->m_nColor == RED) {
            if((root->m_pLeftChild && root->m_pLeftChild->m_nColor == RED)
                    || (root->m_pRightChild && root->m_pRightChild->m_nColor == RED)) {
                return false;
            }

            return isRbTreeAux(root->m_pLeftChild) && isRbTreeAux(root->m_pRightChild);
        } else if(root->m_nColor == BLACK) {
            return isRbTreeAux(root->m_pLeftChild) && isRbTreeAux(root->m_pRightChild)
                   && (getBlackCount(root->m_pLeftChild) == getBlackCount(root->m_pLeftChild));
        } else {
            return false;
        }
    }

    bool isRbTree()
    {
        if(!m_pRoot) {
            return true;
        }

        if(m_pRoot->m_nColor == RED) {
            return false;
        }

        return isRbTreeAux(m_pRoot);
    }

    void treeMiddleTraversalAux(vector<T> &vec, node_type *root)
    {
        if(root->m_pLeftChild) {
            treeMiddleTraversalAux(vec, root->m_pLeftChild);
        }

        vec.push_back(root->m_oValue);

        if(root->m_pRightChild) {
            treeMiddleTraversalAux(vec, root->m_pRightChild);
        }

    }

    void treeMiddleTraversal(vector<T> &vec)
    {
        treeMiddleTraversalAux(vec, m_pRoot);
    }

    void statAux(vector<RbTreeStat> &all, node_type *root, int level)
    {
        RbTreeStat s(level, root->m_oValue, root->m_nColor);
        all.push_back(s);

        if(root->m_pLeftChild) {
            statAux(all, root->m_pLeftChild, level + 1);
        } else {
            RbTreeStat t(level + 1, -1, BLACK);
            all.push_back(t);
        }

        if(root->m_pRightChild) {
            statAux(all, root->m_pRightChild, level + 1);
        } else {
            RbTreeStat t(level + 1, -1, BLACK);
            all.push_back(t);
        }

    }

    void stat(vector<RbTreeStat> &all)
    {
        statAux(all, m_pRoot, 1);
    }

    int getHeightAux(node_type *root)
    {
        if(!root) {
            return 0;
        }

        int leftHeight = getHeightAux(root->m_pLeftChild);
        int rightHeight = getHeightAux(root->m_pRightChild);
        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }

    int getHeight()
    {
        return getHeightAux(m_pRoot);
    }

    void rightRotate(node_type *root)
    {
        if(root->m_pLeftChild) {
            RbTreeNode<T> *pTemp = root->m_pLeftChild;
            root->setLeftChild(pTemp->m_pRightChild);

            if(pTemp->m_pRightChild) {
                pTemp->m_pRightChild->setParent(root);
            }

            pTemp->setParent(root->m_pParent);

            if(root->m_pParent) {
                if(root == root->m_pParent->m_pLeftChild) {
                    root->m_pParent->setLeftChild(pTemp);
                } else {
                    root->m_pParent->setRightChild(pTemp);
                }
            }

            pTemp->setRightChild(root);
            root->setParent(pTemp);

            if(m_pRoot == root) {
                m_pRoot = pTemp;
            }
        }
    }

    void leftRotate(node_type *root)
    {
        if(root->m_pRightChild) {
            RbTreeNode<T> *pTemp = root->m_pRightChild;
            root->setRightChild(pTemp->m_pLeftChild);

            if(pTemp->m_pLeftChild) {
                pTemp->m_pLeftChild->setParent(root);
            }

            pTemp->setParent(root->m_pParent);

            if(root->m_pParent) {
                if(root == root->m_pParent->m_pLeftChild) {
                    root->m_pParent->setLeftChild(pTemp);
                } else {
                    root->m_pParent->setRightChild(pTemp);
                }
            }

            pTemp->setLeftChild(root);
            root->setParent(pTemp);

            if(m_pRoot == root) {
                m_pRoot = pTemp;
            }
        }
    }


    void fixColor(RbTreeNode<T> *pNode)
    {
        if(pNode == m_pRoot) {
            m_pRoot->setColor(BLACK);
            return;
        }

        if(pNode->m_pParent->m_nColor == BLACK) {
            return;
        }

        if(pNode->getUncleColor() == RED) {
            pNode->setParentColor(BLACK);
            pNode->setUncleColor(BLACK);
            pNode->setGrandParentColor(RED);
            fixColor(pNode->m_pParent->m_pParent);
            return;
        }

        if(pNode->m_pParent == pNode->m_pParent->m_pParent->m_pLeftChild) {
            if(pNode == pNode->m_pParent->m_pLeftChild) {
                pNode->setParentColor(BLACK);
                pNode->setGrandParentColor(RED);
                rightRotate(pNode->m_pParent->m_pParent);
            } else {
                pNode->setColor(BLACK);
                pNode->setGrandParentColor(RED);
                node_type *pParent = pNode->m_pParent;
                node_type *pGrandParent = pNode->m_pParent->m_pParent;
                leftRotate(pParent);
                rightRotate(pGrandParent);
            }
        } else {
            if(pNode == pNode->m_pParent->m_pRightChild) {
                pNode->setParentColor(BLACK);
                pNode->setGrandParentColor(RED);
                leftRotate(pNode->m_pParent->m_pParent);
            } else {
                pNode->setColor(BLACK);
                pNode->setGrandParentColor(RED);
                node_type *pParent = pNode->m_pParent;
                node_type *pGrandParent = pNode->m_pParent->m_pParent;
                rightRotate(pParent);
                leftRotate(pGrandParent);
            }
        }

        m_pRoot->setColor(BLACK);

    }

    void insert(RbTreeNode<T> *pNode)
    {
        if(!m_pRoot) {
            m_pRoot = pNode;
            pNode->setColor(BLACK);
            return;
        }

        node_type *pTemp = m_pRoot;

        while(pTemp) {
            if(pNode->m_oValue < pTemp->m_oValue) {
                if(!pTemp->m_pLeftChild) {
                    break;
                }

                pTemp = pTemp->m_pLeftChild;
            }

            if(pNode->m_oValue > pTemp->m_oValue) {
                if(!pTemp->m_pRightChild) {
                    break;
                }

                pTemp = pTemp->m_pRightChild;
            }
        }

        if(pNode->m_oValue < pTemp->m_oValue) {
            pTemp->setLeftChild(pNode);
            pNode->setParent(pTemp);
        } else {
            pTemp->setRightChild(pNode);
            pNode->setParent(pTemp);
        }

        fixColor(pNode);
    }

    node_type *find(const T &value)
    {
        node_type *ret = NULL;
        node_type *pTemp = m_pRoot;

        while(pTemp) {
            if(value < pTemp->m_oValue) {
                if(!pTemp->m_pLeftChild) {
                    break;
                }

                pTemp = pTemp->m_pLeftChild;
            }

            if(value > pTemp->m_oValue) {
                if(!pTemp->m_pRightChild) {
                    break;
                }

                pTemp = pTemp->m_pRightChild;
            }

            if(value == pTemp->m_oValue) {
                ret = pTemp;
                break;
            }
        }

        return ret;
    }

    node_type *findMinAux(node_type *node)
    {
        node_type *pTemp = node;

        while(pTemp && pTemp->m_pLeftChild) {
            pTemp = pTemp->m_pLeftChild;
        }

        return pTemp;
    }

    node_type *findMin()
    {
        return findMinAux(m_pRoot);
    }

    node_type *findMaxAux(node_type *node)
    {
        node_type *pTemp = node;

        while(pTemp && pTemp->m_pRightChild) {
            pTemp = pTemp->m_pRightChild;
        }

        return pTemp;
    }

    node_type *findMax()
    {
        return findMaxAux(m_pRoot);
    }

private:
    node_type *m_pRoot;

}; // class RbTree
