//FORK STRING
//S7 CSE

#include<stdio.h>
#include<string.h>
#include<unistd.h>
void rev(char str[10][10],int n);
void sor(char str[10][10],int n);
void main()
{
  char str[10][10];
  int i=0,j=0,n,p;
  printf("Enter the no. of strings\t");
  scanf("%d",&n);
  printf("Enter the strings\n");
  for(i=0;i<n;i++)
	{
	    scanf("%s",str[i]);
	}
 p=fork();
 if(p==0)
 {
   printf("\tCHILD PROCESSES\n");
   rev(str,n);
 }
 else
 {
   printf("\tPARENT PROCESSES\n");
   sor(str,n);
 }
}

  
void rev(char str[10][10],int n)
{
 printf("Reversed String\n");
  for(int i=0;i<n;i++)
  {
     for(int j=strlen(str[i]);j>-1;j--)
	{
	    printf("%c",str[i][j]);
	}
	 printf("\n");
  }
}

void sor(char str[10][10],int n)
{
  for(int i=0;i<n-1;i++)
  {
	 for(int j=i+1;j<n;j++)
	{
	 if(strcmp(str[i],str[j])>0)
	 {
	  char temp[10];
	  strcpy(temp,str[i]);
	  strcpy(str[i],str[j]);
	  strcpy(str[j],temp);
	}
      }
  }
 printf("Sorted String\n");
      for(int i=0;i<n;i++)
	{
	    printf("%s\n",str[i]);
	}
}


/*OUTPUT
----------
Enter the no. of strings   3
Enter the strings
red
orange
blue

	PARENT PROCESSES
Sorted String
blue
orange
	CHILD PROCESSES
red
Reversed String
der
egnaro
eulb
*/

