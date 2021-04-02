//Infix to postfix

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define size 100

char stack[size];
 int top=-1;
 void push(char x)
{
 if(top>=size-1)
 printf("Overflow");
 else
 stack[++top]=x;
}
 char pop()
{
 char item;
 if(top==-1)
 return -1;
 else
 return stack[top--];
}
 int priority(char x)
{
 if(x=='(')
 return 0;
 if(x=='+'||x=='-')
 return 1;
 if(x=='*'||x=='/')
 return 2;
 if(x=='^')
 return 3;
}
 int main()
{
 char exp[20];
 char *e,x;
 printf("enter the expression: ");
 scanf("%s",exp);
 e=exp;
 printf("postfix expression is: ");
 while(*e!='\0')
{int m=*e;
if(isalnum(m))
printf("%c",*e);
else if(*e=='(')
{
 push(*e);
}
else if(*e==')')
{
while((x=pop())!='(')
printf("%c",x);
}
else
{
while(priority(stack[top])>=priority(*e))
printf("%c",pop());
push(*e);
}
e++;
}
while(top!=-1)
{
printf("%c",pop());
}
}

/*OUTPUT
enter the expression: a/(b+c)
postfix expression is: abc+/ 
*/












