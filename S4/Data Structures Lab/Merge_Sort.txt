//Merge Sort

  #include<stdlib.h>
  #include<stdio.h>
  void mergesort(int [],int ,int );
  void merge(int [],int ,int, int, int );
  int main()
	{
	int a[50],n,l;
	printf("Enter the limit\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(l=0;l<n;l++)
		scanf("%d",&a[l]);
	printf("The unsorted array is:");
	{
	for( l=0;l<n;l++)
		printf("%d \t",a[l]);
	}
	mergesort(a,0,n-1);
	printf("\nThe sorted array  is:");
	for(l=0;l<n;l++)
		printf(" %d \t",a[l]);
	}
	void mergesort(int a[],int l,int r)
	{
	int mid;
	if(l<r)
	{
	mid=((l+r)/2);
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
     	merge(a,l,mid,mid+1,r);
	}
	}
	void merge(int a[],int l1,int r1,int l2,int r2)
	{
	int temp[100];
	int l,r,k;
	l=l1;
	r=l2;
	k=0;
	{
	while(l<=r1 && r<=r2)
	{
	if(a[l]<a[r])
	temp[k++]=a[l++];
	else
	temp[k++]=a[r++];
	}
	while(l<=r1)
	temp[k++]=a[l++];
	while(r<=r2)
	temp[k++]=a[r++];
	}
	for(l=l1,r=0;l<=r2;l++,r++)
	a[l]=temp[r];
         
	}
/*OUTPUT
Enter the limit
5
Enter the array elements
7
5
3
9
1
The unsorted array is:7 	5 	3 	9 	1 	
The sorted array  is :1	        3       5       7 	9 	*/

