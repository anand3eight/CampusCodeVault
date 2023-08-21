// Height of BST

#include <iostream>
#include <cstdlib>
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

int height(BTNode *p)
{
    if (!p)
        return -1;
    return 1 + max(height(p->left), height(p->right));
}

int main(int argc, char const *argv[])
{
    queue<int> t({7, 3, 5, 2, 1, 4, 6, 7});
    BTNode *root = NULL;
    while (!t.empty())
    {
        insertBST(&root, t.front());
        t.pop();
    }
    cout << "Height of BST : " << height(root);
    return 0;
}