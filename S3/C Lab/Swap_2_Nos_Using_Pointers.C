//Swap Two Numbers Using Pointers
#include <stdio.h>

int main()
{
  int a,b;
  void swap(int *x,int *y);
  printf("\n Enter the two numbers\n");
  scanf("%d%d",&a,&b);
  printf("Before function call a=%d, b=%d \n",a,b);
  swap(&a,&b);
  printf("After function call a=%d, b=%d \n",a,b);
}

void swap(int *x,int*y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
