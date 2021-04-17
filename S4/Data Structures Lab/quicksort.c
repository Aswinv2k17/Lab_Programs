//Quicksort

#include<stdio.h>
#include<stdlib.h>
void swap(int*,int*);
void quick(int[],int,int);

void main()
{
int a[20],n,i=0;
printf("Enter the number of elements in the list\t");
scanf("%d",&n);
printf("Enter %d elements \n",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("The list before sorting is: \n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
quick(a,0,n-1);
printf("\nSorted list is :\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}

void swap(int*x,int*y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}

void quick(int a[],int l,int r)
{
int i,j,p;
if(l<r)
{
p=l;
i=l;
j=r;
while(i<j)
{
while((j>=1)&&(a[j]>a[p]))
j--;
while((i<=r)&&(a[i]<a[p]))
i++;
if(i<j)
swap(&a[i],&a[j]);
}
swap(&a[j],&a[p]);
quick(a,l,j-1);
quick(a,j+1,r);
}
}

/*
OUTPUT

Enter the number of elements in the list	5
Enter 5 elements 
20
11
10
9
7
The list before sorting is: 
20	11	10	9	7	
Sorted list is :
7	9	10	11	20	
*/
