//Merging Of Two Arrays
#include <stdio.h>

int main()
{
  int i,j,k,l,g;
  int a[50],b[50];
  int c[100];
  printf("Enter the limit of first array\n");
  scanf("%d",&l);
  printf("Enter the array elements\n");
  for(i=0;i<l;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the limit of second array\n");
  scanf("%d",&k);
  printf("Enter the array elements\n");
  for(j=0;j<k;j++)
  {
    scanf("%d",&b[j]);
  }
  for(i=0;i<l+1;i++)
  {
    c[i]=a[i];
    g=i;
  }
  for(j=0;j<k;j++)
  {
    c[g]=b[j];
    g++;
  }
  printf("The merged array is \n");
  for(i=0;i<(l+k);i++)
  {
    printf("%d ",c[i]);
  }
}
