//Calculator Operations Using Functions
#include<stdio.h>

int main()
{
	int add(int a,int b);
	int sub(int a,int b);
	int multi(int a,int b);
	float div(int a,int b);
	int a,b;
	int ch;
	printf("Enter the first number\n");
	scanf("%d",&a);
	printf("Enter the second number\n");
	scanf("%d",&b);
	printf("\nEnter Choice\n");
	printf("\n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: add(a,b);
			break;
		case 2: sub(a,b);
			break;
		case 3: multi(a,b);
			break;
		case 4: div(a,b);
			break;
		default: printf("\nInvalid choice");
	}
}


int add(int a,int b)
{
	int s=a+b;
	printf("\n Sum = %d",s);
}

int sub(int a,int b)
{
	int d=a-b;
	printf("\n Difference = %d",d);
}

int multi(int a,int b)
{
	int p=a*b;
	printf("\n Product = %d",p);
}

float div(int a,int b)
{
	float q=a/b;
	printf("\n Quotient = %f",q);
}
