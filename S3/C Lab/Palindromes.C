//Checking Palindromes
#include <stdio.h>

int main()
{
  int a,x,y=0;
  int b=0;
  printf("Enter the number\n");
  scanf("%d",&a);
  x=a;
  while(x!=0)
  {
    y=x%10;
    b=(b*10)+y;
    x=x/10;
  }
  if(a!=b)
  printf("The number is not a palindrome\n");
  else
  printf("The number is a palindrome\n");
}
