//Sum Of Digits Of A Number
#include<stdio.h>

int main()
{
  int a,x,y,s=0;
  printf("Enter the number\n");
  scanf("%d",&a);
  while(a>0)
  {
    x=a%10;
    s=s+x;
    a=a/10;
  }
  printf("The sum of terms is %d\n",s);
}
