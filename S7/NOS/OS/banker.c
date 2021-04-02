//Banker's Algorithm

#include<stdio.h>
struct banker
{
	int alloc[3],max[3],nd[3],flag;
}p[10];

void main()
{
	int pn,j,i,av[3],c=0,k=0,s[50];
	printf("Enter no of processess: ");
	scanf("%d",&pn);
	printf("Enter allocation of resource a,b,c for processes:\n");
	for(i=0;i<pn;i++)
	{
		p[i].flag=0;
		printf("Process %d :",i+1);
		scanf("%d%d%d",&p[i].alloc[0],&p[i].alloc[1],&p[i].alloc[2]);
	}
	printf("Enter max allocation of resource a,b,c for processes:\n");
	for(i=0;i<pn;i++)
	{
		printf("Process %d :",i+1);
		scanf("%d%d%d",&p[i].max[0],&p[i].max[1],&p[i].max[2]);
	}
	printf("Enter available resource a,b,c for processes:\n");
	scanf("%d%d%d",&av[0],&av[1],&av[2]);
	printf("Allocation of resource a,b,c for processes:\n");
	for(i=0;i<pn;i++)
	{
		printf("Process %d :",i+1);
		printf("%d\t%d\t%d\t\n",p[i].alloc[0],p[i].alloc[1],p[i].alloc[2]);
	}
	printf("Max allocation of resource a,b,c for processes:\n");
	for(i=0;i<pn;i++)
	{
		printf("Process %d :",i+1);
		printf("%d\t%d\t%d\t\n",p[i].max[0],p[i].max[1],p[i].max[2]);
	}
	printf("Available resource a,b,c for processes:\n");
	printf("%d\t%d\t%d\t",av[0],av[1],av[2]);
	for(i=0;i<pn;i++)
	{
		p[i].nd[0]=p[i].max[0]-p[i].alloc[0];
		p[i].nd[1]=p[i].max[1]-p[i].alloc[1];
		p[i].nd[2]=p[i].max[2]-p[i].alloc[2];
	}
	printf("\nNeed of resources a,b,c for processes:\n");
	for(i=0;i<pn;i++)
	{
		printf("Process %d :",i+1);
		printf("%d\t%d\t%d\t",p[i].nd[0],p[i].nd[1],p[i].nd[2]);
		printf("\n");
	}
	for(j=0;j<pn;j++)
	{
		for(i=0;i<pn;i++)
		{
			if(p[i].flag==0)
			{
				if((p[i].nd[0]<=av[0])&&(p[i].nd[1]<=av[1])&&(p[i].nd[2]<=av[2]))
				{
					printf("\nProcess %d allocated",i+1);
					printf("\nNEED: %d\t%d\t%d\t",p[i].nd[0],p[i].nd[1],p[i].nd[2]);
					printf("\nAvailable: %d\t%d\t%d\t",av[0],av[1],av[2]);
					av[0]=av[0]+p[i].alloc[0];
					av[1]=av[1]+p[i].alloc[1];
					av[2]=av[2]+p[i].alloc[2];
					p[i].flag=1;
					c++;
					s[k++]=i+1;
				}
			}
		}
	}
	if(c==pn)
	{
		printf("\nSafe sequence of processes:");
		for(i=0;i<pn-1;i++)
		printf("P%d -> ",s[i]);
		printf("P%d",s[i]);
	}
	else
	printf("\nUnsafe");
}

/*OUTPUT
=========

Enter no of processess: 5
Enter allocation of resource a,b,c for processes:
Process 1 :0 1 0
Process 2 :2 0 0
Process 3 :3 0 2
Process 4 :2 1 1
Process 5 :0 0 2
Enter max allocation of resource a,b,c for processes:
Process 1 :7 5 3
Process 2 :3 2 2
Process 3 :9 0 2
Process 4 :2 2 2
Process 5 :4 3 3
Enter available resource a,b,c for processes:
3 3 2
Allocation of resource a,b,c for processes:
Process 1 :0    1       0
Process 2 :2    0       0
Process 3 :3    0       2
Process 4 :2    1       1
Process 5 :0    0       2
Max allocation of resource a,b,c for processes:
Process 1 :7    5       3
Process 2 :3    2       2
Process 3 :9    0       2
Process 4 :2    2       2
Process 5 :4    3       3
Available resource a,b,c for processes:
3       3       2
Need of resources a,b,c for processes:
Process 1 :7    4       3
Process 2 :1    2       2
Process 3 :6    0       0
Process 4 :0    1       1
Process 5 :4    3       1

Process 2 allocated
NEED: 1 2       2
Available: 3    3       2
Process 4 allocated
NEED: 0 1       1
Available: 5    3       2
Process 5 allocated
NEED: 4 3       1
Available: 7    4       3
Process 1 allocated
NEED: 7 4       3
Available: 7    4       5
Process 3 allocated
NEED: 6 0       0
Available: 7    5       5
Safe sequence of processes:P2 -> P4 -> P5 -> P1 -> P3 
*/

