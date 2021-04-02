//Sum Of Diagonal Elements, Upper Triangular & Lower Triangular Matrix
#include <stdio.h>
#include <string.h>

int main()
{
  int i,j,k,n,m,o,p,x,y,u=0,l=0,d=0,q=0;
  int A[m][n];
  printf("Input the Matrix Size\n");
  scanf("%d",&m);
  scanf("%d",&n);
  printf("Enter the matrix elements\n");
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&A[i][j]);
    }
  }
  printf("\n");
  for(k=0;k<m;k++)
  {
    for(l=0;l<n;l++)
    {
      if(k==l||(k+l==(m-1)))
        d=d+A[k][l];
    }
  }
  printf("Sum of diagonal elements is %d\n",d);
  for(o=0;o<m;o++)
  {
    for(p=0;p<n;p++)
    {
      if(o<=p)
        u=u+A[o][p];
    }
  }
  printf("Sum of upper triangular elements is %d\n",u);
  for(x=0;x<m;x++)
  {
    for(y=0;y<n;y++)
    {
      if(x>=y)
        q=q+A[x][y];
    }
  }
  printf("Sum of lower triangular elements is %d\n",q);
}
