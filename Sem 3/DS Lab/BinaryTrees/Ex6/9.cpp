// Diameter of a Binary Tree

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

int height(BTNode *p)
{
    if (!p)
        return 0;
    return 1 + max(height(p->left), height(p->right));
}

int diameter(BTNode *p)
{
    if (!p)
        return 0;
    int lDia, rDia, lHt, rHt;
    lDia = diameter(p->left);
    rDia = diameter(p->right);
    lHt = height(p->left);
    rHt = height(p->right);
    return max(lDia, max(rDia, lHt + rHt + 1));
}
int main(int argc, char const *argv[])
{
    BTNode *root = create();
    cout << "\nDiameter : " << diameter(root);
    return 0;
}