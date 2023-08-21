// Maximum Depth of a Binary Tree

#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct BTNode BTNode;

struct BTNode
{
    int data;
    BTNode *left, *right;
};

BTNode *create()
{
    int x;
    cout << " Enter Data -> (0 for No Data) : ";
    cin >> x;
    if (!x)
        return NULL;
    BTNode *p = (BTNode *)malloc(sizeof(BTNode));
    p->data = x;
    cout << "Left Node of  " << x;
    p->left = create();
    cout << "Right Node of " << x;
    p->right = create();
    return p;
}

int maxDepth(BTNode *p)
{
    if (!p)
        return 0;
    return 1 + max(maxDepth(p->left), maxDepth(p->right));
}

int main(int argc, char const *argv[])
{
    BTNode *root = create();
    cout << "Maximum Depth : " << maxDepth(root);
}