//Counting The Positive, Negative, Odd & Even Numbers In An Array
#include<stdio.h>

int main()
{
  int n=0;
  int a[50];
  int l,p=0,e=0,o=0;
  int i,j;
  printf("Enter the array limit\n");
  scanf("%d",&l);
  printf("Enter the array elements\n");
  for(i=0;i<l;i++)
  {
    scanf("%d",&a[i]);
  }
  for(j=0;j<l;j++)
  {
    if(a[j]>0)
    p++;
    if(a[j]<0)
    n++;
    if(a[j]%2==0)
    e++;
    if(a[j]%2!=0)
    o++;
  }
  printf("The number of positive integers= %d\n",p);
  printf("The number of negative integers= %d\n",n);
  printf("The number of odd integers= %d\n",o);
  printf("The number of even integers= %d\n",e);
}
