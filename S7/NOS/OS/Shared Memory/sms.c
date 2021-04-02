//SHARED MEMORY SERVER

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/shm.h>

void main()
{
	int m1,n1,A[20][20],B[20][20],C[20][20],i,j,shmid,*shm,m2,n2;
	int k,pdt[20][20],sum,p1,p2,p3;
	key_t key=ftok("a.c",'N');
	shmid=shmget(key,100,0666|IPC_CREAT);
	shm=(int *)shmat(shmid,0,0);
	m1=*shm;
	shm++;
	n1=*shm;
	shm++;
	p2=fork();
	if(p2==0)
	{
		printf("\n first process id %d\n",getpid());
		for(i=0;i<m1;i++)
			for(j=0;j<n1;j++)
			{
				A[i][j]=*shm;
				shm++;
				printf(" A[%d][%d]=%d\t\n",i,j,A[i][j]);
			}
		printf("\n");
		m2=*shm;
		shm++;
		n2=*shm;
		shm++;
		
		for(i=0;i<m2;i++)
			for(j=0;j<n2;j++)
			{
				B[i][j]=*shm;
				shm++;
				printf(" B[%d][%d]=%d\t\n",i,j,B[i][j]);
			}
		printf("\nSum:\n");
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n1;j++)
			{
				C[i][j]=A[i][j]+B[i][j];
				printf("%d\t",C[i][j]);
			}
			printf("\n");
		}
	}
	p3=fork();
	if(p3==0)
	{
		printf("\nSecond process id:%d",getpid());
		printf("\nProduct :\n");
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n2;j++)
			{
				sum=0;
				for(k=0;k<n1;k++)
				{
					sum=sum+(A[i][k]*B[k][j]);
				}
				pdt[i][j]=sum;
				printf(" %d\t",pdt[i][j]);
			}
			printf("\n");
		}
	}
}		
