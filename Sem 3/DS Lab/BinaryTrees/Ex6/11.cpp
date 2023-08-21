// SumTree check

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
    cout << "Left Node of " << x;
    p->left = create();
    cout << "Right Node of " << x;
    p->right = create();
    return p;
}

bool leaf(BTNode *p)
{
    return !p->left && !p->right;
}

int sumTree(BTNode *p)
{
    if (!p)
        return 0;
    return p->data + sumTree(p->left) + sumTree(p->right);
}
bool sumTreeCheck(BTNode *p)
{
    if (!p || leaf(p))
        return true;
    int lSum, rSum;
    lSum = sumTree(p->left);
    rSum = sumTree(p->right);
    return sumTreeCheck(p->left) && sumTreeCheck(p->right) && (lSum + rSum == p->data);
}

int main(int argc, char const *argv[])
{
    BTNode *root = create();
    if (sumTreeCheck(root))
        cout << "Sum Tree";
    else
        cout << "Not a Sum Tree";
    return 0;
}