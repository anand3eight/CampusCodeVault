/* Student Details */

#include<stdio.h>
#include<string.h>

struct student 
{
	int rollno;
	char name[30], result[20];
	int m1, m2, m3, total, rank;
	float avg;
} s[10];
void main()
{
	int i, j, size; 
	printf("Enter the Number of Students : ");
	scanf("%d", &size);
	for(i = 0; i < size; i++)
	{
		printf("Enter the Details of Student %d : ", i+1);
		scanf("%d%*c%s%*c%d%*c%d%*c%d", &s[i].rollno, s[i].name, &s[i].m1, &s[i].m2, &s[i].m3);
		s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
		s[i].avg = s[i].total / 3;		
		s[i].rank = i+1;
	}
	for(i = 0; i < size; i++)
	{
		if((s[i].m1 >= 50) && (s[i].m2 >= 50) && (s[i].m3 >= 50))
		{
			if(s[i].avg >= 75)								strcpy(s[i].result, "DISTINCTION");
			else if((s[i].avg <= 74) && (s[i].avg >= 60))	strcpy(s[i].result,"FIRSTCLASS");
			else if((s[i].avg <= 59) && (s[i].avg >= 50))	strcpy(s[i].result, "SECONDCLASS");
		}
		else
		{
			strcpy(s[i].result, "FAIL");
		}
		
	}
	int temp;
	for(i = 0; i < size; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(s[i].total < s[j].total)
			{
				temp = s[i].rank;
				s[i].rank = s[j].rank;
				s[j].rank = temp;				
				
			}
		}	
	}
	temp = 1;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if(s[j].rank == temp)
			{
				printf("%d\t%5d\t%30s\t%5d\t%15s\n", s[j].rank, s[j].rollno, s[j].name, s[j].total, s[j].result);
				//printf("\t%d\n", temp);
				temp++;
			}
		}
	}
}
