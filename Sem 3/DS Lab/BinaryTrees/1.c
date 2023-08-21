//insertion in Binary Tree

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

void preorder(BTNode *p)
{
	if(p){
		printf("%d ", p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(BTNode *p)
{
	if(p){
		inorder(p->left);
		printf("%d ", p->data);
		inorder(p->right);
	}
}

void postorder(BTNode *p)
{
	if(p){
		postorder(p->left);
		postorder(p->right);
		printf("%d ", p->data);
	}
}
void main()
{
	BTNode *root = create();
	printf("\nPreOrder : ");
	preorder(root);
	printf("\nInOrder  : ");
	inorder(root);
	printf("\nPostOrder: ");
	postorder(root);
}
