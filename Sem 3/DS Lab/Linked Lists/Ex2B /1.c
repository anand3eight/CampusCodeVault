//Single Linked List - Palindrome Check

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int num;
	struct Node *next;
}*left;

typedef struct Node Node;

Node *push(Node *ptr)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Value : ");
    scanf("%d", &new->num);
    new->next = ptr->next;
    ptr->next = new;
    return new;
}

bool isPalindrome(Node *right)
{
		int isp;
		if(right == NULL)
				return 1;
		isp = isPalindrome(right->next);
		if(isp == 0)
				return 0;
		int isp2 = (left->num == right->num);
		left = left->next;
		return isp2;
}

void display(Node *ptr)
{
      printf("\nList : ");
      while(ptr != NULL)
      {
            printf("%d ", ptr->num);
            ptr = ptr->next;
      }
}

void main()
{
		int i, n;
	  Node *current, *head = (struct Node*)malloc(sizeof(struct Node));
    current = head;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        current = push(current);
    }
		current->next = NULL;
    display(head->next);
		left = head->next;
		int op = isPalindrome(head->next);
		if(op == 1)
				printf("\nPalindrome");
		else
				printf("\nNot a Palindrome");
}
