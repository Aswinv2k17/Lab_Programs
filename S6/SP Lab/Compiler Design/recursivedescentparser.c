#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int cur=0;
char str[30];

void error()
{
 printf("\nString not accepted\n");
 exit(1);
}

void E();
void F()
{
 if (str[cur]=='i')
 	cur++;
 else if (str[cur]=='(')
 {	cur++;
	E();
	if (str[cur]==')')
		cur++;
	else
		error();
 }
 else
	error();
}

void Y()
{
 if(str[cur]=='*')
 {
	cur++;
	F();
	Y();
 }
}

void T()
{
 F();
 Y();
}

void X()
{
 if (str[cur]=='+')
 {
	cur++;
	T();
	X();
 }
}

void E()
{
 T();
 X();
}

void main()
{
 int len;
 printf("Enter the statement\n");
 scanf("%s",str);
 len=strlen(str);
 E();
 if(cur==len)
 {
	printf("\nThe string is accepted\n");
 }
 else
        error();
}



/*OUTPUT

Enter the statement
i+i*i

The string is accepted

Enter the statement
(i)

The string is accepted

Enter the statement
i-e

String not accepted */

