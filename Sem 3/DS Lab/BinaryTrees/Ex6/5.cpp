// Binary Tree to a Mirror Tree

// Iterative method to find height of Binary Tree

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

void mirrorTree(BTNode *p)
{
    if (!p)
        return;
    mirrorTree(p->left);
    mirrorTree(p->right);
    BTNode *temp = p->left;
    p->left = p->right;
    p->right = temp;
}
void inorder(BTNode *p)
{
    if (p)
    {
        inorder(p->left);
        cout << " " << p->data;
        inorder(p->right);
    }
}
int main(int argc, char const *argv[])
{
    BTNode *root = create();
    cout << "\nInOrder : ";
    inorder(root);
    mirrorTree(root);
    cout << "\nMirror Inorder : ";
    inorder(root);
    return 0;
}