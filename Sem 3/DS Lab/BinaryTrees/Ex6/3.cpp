// Check if Two Trees are Identical

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

bool equaltrees(BTNode *p1, BTNode *p2)
{
    if ((!p1 && p2) || (p1 && !p2))
        return false;
    if (!p1 && !p2)
        return true;
    bool check;
    if (p1 && p2)
    {
        check = (p1->data == p2->data);
        if (check)
            check = check && equaltrees(p1->left, p2->left);
        if (check)
            check = check && equaltrees(p1->right, p2->right);
    }
    return check;
}
int main(int argc, char const *argv[])
{
    cout << "Tree 1\n";
    BTNode *root1 = create();
    cout << "Tree 2\n";
    BTNode *root2 = create();
    if (equaltrees(root1, root2))
        cout << "Trees are Identical";
    else
        cout << "Trees are not identical";
    return 0;
}