//Sparse matrix

#include<stdio.h>
#include<conio.h>
void main()
{
	int b[100][100],b1[100][3],b2[100][3],b3[100][3],b4[100][3];
	int m,n,i,j,c1,c2,c4,temp,k,o,flag,q,r,c,e,f,ch,w;
	clrscr();
	printf("\nEnter the order of first matrix and no. of non-zero elements");
	printf("\nr c e\n");
	scanf("%d%d%d",&m,&n,&c1);
	printf("\nEnter the elements in 3 tuple representstion\n");
	b1[0][0]=m;
	b1[0][1]=n;
	b1[0][2]=c1;
	for(i=1;i<=c1;i++)
	{
		scanf("%d%d%d",&b1[i][0],&b1[i][1],&b1[i][2]);
	}
	printf("\nPress 1 if you want to perform sparse matrix addition");
	scanf("%d",&q);
	if(q==1)
	{
		printf("\nEnter the order of first matrix and no. of non-zero elements");
		printf("\nr c e\n");
		scanf("%d%d%d",&m,&n,&c2);
		printf("\nEnter the elements in 3 tuple representstion\n");
		b2[0][0]=m;
		b2[0][1]=n;
		b2[0][2]=c2;
		for(i=1;i<=c2;i++)
		{
			scanf("%d%d%d",&b2[i][0],&b2[i][1],&b2[i][2]);
		}
	}
	while(1)
	{
		printf("\n1.Sparse matrix addition\n2.Sparse matrix transpose\n3.Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:i=1;j=1;k=1;
				if((b1[0][0]==b2[0][0])&&(b1[0][1]==b2[0][1]))
				{
					flag=1;
				}
				if(flag==0)
				{
					printf("\n Addition not possible");
					exit(0);
				}
				b3[0][0]=b1[0][0];
				b3[0][1]=b1[0][1];
				while((i<=c1)&&(j<=c2))
				{
					if(b1[i][0]==b2[j][0])
					{

						b3[k][0]=b1[i][0];
						b3[k][1]=b1[k][1];
						b3[k][2]=b1[i][2]+b2[j][2];
						k++;j++;i++;
					}
					else if(b1[i][1]<b2[j][1])
						{
							b3[k][0]=b1[i][0];
							b3[k][1]=b1[i][1];
							b3[k][2]=b1[i][2];
							k++;i++;
						}
					else if(b1[i][1]>=b2[j][1])
						{
							b3[k][0]=b2[j][0];
							b3[k][1]=b2[j][1];
							b3[k][2]=b2[j][2];
							k++;j++;
						}

					else if(b1[i][0]<b2[j][0])
					{
						b3[k][0]=b1[i][0];
						b3[k][1]=b1[i][1];
						b3[k][2]=b1[i][2];
						k++;i++;
					}
					else
					{
						b3[k][0]=b1[j][0];
						b3[k][1]=b1[j][1];
						b3[k][2]=b1[j][2];
						k++;j++;
					}
			       }
			while(i<=c1)
			{
				b3[k][0]=b1[i][0];
				b3[k][1]=b1[i][1];
				b3[k][2]=b1[i][2];
				k++;i++;
			}
			while(j<=c2)
			{
				b3[k][0]=b1[j][0];
				b3[k][1]=b1[j][1];
				b3[k][2]=b1[j][2];
				k++;j++;
			}
			b3[0][2]=k-1;
			printf("\nResultant sparse in 3 tuple representation");
			printf("\nr\tc\te\n");
			printf("%d\t%d\t%d\n",b3[0][0],b3[0][1],b3[0][2]);
			for(i=1;i<k;i++)
				printf("\n%d\t%d\t%d\n",b3[i][0],b3[i][1],b3[i][2]);
			break;
		case 2:b4[0][0]=b1[0][1];
			b4[0][1]=b1[0][0];
			b4[0][2]=b1[0][2];
			k=1;
			n=b1[0][2];
			for(i=0;i<=b1[0][1];i++)
			{
				for(j=1;j<=n;j++)
				{
					if(i==b1[j][1])
					{
						b4[k][0]=i;
						b4[k][1]=b1[j][0];
						b4[k][2]=b1[j][2];
						k++;
					}
				}
			}
			printf("\nResultant transposed sparse in 3 tuple representation");
			printf("\nr\tc\te\n");
			printf("%d\t%d\t%d\n",b4[0][0],b4[0][1],b4[0][2]);
			for(i=1;i<k;++i)
				printf("\n%d\t%d\t%d",b4[i][0],b4[i][1],b4[i][2]);
			break;
		case 3:exit(0);
			break;
		default:printf("\nNo such option");
		}
	}
	getch();
}
/*
OUTPUT:
Enter the order of first matrix and no. of non-zero elements
r c e
3 3 3

Enter the elements in 3 tuple representstion
1 0 2
2 1 3
3 2 4

Press 1 if you want to perform sparse matrix addition
1

Enter the order of first matrix and no. of non-zero elements
r c e
3 3 3

Enter the elements in 3 tuple representstion
1 0 4
2 1 7
3 2 3

1.Sparse matrix addition
2.Sparse matrix transpose
3.Exit1

Resultant sparse in 3 tuple representation
r       c       e
3       3       3

1       0       6

2       1       10

3       2       7

1.Sparse matrix addition
2.Sparse matrix transpose
3.Exit2

Resultant transposed sparse in 3 tuple representation
r       c       e
3       3       3

0       1       2
1       2       3
2       3       4
1.Sparse matrix addition
2.Sparse matrix transpose
3.Exit3
