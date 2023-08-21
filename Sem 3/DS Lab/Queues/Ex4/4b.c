//Regular Queue using Arrays

#include<stdio.h>
#include<stdlib.h>
int *queue, *priority, job = 0;

void enqueue(int *rear, int len)
{
	if(*rear == len-1)
	{
		printf("Overflow");
	}
	else
	{
		printf("Enter Priority : ");
		scanf("%d", &priority[++(*rear)]);
    queue[*rear] = ++job;
	}
}

void dequeue(int *rear)
{
	if(*rear == -1)
	{
		printf("Underflow");
	}
	else
	{
		int i, val = 0, max = -1;
		for(i = 0; i <= *rear; i++)
		{
		      if(priority[i] > max)
          {
              max = priority[i];
              val = i;
          }
		}
    printf("\nJob : %d(%d)", queue[val], priority[val]);
    (*rear)--;
    for(i = val;i <= *rear; i++)
    {
        queue[i] = queue[i+1];
        priority[i] = priority[i+1];
    }
	}
}

void display(int *rear)
{
	int i;
	printf("Queue : ");
  while(*rear != -1)
  {
      dequeue(rear);
  }
  job = -1;
}

void main()
{
	int len, ch, loop = 1, rear = -1;
	printf("Enter Length : ");
	scanf("%d", &len);
	queue = (int*)malloc(sizeof(int) * len);
  priority = (int*)malloc(sizeof(int) * len);
	while(loop != 0)
	{
		printf("\n1 : Enqueue \n2 : Dequeue \n3 : Display \nEnter Choice \n->");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				enqueue(&rear, len);
				break;
			case 2 :
				dequeue(&rear);
				break;
			case 3 :
				display(&rear);
				break;
			default :
				printf("\nInvalid Choice");
     }
      printf("\nTo End : Press 0 -> ");
			scanf("%d", &loop);
	}

}
