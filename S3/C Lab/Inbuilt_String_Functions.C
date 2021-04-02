//Inbuilt String Functions
#include <stdio.h>
#include <string.h>

int main()
{
  int i=0,j=0,k,l;
  char a[100],b[100],c[100],d[100],e[100];
  printf("Enter the first string\n");
  gets(a);
  k=strlen(a);
  printf("Enter the second string\n");
  gets(b);
  l=strlen(b);
  strcpy(c,a);
  strcpy(e,a);
  strcpy(d,b);
  strcat(e,b);
  printf("The length of first string = %d \n",k);
  printf("The length of second string = %d \n",l);
  printf("The concatenated string is %s\n",e);
  printf("The first string is %s\n",c);
  printf("The second string is %s\n",d);
  if(strcmp (a,b)==0)
  {
    printf("The strings are same\n");
  }
  else
  {
    printf("The strings are different\n");
  }
}
