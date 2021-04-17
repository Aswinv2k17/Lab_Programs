//Queue using array

#include<stdio.h>
void enqueue();
void dequeue();
void display();
int front=-1,rear=-1,item,size,a[100],ch,x;
int kl=0;
 int cho;
int main()
{ 
printf("input size\n"); 
scanf("%d",&size);
do
{
printf("MENU\n");
printf("1.ENQUEUE\n");
printf("2.DEQUEUE\n");
printf("3.DISPLAY\n");
printf(" INPUT CHOICE\n");
scanf("\n %d",&ch);
 switch(ch)
 {
 case 1:enqueue();

        break;
 case 2: dequeue();
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
{if(front==-1)
printf("THE FINAL ARRAY IS EMPTY");
else
{printf("THE FINAL ARRAY IS:");
for(int i=front;i<=rear;i++)
printf("\n%d ",a[i]);
}
}

void enqueue()
{ 
  
  if(rear==size-1)
  printf("\nQUEUE OVERFLOW\n");

  else
{ 
  printf("\nINPUT THE ELEMENT TO BE ADDED\n");
  scanf("\n%d",&x); 
  if(front==-1&&rear==-1)
  front=rear=0;
  else
  rear++;
  a[rear]= x;
 }
}

void dequeue()
{ 
  if(front==-1||front>rear)
 printf("\nQUEUE UNDERFLOW");
 else
{ 
  item= a[front];
  printf("\nTHE DELETED ELEMENT IS %d",item);
  front++;
}
}
OUTPUT
Input size
2
MENU
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
 INPUT CHOICE
1

INPUT THE ELEMENT TO BE ADDED
1

DO U WISH TO CONTINUE?
1
MENU
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
 INPUT CHOICE
1

INPUT THE ELEMENT TO BE ADDED
2

DO U WISH TO CONTINUE?
1
MENU
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
 INPUT CHOICE
1

QUEUE OVERFLOW

DO U WISH TO CONTINUE?
1
MENU
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
 INPUT CHOICE
3
THE FINAL ARRAY IS:
1 
2 
DO U WISH TO CONTINUE?
1
MENU
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
 INPUT CHOICE
2

THE DELETED ELEMENT IS 1
DO U WISH TO CONTINUE?
1
MENU
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
 INPUT CHOICE
2

THE DELETED ELEMENT IS 2
DO U WISH TO CONTINUE?
1
MENU
1.ENQUEUE
2.DEQUEUE
3.DISPLAY
 INPUT CHOICE
2

QUEUE UNDERFLOW
DO U WISH TO CONTINUE?
0

