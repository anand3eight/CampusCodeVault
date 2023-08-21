//To Find a Binary Tree is Complete or Not

#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode BTNode;

struct BTNode{
	int data;
	BTNode *left, *right;
};

BTNode *create()
{
	int x;
	printf(" Enter Data -> (0 for No Data) : ");
	scanf("%d", &x);
	if(!x)
		return NULL;
	BTNode *p = malloc(sizeof(BTNode));
	p->data = x;
	printf("Left Node of %d  ", x);
	p->left = create();
	printf("Right Node of %d ", x);
	p->right = create();
	return p;
}

int singlech(BTNode *p)
{
    return (p->left && !p->right) || (!p->left && p->right);
}
int complete(BTNode *p)
{
    if(!p || !p->left && !p->right)
        return 1;
    if(singlech(p))
        return 0;
    int ch = complete(p->left) && complete(p->right);
    return ch;
}
void main()
{
	 BTNode *root = create();
	 if(complete(root))
        printf("Complete Binary Tree");
   else
        printf("Not Complete Binary Tree");
}
