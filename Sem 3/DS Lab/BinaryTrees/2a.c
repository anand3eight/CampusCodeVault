//Binary Trees using Arrays

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *tree, len;

void create(int i)
{
    int x;
    printf("Enter Data->(0 for No Data) : ");
    scanf("%d", &tree[i]);
    if(!tree[i])
        return;
    if(2*i+1 < len)
    {
        printf("Left  Node of %d ", tree[i]);
        create(2*i+1);
    }
    if(2*i + 2 < len)
    {
       printf("Right Node of %d ", tree[i]);
       create(2*i+2);
    }
    return;
}

void preOrder(int i)
{
    if(tree[i])
      printf("%d ", tree[i]);
    if(2*i+1 < len) preOrder(2*i + 1);
    if(2*i+2 < len) preOrder(2*i + 2);
}

void inOrder(int i)
{
    if(2*i+1 < len) inOrder(2*i + 1);
    if(tree[i])
      printf("%d ", tree[i]);
    if(2*i+2 < len) inOrder(2*i + 2);
}

void postOrder(int i)
{
    if(2*i+1 < len) postOrder(2*i + 1);
    if(2*i+2 < len) postOrder(2*i + 2);
    if(tree[i])
      printf("%d ", tree[i]);
}

void main()
{
    printf("Enter Height : ");
    scanf("%d", &len);
    len = pow(2, len+1) - 1;
    int root = 0;
    if(len > -1)
    {
      tree = (int*)calloc(sizeof(int), len);
      create(root);
      printf("\nPreOrder  : ");
      preOrder(root);
      printf("\nInOrder   : ");
      inOrder(root);
      printf("\nPostOrder : ");
      postOrder(root);
    }

}
