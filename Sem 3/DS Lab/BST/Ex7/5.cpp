// Sum of Leaf Nodes in BST

#include <iostream>
#include <cstdlib>

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

int main(int argc, char const *argv[])
{
    int n, nval, val;
    cout << "Enter Number of TestCases : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Number of Values : ";
        cin >> nval;
        BTNode *root = NULL;
        for (i = 0; i < nval; i++)
        {
            cin >> val;
            insertBST(&root, val);
        }
        cout << "\nLeaf Sum : " << leafSum(root);
    }
}
