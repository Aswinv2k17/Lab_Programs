//Count The Number Of Vowels In A File
#include<stdio.h>
#include<ctype.h>

int main()
{
  char ch;
  int count=0;
  FILE *fp;
  fp=fopen("EXAMPLE.TXT","r");
  printf("\n The contents of the text file is:\n\n");
  while(!feof(fp))
  {
    ch=getc(fp);
    printf("%c",ch);
    switch(toupper(ch))
    {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':count++;
      break;
    }
  }
  printf("\n\n Number of vowels present = %d",count);
  fclose(fp);
}
