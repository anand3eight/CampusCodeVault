#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t chopstick[5];
void *philosopher(void *num){
	int i = *(int*)num;
	printf("\nPhilosopher %d Hungry", i);
	sem_wait(&chopstick[i]);
	sem_wait(&chopstick[(i+1)%5]);
	printf("\nPhilosopher %d is Eating with Forks %d and %d", i, i, (i+1)%5);
	sleep(3);
	sem_post(&chopstick[(i+1)%5]);
	sem_post(&chopstick[i]);
	printf("\nPhilosopher %d is Thinking and puts Down Forks %d and %d", i, i, (i+1)%5);
}
void main(){
	int i, phil[5] = {0,1,2,3,4};
	pthread_t t[5];
	for(i = 0; i < 5; i++)
		sem_init(&chopstick[i], 0, 1);
	for(i = 0; i < 5; i++)
		pthread_create(&t[i], NULL, &philosopher, (void*)&phil[i]);
	for(i = 0; i < 5; i++)
		pthread_join(t[i], NULL);
}
