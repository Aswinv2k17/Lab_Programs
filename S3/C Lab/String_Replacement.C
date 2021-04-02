//String Replacement
#include <stdio.h>
#include <string.h>

int main()
{
  int i=0,l,j=0;
  char a[100],b[100],c[100],r[50],s[200],z;
  printf("Enter the string\n");
  gets(a);
  l=strlen(a);
  printf("Enter the word to be replaced\n");
  gets(b);
  printf("Enter the string to be replaced with\n");
  gets(r);
  strcpy(c," ");
  strcpy(s," ");
  while(i<=l)
  {
    z=a[i];
    if(z==' '||z=='\0')
    {
      c[j]='\0';
      if(strcmp(c,b)!=0)
      {
        strcat(s,c);
        strcat(s," ");
      }
      else
      {
        strcat(s,r);
        strcat(s," ");
      }
      strcpy(c," ");
      j=0;
    }
    else
    {
      c[j]=z;
      j++;
    }
    i++;
  }
  printf("The corrected string is\n %s\n",s);
}
