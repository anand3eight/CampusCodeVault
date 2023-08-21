#include<stdio.h>
#include<stdlib.h>

int i;

void find_waiting_time(int process[],int n,int bt[],int wt[])
{
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1] + bt[i-1];
	}
}

void find_tat(int process[],int n,int bt[],int wt[],int tat[])
{
	for(i=0;i<n;i++)
	{
		tat[i]=wt[i] + bt[i];
	}
}

int main()
{
	int process[] = {1,2,3};
	int n = sizeof(process)/sizeof(process[0]);
	int burst_time[] = {5,3,5};
	int wt[n],tat[n];
	int avg_wt,avg_tat;
	
	find_waiting_time(process,n,burst_time,wt);  //Waiting time
	find_tat(process,n,burst_time,wt,tat);      //TAT
	
	printf("PROCESS  BT  WT  TAT");
	for(i=0;i<n;i++)
	{
		printf("\n %d       %d   %d   %d",process[i],burst_time[i],wt[i],tat[i]);
	}
	
	//Average Time
	float sum=0;                        //avg waiting time
	for(i=0;i<n;i++)
	{
		sum+=wt[i];
	}
	float avgwt=sum/n;
	printf("\n\n Average WT :%.2f",avgwt);
	
	float sum1=0;
	for(i=0;i<n;i++)                    //avg TAT
	{
		sum1+=tat[i];
	}
	float avgtat=sum1/n;
	printf("\n Average TAT :%.2f",avgtat);
	return 0;
}
