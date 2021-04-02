//Dining Philosophers using Semaphore

#include<stdio.h>
//#include<pthread.h>
#include<stdlib.h>
#include<fcntl.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/wait.h>
sem_t *sm[10];
int n;
int reader(int val)
{
	printf("%d Thinking\n",val);
	sem_wait(sm[val]);
	sem_wait(sm[(val+1)%n]);
	printf("%d Eating\n",val);
	sleep(2);
	printf("%d Finished eating\n",val);
	sem_post(sm[val]);
	sem_post(sm[(val+1)%n]);
	sem_close(0);
}

int main()
{
	pid_t cpid[10];
	char snm[10];
	int i,j=0;
	printf("\nEnter no.of philosophers: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sprintf(snm,"%d",getpid()+i);
		sm[i]=sem_open(snm,O_CREAT|O_EXCL,0666,1);
		if(sm[i]==SEM_FAILED)
		{
			perror("\nUnable to create semaphore");
		}
	}
	for(i=1;i<=n;i++)
	{
		cpid[i]=fork();
		if(cpid[i]==0)
		break;
	}
	if(i>n)
	{
		int sts;
		for(i=1;i<=n;i++)
			waitpid(cpid[i],&sts,WUNTRACED);
		for(i=1;i<=n;i++)
		{
			sprintf(snm,"%d",getpid()+1);
			sem_unlink(snm);
		}
	}
	else
		reader(i);
	return 0;	
}
