// Counting Leaf Nodes in a Tree

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
    cout << "Enter Data -> (0 for No Data) : ";
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

bool leaf(BTNode *p)
{
    return !p->left && !p->right;
}

int leafCount(BTNode *p)
{
    int count = 0;
    if (!p)
        return 0;
    if (leaf(p))
        return 1;
    else
        count = leafCount(p->left) + leafCount(p->right);
    return count;
}
int main(int argc, char const *argv[])
{
    BTNode *root = create();
    cout << "Leaf Nodes : " << leafCount(root);
    return 0;
}