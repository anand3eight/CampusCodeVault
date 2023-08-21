// Iterative method to find height of Binary Tree

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

int heightTree(BTNode *p)
{
    if (!p)
        return 0;
    queue<BTNode *> LevelNodeQ;
    BTNode *temp;
    int ht = 0, nodeCount = 0;
    LevelNodeQ.push(p);
    while (!LevelNodeQ.empty())
    {
        ht++;
        nodeCount = LevelNodeQ.size();
        while (nodeCount--)
        {
            temp = LevelNodeQ.front();
            if (temp->left)
                LevelNodeQ.push(temp->left);
            if (temp->right)
                LevelNodeQ.push(temp->right);
            LevelNodeQ.pop();
        }
    }
    return ht;
}
int main(int argc, char const *argv[])
{
    BTNode *root = create();
    cout << "Height : " << heightTree(root);
    return 0;
}