#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* input(){
	int *arr = (int*)malloc(sizeof(int)*2);
	printf("Enter two numbers : ");
	scanf("%d %d", &arr[0], &arr[1]);
	pthread_exit(arr);
}

void* add(void *inp){
	int *arr = (int*)inp;
	arr[0] = arr[0] + arr[1];
	pthread_exit(&arr[0]);	
}

void main(){
	pthread_t t1, t2;
	int *inp = (int*)malloc(sizeof(int) * 2);
	int *result;
	pthread_create(&t1, NULL, &input, NULL);
	pthread_join(t1, (void**)&inp);
	pthread_create(&t2, NULL, &add, inp);
	pthread_join(t2, (void**)&result);
	printf("Answer : %d", *result);
}
