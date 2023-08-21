// Minimum Value in a BST

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

typedef struct BTNode BTNode;

struct BTNode
{
    int data;
    BTNode *left, *right;
};

void insertBST(BTNode **p, int val)
{
    if (!*p)
    {
        BTNode *n = (BTNode *)malloc(sizeof(BTNode));
        n->data = val;
        n->left = n->right = NULL;
        *p = n;
        return;
    }
    if (val < (*p)->data)
    {
        insertBST(&(*p)->left, val);
        return;
    }
    if (val > (*p)->data)
    {
        insertBST(&(*p)->right, val);
        return;
    }
}

int minOfTree(BTNode *p)
{
    if (!p)
        return -1;
    if (!p->left)
        return p->data;
    return minOfTree(p->left);
}

int main(int argc, char const *argv[])
{
    queue<int> t({5, 4, 3, 6, 7, 8});
    BTNode *root = NULL;
    while (!t.empty())
    {
        insertBST(&root, t.front());
        t.pop();
    }
    cout << "Minimum Value is : " << minOfTree(root);
}