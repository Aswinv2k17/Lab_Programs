//First and Follow

#include<stdio.h>
#include<string.h>
#include<malloc.h>

char nonTerminal[10];
char prod[30][10]={"E->TX","X->+TX","X->e","T->FY","Y->*FY","Y->e","F->i","F->(E)"};
char FIRST[30][30],FOLLOW[30][30];

int isTerminal(char a)
{
 int i;
for(i=0;i<strlen(nonTerminal);i++)
{
 if(nonTerminal[i]==a)
 {
 return 0;
 }
}
 return 1;
}

int isDuplicate(char *str,char a)
{
 int i;
 for(i=0;i<strlen(str);i++)
 {
   if(str[i]==a)
       return 1;
 }
 return 0;
}

char * fst(char NT)
{
 char *first=malloc(30);
 int k=0,i,j;
 strcpy(first,"\0");
 for(i=0;i<8;i++)
 {
  if(prod[i][0]==NT)
  {
    if(isTerminal(prod[i][3]))
    {
     first[k++]=prod[i][3];
     first[k]='\0';
    }
   else
   {
     strcat(first,fst(prod[i][3]));
   }
  }
}
 return first;
}

char * fol(char NT)
{
 char *follow=malloc(30);
 int k=0,i,j,x,y;
 strcpy(follow,"\0");
 for(i=0;i<8;i++)
 {
   for(j=3;j<strlen(prod[i]);j++)
   {
     if(prod[i][j]==NT)
     {
       if(prod[i][j+1]=='\0')
       {
         if(prod[i][0]!=NT)
         {
           strcat( follow,fol(prod[i][0]));
         }
      }
    else if(isTerminal(prod[i][j+1]))
      {
         follow[k++]=prod[i][j+1];
         follow[k]='\0';
      }
  else
  {
    k=strlen(follow);
    for(x=0;x<8;x++)
    {
     if(FIRST[x][0]==prod[i][j+1])
     {
      for(y=1;y<strlen(FIRST[x]);y++)
      {
       if(FIRST[x][y]=='e')
       {
       if(prod[i][j+2]=='\0')
      {
       if(prod[i][0]!=NT)
       {
         strcat(follow,fol(prod[i][0]));
       }
    }
  else if(isTerminal(prod[i][j+2]))
  {
   follow[k++]=prod[i][j+2];
   follow[k]='\0';
  }
}
 
 else      
  {
   follow[k++]=FIRST[x][y];
   follow[k]='\0';
   }}
 }}
 }}
}
}

  if(NT=='E')
  strcat(follow,"$");
  return follow;
 }
char * removeDup(char FOLLOW[30])
{
 int i,j=0,flag,len;
 char *follow=malloc(30);
 follow[0]=FOLLOW[0];
 follow[1]='\0';
 for(i=1;i<strlen(FOLLOW);i++)
 {
   len=strlen(follow);
   flag=0;
   for(j=0;j<len;j++)
   {
    if(follow[j]==FOLLOW[i])
    {
      flag =1;
      break;
   }
  }
 if(flag==0)
 {
  follow[len++]=FOLLOW[i];
  follow[len]='\0';
 }
}
return follow;
}
void main()
{
 int i,j=0;
char first[30];
char follow[30];
for(i=0;i<8;i++)
{
if(! isDuplicate(nonTerminal,prod[i][0]))
{
 nonTerminal[j++]=prod[i][0];
 nonTerminal[j]='\0';
 }
}
printf("Non-Terminals=%s\n",nonTerminal);
for(i=0;i<strlen(nonTerminal);i++)
 {
 FIRST[i][0]=nonTerminal[i];
 FIRST[i][1]='\0';
 strcpy(first,fst(nonTerminal[i]));
 strcat(FIRST[i],first);
 }
for(i=0;i<strlen(nonTerminal);i++)
{
 printf("FIRST(%c)=",FIRST[i][0]);
 for(j=1;j<strlen(FIRST[i]);j++)
 {
  printf("%c\t",FIRST[i][j]);
  }
 printf("\n");
}
 for(i=0;i<strlen(nonTerminal);i++)
 {
  FOLLOW[i][0]=nonTerminal[i];
  FOLLOW[i][1]='\0';
  strcpy(follow,fol(nonTerminal[i]));
  strcat(FOLLOW[i],removeDup(follow));
 }
 for(i=0;i<strlen(nonTerminal);i++)
 {
  printf("FOLLOW(%c)=",FOLLOW[i][0]);
  for(j=1;j<strlen(FOLLOW[i]);j++)
  {
   printf("%c\t",FOLLOW[i][j]);
  }
 printf("\n");
}
}

OUTPUT
=======
Non-Terminals=EXTYF
FIRST(E)=i	(	
FIRST(X)=+	e	
FIRST(T)=i	(	
FIRST(Y)=*	e	
FIRST(F)=i	(	
FOLLOW(E)=)	$	
FOLLOW(X)=)	$	
FOLLOW(T)=+	)	$	
FOLLOW(Y)=+	)	$	
FOLLOW(F)=*	+	)	$	
