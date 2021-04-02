//Factorial Using Recursion
#include<stdio.h>

int fact(int n);
int num;
int main()
{
  printf("Enter the number\n");
  scanf("%d",&num);
  int result= fact(num);
  printf("The factorial of %d is %d\n",num,result);
}

int fact(int n)
{
  if(n>0)
  {
    return (n*fact(n-1));
  }
  else
  {
    return 1;
  }
}
