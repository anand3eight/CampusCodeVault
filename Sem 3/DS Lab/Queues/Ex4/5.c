//Queues using Two Stacks

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int len, ch, top1 = -1, top2 = -1, loop = 1;
	printf("Enter Length : ");
	scanf("%d", &len);
	int *st1, *st2;
	st1 = (int*)malloc(sizeof(int) * len);
	st2 = (int*)malloc(sizeof(int) * len);
	while(loop != 0)
	{
		printf("\n1 : Enqueue \n2 : Dequeue \n3 : Display \nEnter Choice \n->");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				if(top1 == len-1)
				{
					printf("Overflow");
					continue;
				}
				printf("Enter Value : ");
				scanf("%d", &st1[++top1]);
				break;
			case 2 :
				while(top1 > 0)
				{
					st2[++top2] = st1[top1--];
				}
				if(top1 == -1)
				{
					printf("Underflow");
					continue;
				}
				printf("Dequeue : %d", st1[top1--]);
				while(top2 > -1)
				{
					st1[++top1] = st2[top2--];
				}
				break;
			case 3 :
				printf("Queue : ");
				while(top1 > -1)
				{
					st2[++top2] = st1[top1--];
				}
				while(top2 > -1)
				{
					printf("%d ", st2[top2--]);
				}
				break;
			default :
				printf("\nInvalid Choice");
		}
			printf("\nTo End : Press 0 -> ");
			scanf("%d", &loop);
	}

}
