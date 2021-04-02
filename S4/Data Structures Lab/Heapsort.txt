//Heapsort

#include<stdio.h>
void build_heap(int,int);
void heap_sort(int);
void heap(int);
int a[20];
void main()
{
 int i,t,n;
 printf("enter the size:");
 scanf("%d",&n);
 printf("enter the elements:");
 for(i=0;i<n;i++)
  {
 scanf("%d",&a[i]);
  }
 printf("elements before sorting:\n");
 for(i=0;i<n;i++)
 {
 printf("%d\t",a[i]);
 }
 printf("\n");
 heap(n);
 heap_sort(n);
 printf("\nelements after sorting:\n");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}

void heap(int n)
{
int i;
for(i=(n/2)-1;i>=0;i--)
 {
 build_heap(i,n);
 }
}

void build_heap(int i,int n)
 {
 int l,r,max,t;
 l=(2*i)+1;
 r=(2*i)+2;
 if(l<=n-1 && a[l]>a[i])
  {
   max=l;
  }
 else
  {
   max=i;
  }
if((r<=n-1)&&(a[r]>a[max]))
 {
  max=r;
 }
 if(max!=i)
 {
  t=a[max];
 a[max]=a[i];
 a[i]=t;
 }
}

void heap_sort(int n)
{
 int i,t;
 for(i=n-1;i>=1;i--)
 {
  t=a[0];
a[0]=a[i];
a[i]=t;
n--;
heap(n);
 }
printf("\n");
}
/*OUTPUT
enter the size:5
enter the elements:11
10
7
6
-3
elements before sorting:
11	10	7	6	-3	


elements after sorting:
-3	6	7	10	11	
*/

 



