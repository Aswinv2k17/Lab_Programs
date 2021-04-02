//Bubble Sort Using Functions
#include <stdio.h>

int main()
{
  int sort(int a[50],int n);
  int a[50],n,i,j;
  printf("Enter array limit\n");
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  sort(a,n);
}

int sort(int a[50], int n)
{
  int i,j,x;
  for(i=0;i<n;i++)
  {
    for(j=0;j<(n-i-1);j++)
    {
      if(a[j]>=a[j+1])
      {
        x=a[j];
        a[j]=a[j+1];
        a[j+1]=x;
      }
    }
  }
  printf("The sorted array = \n");
  for(i=0;i<n;i++)
  {
    printf("%d \t",a[i]);
  }
}
