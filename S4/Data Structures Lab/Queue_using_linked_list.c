//Queue using linked list

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void enq();
void deq();
void dis();
struct node
{int info;
struct node *link;
}*front=NULL,*rear=NULL;

void main()
{
int choice,q;
do
{
printf("Enter your choice\n1.Insert\n2.Delete\n3.Display\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
enq();
break;

case 2:
deq();
break;

case 3:
dis();
break;

default:
printf("invalid entry\n");
}
printf("\nPress 1 to continue\n");
scanf("%d",&q);
}while(q==1);
}

void enq()
{
struct node *tmp;
int added_item;
tmp=(struct node *)malloc(sizeof(struct node));
printf("Enter the element\n");
scanf("%d",&added_item);
tmp->info=added_item;
tmp->link=NULL;
if(front==NULL)
front=tmp;
else 
rear->link=tmp;
rear=tmp;
}

void deq()
{
struct node *tmp;
if(front==NULL)
printf("Queue Underflow\n");
else
{
tmp=front;
printf("Deleted element %d",tmp->info);
front=front->link;
free(tmp);
}
}

void dis()
{
struct node *ptr;
ptr=front;
if(front==NULL)
printf("queue is Empty\n");
else
{
printf("Queue Elements\n");
while(ptr!=NULL)
{
printf("%d\n",ptr->info);
ptr=ptr->link;
}
printf("\n");
}
}

/*
Enter your choice
1.Insert
2.Delete
3.Display
1
Enter the element
4

Press 1 to continue
1
Queue using linked list
Enter your choice
1.Insert
2.Delete
3.Display
3
Queue Elements
4


Press 1 to continue
1
Queue using linked list
Enter your choice
1.Insert
2.Delete
3.Display
2
Deleted element 4
Press 1 to continue
5
*/
