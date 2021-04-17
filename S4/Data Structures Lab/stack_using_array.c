//stack using array

#include<stdio.h>
void pop();
void push();
void display();
int top=-1,item,size,a[100],ch,x;
 int cho;
int main()
{ 
printf("input size\n"); 
scanf("%d",&size);
do
{
printf("MENU\n");
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.DISPLAY\n");
printf(" INPUT CHOICE\n");
scanf("\n %d",&ch);
 switch(ch)
 {
 case 1:push();
        break;
 case 2: pop();
        break;
 case 3: display();
         break;
 default: printf("\nINVALID CHOICE");
 }
 printf("\nDO U WISH TO CONTINUE?\n");
 scanf("%d",&cho);
}while(cho!=0);
 }
void display()
{if(top==-1)
printf("THE FINAL ARRAY IS EMPTY");
else
{printf("THE FINAL ARRAY IS:");
for(int i=top;i>=0;i--)
printf("\n%d ",a[i]);
}
}

void push()
{ 
  if(top==size-1)
 printf("\nSTACK OVERFLOW\n");
 else
{ 
  top+=1;
  printf("\nINPUT THE ELEMENT TO BE ADDED\n");
  scanf("\n%d",&x);
  a[top]= x;
} 
}

void pop()
{ 
  if(top==-1)
 printf("\nSTACK UNDERFLOW");
 else
{ 
  item= a[top];
  printf("\nTHE DELETED ELEMENT IS %d",item);
  top--;
}
}

OUTPUT

input size
2
MENU
1.PUSH
2.POP
3.DISPLAY
 INPUT CHOICE
1

INPUT THE ELEMENT TO BE ADDED
5

DO U WISH TO CONTINUE?
1
MENU
1.PUSH
2.POP
3.DISPLAY
 INPUT CHOICE
1

INPUT THE ELEMENT TO BE ADDED
6

DO U WISH TO CONTINUE?
1
MENU
1.PUSH
2.POP
3.DISPLAY
 INPUT CHOICE
1

STACK OVERFLOW

DO U WISH TO CONTINUE?
6
MENU
1.PUSH
2.POP
3.DISPLAY
 INPUT CHOICE
3
THE FINAL ARRAY IS:
6 
5 
DO U WISH TO CONTINUE?
1
MENU
1.PUSH
2.POP
3.DISPLAY
 INPUT CHOICE
2
THE DELETED ELEMENT IS 6
DO U WISH TO CONTINUE?
1
MENU
1.PUSH
2.POP
3.DISPLAY
 INPUT CHOICE
2
THE DELETED ELEMENT IS 5
DO U WISH TO CONTINUE?
1
MENU
1.PUSH
2.POP
3.DISPLAY
 INPUT CHOICE
3
THE FINAL ARRAY IS EMPTY
DO U WISH TO CONTINUE?
0













 


 
