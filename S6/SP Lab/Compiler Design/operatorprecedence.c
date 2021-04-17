#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char ffun[20][20],gfun[20][20];
int ifcount=0,igcount=0;
char oprtab[20][20];
 int getprecedence(char a, char b)
{
	int i,fvaluse,gvalue;
	char *temp;
	for(i=0;i<stelen(ffun[0];i++)
	{
		if(ffun[0][i]==a)
		{
		temp[0]=ffun[1][i];
		temp[1]='\0';
		fvalue=atoi(temp);
		}
	}
	for(i=0;i<stelen(gfun[0];i++)
	{
		if(gfun[0][i]==a)
		{
		temp[0]=gfun[1][i];
		temp[1]='\0';
		gvalue=atoi(temp);
		}
	}

	if(gvalue==0&&fvalue==0)
	{
	return -1;
	}
	if(gvalue<fvalue)
	{
	return 1;
	}
	if(gvalue>fvalue)
	{
	return 2;
	}
	return -1;
}


char check(char a,char b)
	{
	int icount,icount1;
	for(icount=1;icount<stelen(oprtab[0]);icount++)
		{
		if(oprtab[icount][0]==a)
			{
			fpr(icount1=1;icount1<strlen(oprtab[0]);icount1++)
			if(oprtab[0][icount1]==b)
				{
				return oprtab[icount]icount1];
				}
			}
		}
	}return '\0';
	


void parser(char string[])
	{
	char stack[30],top=0,icount,stacktop;
	strcpy(stack,"$");
	for(icount=0;icount<strlen(string);icount++)
		{
		if(stack[top]=='$'&&string[icount=='$')
			{
			printf("the string is accepted\n");
			return;
			}

		if(check(stack[top],string[icount])=='>')
			{
			stacktop=stack[top];
			stack[top--]='\0';
			while(check(stack[top],stacktop)!=
				{
				stacktop=stack[top];
				stack[top--]='\0';

				}
			icount--;
			}
		else
			{
			stack[++top]=string[icount];
			stack[top+1]='\0';
			printf("stack:%s\n",stack);
			}
		}
	printf("the string is not accepetd");
}


 int main()
	{
	 FILE *predtab,*opertab;
	char string[30];
	int icount,icount1,preval;
	predtav=fopen("predtab.txt","r");
	fscanf(predtab,"%s",string);
	strcpy(ffun([ifcount++],string);
	strcpy(gfun[igcount++],string);
	while(!feof(predtab))
		{
		fscanf(predtab,"%s",string);
		if(string[0]=='f')
			{
			strcpy(ffun[ifcount++],string);
			}
		else if (strcpy[0]=='g')
			{
			strcpy(gfun[igcount++],string);
			}

		}
	fclose(predtab);
	for(icount=0;icount<strlen(ffun[0]);icount++)
		{
		if(icount==0)
			{
			strcpy(oprtab[icount],ffun[icount]);
			}
		oprtab[icount][0]=ffun[0][icount];
		}
	//generating operator precedence table
	for(icount=1;icount<strlen(oprtab]0]);icount++)
		{
		for(icount1=1;icount1<strlen(oprtab[0]);icount1++)
			{
			if(oprtab[icount][0]=='i'&&oprtab[0][icount1]=='('))
				{
				oprtab[icount][icount1]=' ';
				}
			else if(oprtab[icount][0]=='i'&&oprtab[0][icount1]=='i')
				{
				oprtab[icount][icount1]=' ';
				}
			else if(oprtab[icount][0]==')'&&oprtab[0][icount1]=='('))
				{
				oprtab[icount][icount1]=' ';
				}
			else if(oprtab[icount][0]=='('&&oprtab[0][icount1]=='i')')
				{
				oprtab[icount][icount1]=' ';
				}
			else if(oprtab[icount][0]==')'&&oprtab[0][icount1]=='i'))
				{
				oprtab[icount][icount1]=' ';
				}
			 else
				{
				preval=getprecedence(oprtab[icount][0],oprtab[0][icount1]);
				if(preval==1)
					{
					oprtab[icount][icount1]='>';
					}
				else if(preval==2)
					{
					oprtab[icount][icount1]='<';
					}
				else
					{
					oprtab[icount][icount1]=' ';
					}
				}
			}
	}
	opertab=fopen("opertab.txt","w");
	for(icount=0;icount<strlen(opertab[0];icount++)
		{
		fprintf(opertab."\n\n");
		for(icount1=0;icount<strlen(opertab[0];icount1++)
			{
			fprintf(opertab,"%c\t",opertab[icount][icount1]);
			}
		}
	printf("\n enter the string to be tested ending with $:";
	scanf("%s",string);
	parser(string);
	return 1;
	}

