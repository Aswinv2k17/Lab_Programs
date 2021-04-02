//File Copy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char ch,source[25],target[25];
  FILE *source_fptr,*target_fptr;
  printf("Enter the source file name:\n");
  scanf("%s",source);
  source_fptr=fopen(source,"r");
  printf("Enter the target file name:\n");
  scanf("%s",target);
  target_fptr=fopen(target,"w+");
  if(source_fptr==NULL)
  {
    printf("NO content in source file!");
    exit(0);
  }
  while(!feof(source_fptr))
  {
    ch=getc(source_fptr);
    putc(ch,target_fptr);
  }
  printf("The contents of the target file are\n");
  printf("------------------------------------------------\n");
  rewind(target_fptr);
  while(!feof(target_fptr))
  {
    ch=getc(target_fptr);
    printf("%c",ch);
  }
  fclose(source_fptr);
  fclose(target_fptr);
}
