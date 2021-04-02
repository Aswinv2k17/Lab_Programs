//Addition Of Two Matrix Using Functions
#include<stdio.h>
#include<string.h>

int add(int A[][10], int B[][10]);
int main()
{
	int i=0,j=0,k,l,a,b,c,d,s=0;
	printf("Enter the order of Matrices\n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	int A[a][b],B[c][d];
	printf("Enter the elements of first matrix\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	printf("\n");
	printf("Enter the elements of second matrix\n");
	for(i=0;i<c;i++)
	{
		for(j=0;j<d;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	printf("\n");
	add(A,B);
}


int add(int A[10][10], int B[10][10])
{
	int i=0,j=0,k,l,m,n,a,b,c,d,s=0;
	int C[a][b],D[a][d];
	if((a==c)&&(b==d))
	{
		for(i=0;i<c;i++)
		{
			for(j=0;j<d;j++)
			{
				C[i][j]=A[i][j]+B[i][j];
				printf("%d ",C[i][j]);
			}
		printf("\n");
		}
	}
	else
	{
		printf("The matrices are of different order\n");
	}
	if(b==c)
	{
		for(i=0;i<a;i++)
		{
			for(k=0;k<d;k++)
			{
				for(j=0;j<d;j++)
				s+=A[i][j]*B[j][k];
				D[i][k]=s;
				s=0;
			}
		}
	}
	printf("The product is =\n");
	for(m=0;m<a;m++)
	{
		for(n=0;n<d;n++)
		{
			printf("%d ",D[m][n]);
		}
		printf("\n");
	}
}
