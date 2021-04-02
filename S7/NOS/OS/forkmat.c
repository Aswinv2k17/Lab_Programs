//FORK MATRIX
//S7 CSE

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
  int a[3][3],i,j,m=3,n=3,p2,p3;
  printf("Enter the elements of matrix\t");
  for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	  {
	    scanf("%d",&a[i][j]);
	  }
	}
  for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	  {
	    printf("%d\t",a[i][j]);
	  }
	 printf("\n");
	}
 p2=fork();
 
 if(p2==0)
 {
   int b[3][3]={1,2,3,4,5,6,7,8,9},sum[3][3];
   printf("Process P2\n");
   printf("Process id: %d\n",getpid());
   printf("Parent id: %d\n",getpid());
   printf("Addition of Matrix\n");
   for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	  {
	    sum[i][j]=a[i][j]+b[i][j];
	  }
	}
   for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	  {
	    printf("%d\t",sum[i][j]);
	  }
	 printf("\n");
	}
 }
 else
 {
  p3=fork();

  if(p3==0)
  {
   int c[3][3]={1,2,3,4,5,6,7,8,9},diff[3][3];
   printf("Process P3\n");
   printf("Process id: %d\n",getpid());
   printf("Parent id: %d\n",getpid());
   printf("Subtraction of Matrix\n");
   for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	  {
	    diff[i][j]=a[i][j]-c[i][j];
	  }
	}
   for(i=0;i<3;i++)
	{
	 for(j=0;j<3;j++)
	  {
	    printf("%d\t",diff[i][j]);
	  }
	 printf("\n");
	}
   }
 }
}
