#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define SIZE 5
int pthread_mutex_init(pthread_mutex_t *mutex,
			const pthread_mutexattr_t *attr);


 pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
 pthread_cond_t full  = PTHREAD_COND_INITIALIZER;  // Condition indicating queue is full
 pthread_cond_t empty = PTHREAD_COND_INITIALIZER; // Condition indicating queue is empty
 int q[SIZE];

void *prod(void *count)
{
	int* c = (int*)count;
	long int i;
	int j;
	for(i=0;i<5000;i++)
	{
		pthread_mutex_lock(&mutex);
		if(*c==(SIZE-1))
			pthread_cond_wait(&full,&mutex);
		q[*c]=1;
		(*c)++;
		for(j=0;j<SIZE;j++)
    {
  		printf("%d ", q[j]);
  	}
		printf("p\n");
		if(*c==1)
			pthread_cond_signal(&empty);
		pthread_mutex_unlock(&mutex);
		//printf("prod %d", *c);
	}
	return NULL;
}

void *cons(void *count)
{
	int* c = (int*)count;
	long int i;
	int k;
	for(i=0;i<5000;i++)
	{
		pthread_mutex_lock(&mutex);
		if(*c==0)
			pthread_cond_wait(&empty,&mutex);
		(*c)--;
		q[*c]=0;
		for(k=0;k<SIZE;k++)
    {
    	printf("%d ", q[k]);
    }
		printf("c\n");
		if(*c==SIZE-2)
			pthread_cond_signal(&full);
		pthread_mutex_unlock(&mutex);
		//printf("cons %d", *c);
	}
	return NULL;
}

int main()
{
	int count = 0;
	pthread_t producer;
	pthread_t consumer;
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
