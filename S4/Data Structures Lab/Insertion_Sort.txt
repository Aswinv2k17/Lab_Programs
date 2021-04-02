//Insertion Sort

#include<stdio.h>
 void sort( int [],int);
 int array[50],n,i,j,x;
 void main()
{
 printf("enter the size of the array");
 scanf("%d",&n);
 printf("\n enter the elements :");
 
for(i=0;i<n;i++)
{ 
 scanf("%d",&array[i]);
}


 printf("sorted list in ascending order \n");

for(i=0;i<=n-1;i++)
{
 printf("%d\n",array[i]);
 }

}
 void sort (int array[], int n)
{
 for(i=1;i<n;i++)
{
 j=i-1;
 x=array[i];
 while(j>=0 && x < array[j])
{

 array[j+1]= array[j];
 j--;
  }
 array[j+1]=x;
for(i=0;i<n;i++)
{printf("%d",array[i]);
}
}
}

//OUTPUT

 /*enter the size of the array5

 enter the elements :8
99
13
2
7
sorted list in ascending order 
2
7
8
13
99
*/
