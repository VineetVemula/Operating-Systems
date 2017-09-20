#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define SIZE 5
 int s=0;
 sem_t full,empty;
 pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
 int q[SIZE];

void *prod(void *count)
{
	int* c = (int*)count;
	long int i;
	int j;
	for(i=0;i<10;i++)
	{
		sem_wait(&full);
		sem_getvalue(&full,&s);
    printf("full= %d\n", s);
		pthread_mutex_lock(&mutex);
		q[*c]=1;
		(*c)++;
		for(j=0;j<SIZE;j++)
		{
			printf("%d ", q[j]);
		}
		printf("Producer, c = %d \n" , *c);
		sem_post(&empty);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void *cons(void *count)
{
	int* c = (int*)count;
	long int i;
	int j;
	int k;
	for(i=0;i<10;i++)
	{
		sem_wait(&empty);
		sem_getvalue(&empty,&s);
        printf("empty= %d\n", s);
		pthread_mutex_lock(&mutex);
		(*c)--;
		q[*c]=0;
		for(j=0;j<SIZE;j++)
		{
			printf("%d ", q[j]);
		}
		printf("Consumer, c = %d \n" , *c);
		sem_post(&full);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	int count = 0;
	pthread_t producer;
	pthread_t consumer;
	sem_init(&full,0,SIZE);
  sem_init(&empty,0,0);
  sem_getvalue(&full,&s);
  printf("full= %d\n", s);
	pthread_create(&producer, NULL, prod, &count);
	pthread_create(&consumer, NULL, cons, &count);
  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);
  printf("Value of count is = %d\n", count);
	for(int j=0;j<SIZE;j++)
  {
 		printf("%d ", q[j]);
 	}
	exit(0);
}

