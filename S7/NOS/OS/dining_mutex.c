//Dining Philosopher using Mutex

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
pthread_t ph[50];
pthread_mutex_t chsk[50];
int n;
void *philosopher(int i)
{
	printf("\nPhilosopher %d has started thinking",i+1);
	pthread_mutex_lock(&chsk[i]);
	pthread_mutex_lock(&chsk[(i+1)%n]);
	printf("\nPhilosopher %d has started eating",i+1);
	sleep(2);
	pthread_mutex_unlock(&chsk[i]);
	pthread_mutex_unlock(&chsk[(i+1)%n]);
	printf("\nPhilosopher %d has finished eating",i+1);
	pthread_exit(NULL);
}

int main()
{
	int k,i;
	void *msg;
	printf("Enter the number of philosopher:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		k=pthread_mutex_init(&chsk[i],NULL);
		if(k<0)
		{
			perror("\nERROR IN INITIALIZING....");
			return 1;
		}
	}
	for(i=0;i<n;i++)
	{
		k=pthread_create(&ph[i],NULL,(void *)philosopher,(int *)i);
		if(k<0)
		{
			perror("\nERROR IN CREATING...");
			return 1;
		}
	}
	for(i=0;i<n;i++)
	{
		k=pthread_join(ph[i],(void *)msg);
		if(k<0)
		{
			perror("\nERROR IN JOINING...");
			return 1;
		}
	}
	for(i=0;i<n;i++)
	{
		k=pthread_mutex_destroy(&chsk[i]);
		if(k<0)
		{
			perror("\nERROR IN DESTROYING...");
			return 1;
		}
	}
	return 0;
}

/*OUTPUT
Enter the number of philosopher:5

Philosopher 1 has started thinking
Philosopher 1 has started eating
Philosopher 2 has started thinking
Philosopher 3 has started thinking
Philosopher 3 has started eating
Philosopher 4 has started thinking
Philosopher 5 has started thinking
Philosopher 3 has finished eating
Philosopher 1 has finished eating
Philosopher 5 has started eating
Philosopher 2 has started eating
Philosopher 2 has finished eating
Philosopher 5 has finished eating
Philosopher 4 has started eating
Philosopher 4 has finished eating*/
