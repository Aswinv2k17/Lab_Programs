//Virtual function
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class shape
{
public:
double x,y;
public:
 void getdata(double a,double b)
{
x=a;
y=b;
}
virtual void display()
{


}
};



class triangle: public shape
{

public:

void display()
{

cout<< "\narea of triangle="<<0.5*x*y;
}
};

class rectangle: public shape
{

public:

 void display()
{

cout<< "\narea of rectangle="<<x*y;
}
};




int main()
{
shape *s;
rectangle re;
triangle tr;
double a,b;
int ch;
do
{

cout<<" \n enter your choice";
cout<<"\n--------------------";
cout<<"\n 1. triangle\n2.rectangle\n3.exit\n";
cin>>ch;
switch(ch)
{
case 1:
{
cout<<"\nenter the base and height\n";
cin>>a>>b;
s=&tr;
s->getdata(a,b);
s->display();
break;
}
case 2:
{

cout<<"\n enter the length and bredth\n";
cin>>a>>b;
s=&re;
s->getdata(a,b);
s->display();

break;
}

case 3:

{
exit(0);
break;
}
default:
{
cout<<"\n invalid choice entry";

break;
}
}
}while(1);
}


/*OUTPUT
_________
 enter your choice
--------------------
 1. triangle
2.rectangle
3.exit
2

 enter the length and bredth
12
21

area of rectangle=252 
 enter your choice
--------------------
 1. triangle
2.rectangle
3.exit
1

enter the base and height
12
21

area of triangle=126 
 enter your choice
--------------------
 1. triangle
2.rectangle
3.exit

*/
