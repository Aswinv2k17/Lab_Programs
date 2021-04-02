//Deque


#include<stdio.h>

int left = -1,right =-1,max;
int deque[100];

void insert_right();
void insert_left();
void delete_right();
void delete_left();
void display();

void main()
{
	int c;
	printf("Enter the size\n");
	scanf("%d",&max);
	do
	{
		printf("\n1.Insert at right \n2.Insert at left \n3.Delete from right \n4.Delete from left \n5.Display \n6.Exit");
		printf("\nenter your choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				{
				    insert_right();
				    break;
			    }
			case 2:
				{
					insert_left();
					break;
				}
		    case 3:
				{
				   	delete_right();
					break;   	
				}
			case 4:
			    {
			    	delete_left();
			    	break;
				}	
				case 5:
					{
						display();
						break;
					}
				}
			}while(c!=6);
		
	
}

void insert_right()
{
	int val;
	printf("\nEnter the value to be added\n");
	scanf("%d",&val);
	if((left==0 && right==max)||(left==right+1))
	{
		printf("\n overflow");
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(right==max-1)
		right=0;
		else
		right=right+1;
	}
	deque[right]=val;
}
void insert_left()
{
	int val;
	printf("\nEnter the value to be added\n");
	scanf("%d",&val);
	if((left==0&&right==max-1)||(left==right+1))
	{
		printf("\n overflow");
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else
	{
		if(left==0)
		left=max-1;
		else
		left=left-1;
	}
	deque[left]=val;
}
void delete_right()
{
	if(left==-1)
	{
		printf("\n underflow");
		return;
	}
	printf("\nThe deleted element is %d \n",deque[right]);
	if(left==right)
	{
		left=-1;
		right=-1;
	}
	else
	{
		if(right==0)
		right=max-1;
		else
		right=right-1;
	}
}
void delete_left()
{
	if(left==-1)
	{
		printf("\nunderflow");
		return;
	}
	printf("\n The deleted element is %d \n",deque[left]);
	if(left==right)
	{
		left=-1;
		right=-1;
	}
	else
	{
		if(left==max-1)
		left=0;
		else
		left=left+1;
	}
}
void display()
{
	int front=left,rear =right;
	if(front==-1)
	{
		printf("\nQueue is empty\n");
		return;
	}
	printf("\nThe elements in the queue are:");
	if(front<=rear)
	{
		while(front<=rear)
		{
			printf("%d  ",deque[front]);
			front++;
		}
	}
	else
	{
		while(front<=max-1)
		{
			printf("%d  ",deque[front]);
			front++;
		}
		front=0;
		while(front<=rear)
		{
			printf("%d  ",deque[front]);
			front++;
		}
	}
	printf("\n");
}

/*  OUTPUT
  
Enter the size
5

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
1

Enter the value to be added
5

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
2

Enter the value to be added
6

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
2

Enter the value to be added
7

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
5

The elements in the queue are:7  6  5

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
3

The deleted element is 5

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
5

The elements in the queue are:7  6

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
4

 The deleted element is 7

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
5

The elements in the queue are:6

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
3

The deleted element is 6

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
5

Queue is empty

1.Insert at right
2.Insert at left
3.Delete from right
4.Delete from left
5.Display
6.Exit
enter your choice
6    */

