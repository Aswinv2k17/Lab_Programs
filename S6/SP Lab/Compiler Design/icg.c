//INTERMEDIATE CODE GENERATOR

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char postfix[30];

void intopost( char infix[])
{
	char stack[30];
	int i,j=0,top=-1,len;
	len=strlen(infix);
	for(i=len;i>=0;i--)
		infix[i+1]=infix[i];
	infix[0]='(';
	len++;
	infix[len++]=')';
	infix[len]='\0';
	for(i=0;i<strlen(infix);i++)
	{
		if( (infix[i]>64 && infix[i]<91) || (infix[i]>96) && (infix[i]<123) )
		{
			postfix[j++]=infix[i];
		}
		else
		{
			stack[++top]=infix[i];
			if( stack[top]==')' )
				top--;
			while( stack[top]!= '(')
			{
				postfix[j++]=stack[top];
				top--;
			}
			stack[top--]='\0';
		}
		if ( stack[top-1]=='^' && ( stack[top]=='+' || stack[top]=='-' || stack[top]=='*' || stack[top]=='/' ) )
		{
			postfix[j++]=stack[top-1];
			stack[top-1]=stack[top];
			top;
		}
		if ( (stack[top-1]=='*' || stack[top-1]=='/') && (stack[top]== '+' || stack[top]=='-'|| stack[top]=='*' || stack[top]=='/') )
		{
			postfix[j++]=stack[top-1];
			stack[top-1]=stack[top];
			top--;
		}
		if ( (stack[top-1]=='+' || stack[top-1]=='-') && (stack[top]=='+' || stack[top]=='-') )
		{
			postfix[j++]=stack[top-1];
			stack[top-1]=stack[top];
			top--;
		}
		stack[top+1]='\0';
		printf("\n STACK: %s \n",stack);
	}
	postfix[j]='\0';
}

int intercode()
{
	int top=0,count=0,j=0,k=1,i;
	char stack[30],code[10][10],countchar[2];
	printf("\nIntermediate Code of given statement \n");
	for(i=0; i<strlen(postfix) ; i++)
	{
		if ( isalpha(postfix[i]) || isdigit(postfix[i]) )
		{
			stack[top++]=postfix[i];
			stack[top]='\0';
		}
		else
		{
			if ( isdigit(stack[top-2]) && isdigit(stack[top-1]) )
			{
				printf("\nT%d=T%c%cT%c\n",count,stack[top-2],postfix[i],stack[top-2]);
			}
			else if ( isdigit(stack[top-2]))
			{
				printf("\nT%d=T%c%c%c\n",count,stack[top-2],postfix[i],stack[top-1]);
			}
			else if ( isdigit(stack[top-1]))
			{
				printf("\nT%d=T%c%cT%c\n",count,stack[top-2],postfix[i],stack[top-1]);
			}
			else
			{
				printf("\nT%d=T%c%c%c\n",count,stack[top-2],postfix[i],stack[top-1]);
			}
			stack[top-2]='\0';
			itoa(count++,countchar,10);
			strcat(stack,countchar);
			top=strlen(stack);
		}
	}
	return count-1;
}

void main()
{
	char statement[30];
	char infix[25];
	int count,i,j;
	printf("\nEnter the statement\n");
	scanf("%s",statement);
	for(i=2,j=0;i<strlen(statement);i++,j++)
	{
		infix[j]=statement[i];
	}
	infix[j]='\0';
	printf("\n %s\n",infix);
	intopost(infix);
	intercode();
	printf("\n%c=T%d\n",statement[0],count);
}
	
