//Binary Search Tree - Including Deletion

#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode BTNode;
struct BTNode{
    int data;
    BTNode *left, *right;
};

void insertBST(BTNode **p,int val){
    if(!*p){					
        BTNode *new = malloc(sizeof(BTNode));
        new->data = val;
        new->left = new->right = NULL;
        *p = new;
        return;
    }
    else if(val < (*p)->data){
        insertBST(&(*p)->left, val);
        return;
    }
    else{
        insertBST(&(*p)->right, val);
        return;
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

int leafch(BTNode *p){
	return !p->left && !p->right;
}

int singlech(BTNode *p)
{
	if(p->left && !p->right)
		return 1;
	if(!p->left && p->right)
		return 2;
	return 0;
}

BTNode *find_Max(BTNode *p)
{
	if(p && !p->right)
	{
		return p;
	}
	p = find_Max(p->right);
}
BTNode* deleteBTNode(BTNode *p, int val)
{
	if(!p)
		return p;
	if(val < p->data)
		p->left = deleteBTNode(p->left, val);
	else if(val > p->data)
		p->right = deleteBTNode(p->right, val);
	else if(val == p->data)
	{
		if(leafch(p))
		{
			free(p);
			return NULL;
		}
		else if(singlech(p) == 1)
		{
			BTNode *temp = p->left;
			free(p);
			return temp;
		}
		else if(singlech(p) == 2)
		{
			BTNode *temp = p->right;
			free(p);
			return temp;
		}
		else if(!singlech(p))
		{
			BTNode *temp = find_Max(p->left);
			p->data = temp->data;
			p->left = deleteBTNode(p->left, temp->data);
			return p;
		}
	}
}
void main(){
    BTNode *root = NULL;
    int ch = 1, val;
    while(ch){
        printf("Enter : ");
        scanf("%d", &val);
        insertBST(&root, val);
        printf("To End : Press 0-> ");
        scanf("%d", &ch);
    }
    ch = 1;
    while(ch){
    	printf("Tree : ");
    	inorder(root);
    	printf("\nEnter Delete Number : ");
    	scanf("%d", &val);
    	root = deleteBTNode(root, val);
    	printf("To End : Press 0-> ");
        scanf("%d", &ch);
	}
}
