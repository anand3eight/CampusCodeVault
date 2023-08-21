// Root to Leaf Paths in a binary Tree

#include <iostream>
#include <cstdlib>
#include <vector>

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

bool leaf(BTNode *p)
{
    return !p->left && !p->right;
}

void printTree(vector<int> path)
{
    cout << "\nPath : ";
    for (auto & a : path)
    {
        cout << a << " ";
    }
}

void rootToLeaf(BTNode *p, vector <int> path)
{
    if (!p)
        return;
    path.push_back(p->data);
    if (leaf(p))
        printTree(path);
    else
    {
        rootToLeaf(p->left, path);
        rootToLeaf(p->right, path);
    }
}
int main(int argc, char const *argv[])
{
    BTNode *root = create();
    vector <int> path;
    rootToLeaf(root, path);
}();
    int pathLen = 0, path[] = {};
    rootToLeaf(root, path, pathLen);
}