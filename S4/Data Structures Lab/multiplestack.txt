//Multiple Stack

#include<stdio.h>
#include<stdlib.h>
int top1,top2,stkarr[100];
void push();
void pop(int);
void display(int);
void main()
{
int ch,max;

top1=-1;
printf("enter the size of the stack");
scanf("%d",&max);
top2=max;
do
{
printf("\n1.push\n2.pop\n3.display\n4.exit");
printf("\nenter a CHOICE");
scanf("%d",&ch);
switch(ch)
{
case 1:push();
       break;
case 2:pop(max);
       break;
case 3:display(max);
       break;
case 4:exit(0);
       break;
default:printf("\nwrong choice");
        break;
}
}while(ch!=4);
}
void push()
{
int r,ch,n,x;
if(top1==top2-1)
{
printf("\nstack overflow");
return;
}
printf("enter a number");
scanf("%d",&n);
printf("press 1 to push in stack 1 and press 2 to push in stack 2:");
scanf("%d",&ch);
if(ch==1)
{
stkarr[++top1]=n;
}
else
{
stkarr[--top2]=n;//n used instead x
}
printf("%d\nelement is successfully pushed",n);
return;
}
void pop(int max)
{
int y,ch;
printf("press 1 to pop from stack1 and 2 to pop from stack2....");
scanf("%d",&ch);
if(ch==1)
{
 if(top1==-1)
 {
 printf("stack underflow");
 return;
 }
y=stkarr[top1];
stkarr[top1--]=0;
}
else
 {
 if(top2==max)
  {
  printf("\nstack underflow");
  return;
  }
y=stkarr[top2];
stkarr[top2++]=0;
}
printf("%d\nelement is successfully poped from stack",y);
return;
}
void display(int max)
{
int i;
if(top1==-1)
{
printf("\nstack1 is empty");
}
else
{
printf("\nelements of stack1 are:");
for(i=0;i<=top1;i++)
{
printf("%d\n",stkarr[i]);
}
}
if(top2==max)
{
printf("\nstack2 is empty");
}
else
{
printf("\nelements in stack2 are:");
for(i=max-1;i>=top2;i--)
{
printf("%d\n",stkarr[i]);
}
}
return;
}
/*OUPUT
enter the size of the stack2

1.push
2.pop
3.display
4.exit
enter a CHOICE1
enter a number11
press 1 to push in stack 1 and press 2 to push in stack 2:2
11
element is successfully pushed
1.push
2.pop
3.display
4.exit
enter a CHOICE1
enter a number33
press 1 to push in stack 1 and press 2 to push in stack 2:1
33
element is successfully pushed
1.push
2.pop
3.display
4.exit
enter a CHOICE3

elements of stack1 are:33

elements in stack2 are:11

1.push
2.pop
3.display
4.exit
enter a CHOICE1

stack overflow
1.push
2.pop
3.display
4.exit
enter a CHOICE2
press 1 to pop from stack1 and 2 to pop from stack2....2
11
element is successfully poped from stack
1.push
2.pop
3.display
4.exit
enter a CHOICE3

elements of stack1 are:33

stack2 is empty
1.push
2.pop
3.display
4.exit
enter a CHOICE4
*/
