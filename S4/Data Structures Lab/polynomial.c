//Polynomial addition and multiplication

#include<stdio.h>
#include<stdlib.h>
struct node
{
int mag,exp;
struct node *link;
}*p,*q,*a,*b,*s,*t,*ptr,*ptr1;
void insert()
{
int x,y,i=0;
y=1;
printf("\n enter the first polynomial \n");
p=(struct node *)malloc(sizeof(struct node));
p->link=(struct node *)malloc(sizeof(struct node ));
s=p->link;
while(y>0)
{
scanf("%d",&x);
scanf("%d",&y);
s->mag=x;
s->exp=y;
if(y!=0)
{
s->link=(struct node *)malloc(sizeof(struct node));
s=s->link;
}
i++;
}
y=2;
printf("\n enter the second polynomial \n");
q=(struct node *)malloc(sizeof(struct node));
q->link=(struct node *)malloc(sizeof(struct node ));
t=q->link;
while(y>0)
{
scanf("%d",&x);
scanf("%d",&y);
t->mag=x;
t->exp=y;
if(y!=0)
{
t->link=(struct node *)malloc(sizeof(struct node));
t=t->link;
}
}
}

void add()
{
insert();
s=p->link;
t=q->link;
a=(struct node *)malloc(sizeof(struct node));
a->link=(struct node *)malloc(sizeof(struct node));
b=a->link;
while((s!=NULL)&&(t!=NULL))
{
if(s->exp==t->exp)
{
b->mag=s->mag+t->mag;
b->exp=s->exp;
s=s->link;
t=t->link;
b->link=(struct node *)malloc(sizeof(struct node));
b=b->link;
}
else if(s->exp>t->exp)
{
b->mag=s->mag;
b->exp=s->exp;
s=s->link;
b->link=(struct node *)malloc(sizeof(struct node));
b=b->link;
}
else
{
b->mag=t->mag;
b->exp=t->exp;
t=t->link;
b->link=(struct node *)malloc(sizeof(struct node));
b=b->link;
}
}
while(s!=NULL)
{
b->mag=t->mag;
t=t->link;
b->link=(struct node *)malloc(sizeof(struct node));
b=b->link;
}
}

void multiply()
{
insert();
a=(struct node *)malloc(sizeof(struct node));
a->link=(struct node *)malloc(sizeof(struct node));
b=a->link;
s=p->link;
while(s!=NULL)
{
t=q->link;
while(t!=NULL)
{
b->mag=(s->mag)*(t->mag);
b->exp=s->exp+t->exp;
t=t->link;
b->link=(struct node *)malloc(sizeof(struct node));
b=b->link;
}
s=s->link;
}
b=a->link;
while(b!=NULL)
{
ptr=b;
while(ptr->link!=NULL)
{
ptr1=ptr;
ptr=ptr->link;
if(b->exp==ptr->exp)
{
b->mag=b->mag+ptr->mag;
ptr1->link=ptr->link;
free(ptr);
ptr=ptr1;
}
}
b=b->link;

}
}
void main()
{
int ch;

while(1)
{
printf("\n POLYNOMIAL MENU \n 1.addition \n 2.multiplication \n 3.exit\n enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1:add();
       printf("\n sum is:");
	b=a->link;
	while(b->exp!=0)
	{
	printf("%dx^%d+",b->mag,b->exp);
	b=b->link;
	}
	printf("%d",b->mag);
	break;
case 2:multiply();
	printf("\n product is:");
	b=a->link;
	while(b->link!=NULL)
	{
	printf("%dx^%d+",b->mag,b->exp);
	b=b->link;
	}
	printf("%dx^%d",b->mag,b->exp);
	break;
case 3:exit(0);
	break;
default:printf("\n no such option ");
}
}

}





/*OUTPUT

 POLYNOMIAL MENU 
 1.addition 
 2.multiplication 
 3.exit
 enter your choice1

 enter the first polynomial 
4 3 2 2 3 1 4 0

 enter the second polynomial 
5 2 10 1 3 0

 sum is:4x^3+7x^2+13x^1+7
 POLYNOMIAL MENU 
 1.addition 
 2.multiplication 
 3.exit
 enter your choice2 

 enter the first polynomial 
1 2 1 1 0 0

 enter the second polynomial 
3 2 1 0

 product is:3x^4+1x^2+3x^3+1x^1+0x^0
 POLYNOMIAL MENU 
 1.addition 
 2.multiplication 
 3.exit
 enter your choice
*/


