//Substring Search and Deletion

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()

{
	
	char str[50],str1[50];
	
	int l1,loc,b,x,pos,c,i,k=0,l,flag,j,a[50],z=0;
	
	printf("\n Enter the main string\n");
		
	gets(str);
	

	printf("\n Enter the substring you want to search and delete\n");

	gets(str1);

	l=strlen(str1);

	for(i=0;str[i]!='\0';i++)

	{

		if(str[i]==str1[0])

		{

			k=i+1;j=1;

			if(str[k]==str1[j])

			{	
				
				while(l>=j)

				{
	
					if(l==j+1)

					{

						flag=1;

						loc=k-j;

						a[z]=loc;

						printf("\n String found at location %d ",loc+1);

						z++;

					}

					k++;j++;

				}

			}

		}

	}

	printf("\n Substring deletion...New string is \n");
	pos=0;
	for(x=0;a[x]!=0;x++)
	{
		for(i=pos;i<a[x]-1;i++)
			printf("%c",str[i]);
		pos=a[x]+strlen(str1);	
	}
	for(i=pos;str[i]!='\0';i++)
		printf("%c",str[i]);
	getch();
}

/*OUTPUT:
Enter the main string
iam what iam
Enter the substring you want to search and delete
what
String found at location 5
Substring deletion...New string is
iam iam   */











