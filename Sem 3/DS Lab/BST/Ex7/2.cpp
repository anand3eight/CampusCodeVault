// Least Common Ancestor of Two Nodes in BST

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

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
    if (val > (*p)->data)
    {
        insertBST(&(*p)->right, val);
        return;
    }
}
vector<int> rootToNode(BTNode *p, vector<int> path, int val)
{
    if (!p)
        return path;
    path.push_back(p->data);
    if (val < p->data)
        return rootToNode(p->left, path, val);
    else if (val > p->data)
        return rootToNode(p->right, path, val);
    else if (val == p->data)
        return path;
    return path;
}

int lcn(vector<int> path1, vector<int> path2)
{
    int cmn = -1;
    for (int i = 0; i < min(path1.size(), path2.size()); i++)
    {
        if (path1[i] != path2[i])
            break;
        cmn = path1[i];
    }
    return cmn;
}

int main(int argc, char const *argv[])
{
    int n1, n2, ans;
    vector<int> path1, path2;
    queue<int> t({5, 4, 3, 6, 7, 8});
    BTNode *root = NULL;
    while (!t.empty())
    {
        insertBST(&root, t.front());
        t.pop();
    }
    cout << "Enter Values : ";
    cin >> n1 >> n2;
    path1 = rootToNode(root, path1, n1);
    path2 = rootToNode(root, path2, n2);
    ans = lcn(path1, path2);
    if (n1 != -1)
        cout << "Least Common Ancestor of " << n1 << " and " << n2 << " is : " << ans;
    else
        cout << "No Common Ancestor";
    return 0;
}