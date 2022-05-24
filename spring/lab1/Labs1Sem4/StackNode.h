#include "TreeNode.h"

template <typename T>
class StackNode
{
    TreeNode<T>* data;
public:

    TreeNode<T>* getData()
    {
        return this->data;
    }

    StackNode(TreeNode<T>* data, StackNode<T>* pNext)
    {
        this->data = data;
        this->pNext = pNext;
    }

    StackNode<T>* pNext;
};
