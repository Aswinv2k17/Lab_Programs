//Stack using Linked list

        #include<stdio.h>
	#include<malloc.h>
	void push();
	void pop();
	void display();
	struct node
	{
	  int info;
	struct node*link;
	}
	 *top=NULL;
	int main()
	{
	int choice;
	while(1)
	{
	 printf("1.PUSH \n");
	 printf("2.POP \n");
	 printf("3.DISPLAY \n");
	 printf("Enter your choice");
	 scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	{
	 push();
	 break;
	}
	 case 2:
	{
	 pop();
	 break;
	}
	 case 3:
	{
	 display();
	 break;
	}
	 default:
	{
	 printf("Wrong choice");
	}
	}
	}
	}
	void push()
	{
	struct node *temp;
	int pushed_item;
	 temp=(struct node *)malloc(sizeof(struct node));
	 printf("Snput the new value to be pushed on the stack:");
	 scanf("%d",&pushed_item);
	 temp->info=pushed_item;
	 temp->link=top;
	 top=temp;
	}
	void pop()
	{
	 struct node*temp;
	 if(top==NULL)
	{
	 printf("Stack is empty \n");
	}
	else
	{
	 temp=top;
	 printf("Popped item is %d \n",temp->info);
	 top=top->link;
	 free(temp);
	}
	}
	void display()
	{
	 struct node*ptr;
	 ptr=top;
	if(top=NULL)
	 printf("Stack is empty \n");
	else
	{
	 printf("Stack elements:\n");
	while(ptr!=NULL)
	{
	 printf("%d \n",ptr->info);
	 ptr=ptr->link;
	}
	}
	}
	/* OUTPUT
	1.PUSH 
	2.POP 
	3.DISPLAY 
	enter your choice1
	input the new value to be pushed on the stack:5
	1.PUSH 
	2.POP 
	3.DISPLAY 
	enter your choice1
	input the new value to be pushed on the stack:7
	1.PUSH 
	2.POP 
	3.DISPLAY 
	enter your choice1
	input the new value to be pushed on the stack:8
	1.PUSH 
	2.POP 
	3.DISPLAY 
	Enter your choice2
	popped item is 8 
        1.PUSH 
        2.POP 
        3.DISPLAY 
        Enter your choice3
        stack elements:
        7 
        5 */


