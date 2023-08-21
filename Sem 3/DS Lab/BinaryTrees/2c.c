//Insertion in Binary Tree - All traversals

#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode BTNode;
typedef struct Node Node;

struct BTNode{
	int data;
	BTNode *left, *right;
};

struct Node{
    BTNode *bt;
    Node *next;
};
Node *front = NULL, *rear = NULL;
void enqueue(BTNode *n)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->bt = n;
    newNode->next = NULL;
    if(!front)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

BTNode *dequeue()
{
    BTNode *temp = front->bt;
    front = front->next;
    return temp;
}

BTNode *create()
{
	int x;
	printf(" Enter Data -> (0 for No Data) : ");
	scanf("%d", &x);
	if(!x)
		return NULL;
	BTNode *p = malloc(sizeof(BTNode));
	p->data = x;
	printf("Left  Node of %d ", x);
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

void levelorder(BTNode *p)
{
    if(p)
    {
      enqueue(p);
      BTNode *temp;
      while(front)
      {
          temp = dequeue();
          printf("%d ", temp->data);
          if(temp->left)
              enqueue(temp->left);
          if(temp->right)
              enqueue(temp->right);
      }
    }
}

void main()
{
	BTNode *root = create();
	printf("\nPreOrder   : ");
	preorder(root);
	printf("\nInOrder    : ");
	inorder(root);
	printf("\nPostOrder  : ");
	postorder(root);
  printf("\nLevelOrder : ");
  levelorder(root);
}
