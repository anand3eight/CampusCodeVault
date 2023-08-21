// Print ancestors of the given Node

#include <iostream>
#include <cstdlib>
#include<vector>

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

void printTree(vector <int> path)
{
    cout << "\nPath : ";
    for (auto & a : path)
    {
        cout << a << " ";
    }
}

void rootToLeaf(BTNode *p, vector <int> path, int val)
{
    if (!p)
        return;
    path.push_back(p->data);
    if (p->data == val)
        printTree(path);
    else
    {
        rootToLeaf(p->left, path, val);
        rootToLeaf(p->right, path, val);
    }
}
int main(int argc, char const *argv[])
{
    BTNode *root = create();
    int val = 0;
    vector <int> path;
    cout << "Enter Value : ";
    cin >> val;
    rootToLeaf(root, path, val);
}> val;
    rootToLeaf(root, path, pathLen, val);
}