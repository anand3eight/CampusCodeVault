// BST from PreOrder Traversal

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
    if (val >= (*p)->data)
    {
        insertBST(&(*p)->right, val);
        return;
    }
}

int leafSum(BTNode *p)
{
    if (!p)
        return 0;
    if (!p->left && !p->right)
        return p->data;
    return leafSum(p->left) + leafSum(p->right);
}

void inorder(BTNode *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}
int main(int argc, char const *argv[])
{
    queue<int> tree({5, 6, 4, 7, 3, 8});
    BTNode *root = NULL;
    while (!tree.empty())
    {
        insertBST(&root, tree.front());
        tree.pop();
    }
    cout << "BST : ";
    inorder(root);
}
