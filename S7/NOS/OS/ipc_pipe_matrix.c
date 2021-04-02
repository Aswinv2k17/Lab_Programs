//IPC PIPE MATRIX MULTIPLICATION

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int a[10][10],b[10][10],c[10][10],fd1[2],fd2[2],fd3[2],i,j,k;
	int m,n,p,q,r[10],s[10],p1,p2,p3;
	
	pipe(fd1);
	pipe(fd2);
	pipe(fd3);
	printf("Enter the order of matrix 1: ");
	scanf("%d%d",&m,&n);
	printf("Enter the elements of matrix 1:\n ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the order of matrix 2: ");
	scanf("%d%d",&p,&q);
	printf("Enter the elements of matrix 2: \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	write(fd1[1],&m,sizeof(m));
	write(fd1[1],&n,sizeof(n));
	write(fd1[1],a,sizeof(a));
	write(fd1[1],&p,sizeof(p));
	write(fd1[1],&q,sizeof(q));
	write(fd1[1],b,sizeof(b));
	close(fd1[1]);
	
	p1=fork();
	if(p1==0)
	{
		int a1[10][10],b1[10][10],c[10][10];
		int m1,n1,p1,q1;
		read(fd1[0],&m1,sizeof(m1));
		read(fd1[0],&n1,sizeof(n1));
		read(fd1[0],a1,sizeof(a1));
		read(fd1[0],&p1,sizeof(p1));
		read(fd1[0],&q1,sizeof(q1));
		read(fd1[0],b1,sizeof(b1));
		close(fd1[0]);
		
		printf("Child Process 1 for multiplication ");
		printf("\nProcess Id of child process 1: %d",getpid());
		printf("\nMatrix 1:\n");
		for(i=0;i<m1;i++)
		{
			for(j=0;j<n1;j++)
			{
				printf("%d\t",a1[i][j]);
			}
			printf("\n");
		}
		printf("\nMatrix 2:\n");
		for(i=0;i<p1;i++)
		{
			for(j=0;j<q1;j++)
			{
				printf("%d\t",b1[i][j]);
			}
			printf("\n");
		}
		
		if(n1==p1)
		{
			for( i=0;i<m1;i++)
			{
				for( j=0;j<n1;j++)
				{
					c[i][j]=0;
					for( k=0;k<q1;k++)
					{
						c[i][j]+=a1[i][k]*b1[k][j];
					}
				}
			}
		}
		else
		{
			printf("Cannot multiply the matrices");
			exit(0);
		}
		
		write(fd2[1],&m1,sizeof(m1));
		write(fd2[1],&q1,sizeof(q1));
		write(fd2[1],c,sizeof(c));
		close(fd2[1]);
	}
	else
	{
		p2=fork();
		if(p2==0)
		{
			int c2[10][10],m2,q2;
			
			read(fd2[0],&m2,sizeof(m2));
			read(fd2[0],&q2,sizeof(q2));
			read(fd2[0],c2,sizeof(c2));
			close(fd2[0]);
			
			printf("Child Process 2 to display product ");
			printf("\nProcess Id of child process 2: %d",getpid());
			printf("\nProduct: \n");
			for( i=0;i<m2;i++)
			{
				for( j=0;j<q2;j++)
				{
					printf("%d\t",c2[i][j]);
				}
				printf("\n");
			}
			write(fd3[1],&m2,sizeof(m2));
			write(fd3[1],&q2,sizeof(q2));
			write(fd3[1],c2,sizeof(c2));
			close(fd3[1]);
			
			p3=fork();
			if(p3==0)
			{
				int c3[10][10],s[10],r[10],m3,q3;
				
				read(fd3[0],&m3,sizeof(m3));
				read(fd3[0],&q3,sizeof(q3));
				read(fd3[0],c3,sizeof(c3));
				close(fd3[0]);
				
				printf("Child Process 3 to display row sum ");
				printf("\nProcess Id of child process 3: %d",getpid());
				for( i=0;i<m3;i++)
				{
					r[i]=0;
					for( j=0;j<q3;j++)
					{
						r[i]=r[i]+c3[i][j];
					}
				}
				printf("\nRow-sum: ");
				for( i=0;i<m3;i++)
					printf("%d\t",r[i]);
				
				for( i=0;i<q3;i++)
				{
					s[i]=0;
					for( j=0;j<m3;j++)
					{
						s[i]+=c3[j][i];
					}
				}
				printf("\ncolumn sum: ");
				for( i=0;i<q3;i++)
					printf("%d\t",s[i]);	
			}
		}
	}
}

/*OUTPUT
Enter the order of matrix 1: 2 2
Enter the elements of matrix 1:
 1
2
3
4
Enter the order of matrix 2: 2 2
Enter the elements of matrix 2: 
1
2
3
4
Child Process 1 for multiplication 
Process Id of child process 1: 3414
Matrix 1:
1	2	
3	4	

Matrix 2:
1	2	
3	4	
Child Process 2 to display product 
Process Id of child process 2: 3415
Product: 
7	10	
15	22	
Child Process 3 to display row sum 
Process Id of child process 3: 3416
Row-sum: 17	37	
column sum: 22	32	*/
