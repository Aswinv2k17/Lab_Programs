//SHARED MEMORY CLIENT

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/shm.h>

void main()
{
	int i,j, shmid,*shm,A[20][20],B[20][20],m,n,p,q;
	key_t key=ftok("a.c",'N');
	shmid=shmget(key,100,0666|IPC_CREAT);
	shm=(int *)shmat(shmid,0,0);
	printf("\nEnter the order of first matrix:");
	scanf("%d%d",&m,&n);
	*shm=m;
	shm++;
	*shm=n;
	shm++;
	printf("\nEnter the elements:\n");
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
		printf("A[%d][%d]=",i,j);
		scanf("%d",&A[i][j]);
		*shm=A[i][j];
		shm++;
	}
	printf("\nEnter the order of second matrix:");
	scanf("%d%d",&p,&q);
	*shm=p;
	shm++;
	*shm=q;
	shm++;
	printf("\nEnter the elements:\n");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
		{
			printf("B[%d][%d]=",i,j);
			scanf("%d",&B[i][j]);
			*shm=B[i][j];
			shm++;
	        }
}
