//Prime Number Series
#include <stdio.h>

int main()
{
  int a,d,i,j,n;
  printf("Enter the limit\n");
  scanf("%d",&n);
  printf("The prime numbers are:\n");
  for(i=2;i<n;i++)
  {
    d=0;
    for(j=2;j<i;j++)
    {
      if(i%j==0)
      {
      d=1;
      break;
      }
    }
    if(d==0)
    printf("%d\n",i);
  }
}
