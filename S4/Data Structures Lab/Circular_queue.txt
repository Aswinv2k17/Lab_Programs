//Circular queue

#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void display();
int cqueue_arr[50];
int front =-1;
int rear=-1;
int max;
void main()
{
int choice;
printf("Enter the size of the array: ");
scanf("%d",&max);
do
{
   printf("1.insertion\n");
   printf("2.deletion\n");
   printf("3.display\n");
   printf("4.quit\n");
   printf("Enter the choice: ");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
        {insert();
         break;}
   case 2:
         {delete();
         break;}
   case 3:
        {display();
         break;}
   case 4:
        {exit(1);}
   default:("wrong choice\n");
   }
}
while(1);
}

void insert()
{
 int added_item;
 if((front==0&&rear==max-1)||(front==rear+1))
 {
 printf("Queue over flow\n");
 return;
}
 if (front==-1)
{
 front=0;
 rear=0;
}

else
  if(rear==max-1)
   rear=0;
   else 
  rear=rear+1;
printf("input the element for insertion in queue: ");
scanf("%d",&added_item);
cqueue_arr[rear]=added_item;
}

void delete()
{
 if (front==-1)
{
 printf("Queue under flow\n");
 return;
}
printf("Element deleted from queue is: %d\n",cqueue_arr[front]);
if(front==rear)
{
front=-1;
rear=-1;
}
else
 if(front==max-1)
  front=0;
  else
  front=front+1;
}

void display()
{ 
 int front_pos=front,rear_pos=rear;
if(front==-1)
{
printf("Queue is empty\n");
 return;
}
printf("Queue element:\n");
if(front_pos<=rear_pos)
{
 while(front_pos<=rear_pos)
{
printf("%d",cqueue_arr[front_pos]);
front_pos++;
}
}
else
{
while(front_pos<=max-1)
{
printf("%d",cqueue_arr[front_pos]);
front_pos++;
}
front_pos=0;
while(front_pos<=rear_pos)
{
printf("%d",cqueue_arr[front_pos]);
front_pos++;
}
}
printf("\n");
}


/*
OUTPUT

Enter the size of the array: 2
1.insertion
2.deletion
3.display
4.quit
Enter the choice: 1
input the element for insertion in queue: 1
1.insertion
2.deletion
3.display
4.quit
Enter the choice: 1
input the element for insertion in queue: 2
1.insertion
2.deletion
3.display
4.quit
Enter the choice: 1
Queue over flow
1.insertion
2.deletion
3.display
4.quit
Enter the choice: 2
Element deleted from queue is: 1
1.insertion
2.deletion
3.display
4.quit
Enter the choice: 3
Queue element:
2
1.insertion
2.deletion
3.display
4.quit
Enter the choice: 4
*/
















