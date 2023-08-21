#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* input(){
	char *arr = (char*)malloc(sizeof(char) * 20);
	printf("Enter Word : ");
	scanf("%s", arr);
	pthread_exit(arr);
}

void main(){
	pthread_t t1, t2;
	char *inp1 = (char*)malloc(sizeof(char) * 20);
	char *inp2 = (char*)malloc(sizeof(char) * 20);
	pthread_create(&t1, NULL, &input, NULL);
	pthread_join(t1, (void**)&inp1);
	pthread_create(&t2, NULL, &input, NULL);
	pthread_join(t2, (void**)&inp2);
	printf("%s %s!", inp1, inp2);
}
