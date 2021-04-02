//Display The File Content
#include <stdio.h>

int main()
{
  char ch,c;
  FILE *fp,*fq;
  fp=fopen("EXAMPLE.TXT","w");
  printf("\n Type the text...Press enter key at the end\n");
  while((ch=getchar())!='\n');
  putc(ch,fp);
  fclose(fp);
  fq=fopen("EXAMPLE.TXT","r");
  while(!feof(fq))
  {
    c=getc(fq);
    printf("%c",c);
  }
  fclose(fq);
}
