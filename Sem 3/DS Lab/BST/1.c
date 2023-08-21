//Binary Search Tree

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

void rinorder(BTNode *p)
{
	if(p){
		rinorder(p->right);
		printf("%d ", p->data);
		rinorder(p->left);
	}
}

int find_min(BTNode *p)
{
    if(p && !p->left){
        return p->data;
    }
    find_min(p->left);
}

int find_max(BTNode *p)
{
    if(p && !p->right){
        return p->data;
    }
    find_max(p->right);
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
    printf("Sorted Array : ");
    inorder(root);
    printf("\nReverse Sorted Array : ");
    rinorder(root);
    printf("\nMin : %d \nMax : %d", find_min(root), find_max(root));
}
