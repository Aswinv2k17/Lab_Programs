//Binary Search Using Functions
#include <stdio.h>

void search(int a[], int n);
int k;
int main()
{
  int a[50],n,i,j;
  printf("Enter the array size\n");
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the key to search\n");
  scanf("%d",&k);
  search(a,k);
}


void search(int a[], int n)
{
  int i,j,x;
  int first=0,last,mid,flag=0;
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
  last=n;
  while((first<=last)&&(flag==0))
  {
    mid=(first+last)/2;
    if(a[mid]<k)
    {
      first=mid+1;
    }
    else if(a[mid]>k)
    {
      last=mid-1;
    }
    else
    {
      flag=1;
    break;
    }
  }
  if(flag==1)
  {
    printf("The key is found\n");
  }
  else if(flag==0)
  {
    printf("Entered key not found\n");
  }
}
