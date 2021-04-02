//String Palindrome
#include <stdio.h>
#include <string.h>

int main()
{
  int i,j,k,l,m;
  char a[100],b[100],c[100];
  printf("Enter the string\n");
  gets(a);
  l=strlen(a);
  for(k=0;k<l;k++)
  {
    b[l-k-1]=a[k];
  }
  b[l]='\0';
  if (strcmp (a,b)==0)
  {
    printf("The string is palindrome");
  }
  else
  {
    printf("The string is not a palindrome");
  }
}
