//Call by value & call by reference
#include<iostream>
#include<cstdlib.h>
using namespace std;
class A
{
 public:
	void call_value(int x,int y);
	void call_reference(int &p,int &q);
};

void A::call_value(int x,int y)
{
	int z;
	z=x;
	x=y;
	y=z;
	cout<<"After swapping, inside the function\n Value of a="<<x<<"\n Value of b="<<y<<"\n";
}

void A::call_reference(int &p,int &q)
{
	int r;
	r=p;
	p=q;
	q=r;
	cout<<"After swapping, inside the function\n Value of a="<<p<<"\n Value of b="<<q<<"\n";
}

int main()
{
A obj;
int a,b,ch,l;
cout<<"Enter two numbers\n";
cin>>a>>b;
while(l=1)
{
cout<<"\n\t\t Menu"<<"\n1.Call by Value\n2.Call by Reference\n3.Exit\n";
cout<< "Enter your choice\n";
cin>>ch;
switch(ch)
{
case 1:
{
	cout<<"The values of a and b, before swapping are:"<<a<<" "<<b<<"\n";
	obj.call_value(a,b);
	cout<<"The values of a and b, after swapping outside function are:"<<a<<" "<<b<<"\n";
	break;
}

case 2:
{
	cout<<"The values of a and b, before swapping are:"<<a<<" "<<b<<"\n";
	obj.call_reference(a,b);
	cout<<"The values of a and b, after swapping outside function are:"<<a<<" "<<b<<"\n";
	break;
}

case 3:
{
exit(l=0);
break;
}
default:
{
cout<<"\n Invalid choice";
break;
}
}
}
return(l);
}
