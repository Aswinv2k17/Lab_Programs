//User Defined String Functions
#include <stdio.h>

int strle(char[]);
void strev(char[],int);
void strca(char[],int,char[],int);
char s1[50],s2[50];
int l2,l1;
int main()
{
  int i,j;
  printf("Enter the first string\n");
  gets(s1);
  l2=strle(s1);
  printf("Enter the second string\n");
  gets(s2);
  l1=strle(s2);
  strca(s1,l2,s2,l1);
  strev(s1,l2);
  strev(s2,l1);
}

int strle(char x[])
{
  int i=0;
  while(x[i]!='\0')
  {
    i++;
  }
  printf("The length of string is %d\n",i);
  return(i);
}


void strev(char x[],int y)
{
  int i=0,j,l3;
  char a[15];
  for(j=y-1;j>=0;j--)
  {
    a[i]=x[j];
    i++;
  }
  a[i]='\0';
  printf("Reversed string is %s\n",a);
}

void strca(char x[],int y,char r[],int s)
{
  int i,j=0;
  char d[50];
  s=l1+l2+1;
  for (i=0;s1[i]!='\0';i++)
  {
    d[i]=x[i];
  }
  for (j=0;s2[j]!='\0';j++)
  {
    d[i]=r[j];
    i++;
  }
  printf("The concatenated string is %s\n",d);
}
