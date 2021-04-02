//Fibinocci Series
#include <stdio.h>

int main()
{
  int a,b,c=0,n;
  printf("Enter the limit\n");
  scanf("%d",&n);
  printf("The Fibinocci numbers are: ");
  a=0,b=1;
  printf("%d %d ",a,b);
  while (c<n)
  {
    c=a+b;
    printf("%d ",c);
    a=b;
    b=c;
  }
  printf("\n");
}
