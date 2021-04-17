//FUNCTION OVERLOADING
#include<iostream>
#include<cstdlib>
using namespace std;
class A
{
	int l,b;
	float a,x,y;
	public:
		int area(int r);
		int area(int l, int b);
		float area(float x, float y);
};

int A::area(int r)
{
	return(3.14*r*r);
}
int A::area(int a,int b)
{
	return(l*b);
}
float A::area(float x,float y)
{
	return(x*y*.5);
}

int main()
{
	A ob;
	int ch,len,br;
	float r,base,hgt;
	while(1)
	{
	 cout<<"\t\tMENU"<<"\n1. Area of Circle \n2.Area of Rectangle\n 3.Area of Triangle\n 4.Exit\n";
	 cout<<"\nEnter Choice\n";
	 cin>>ch;
	  switch(ch)
	  {
	   case 1:
	   {
		cout<<"\nEnter the radius of the circle\n";
		cin>>r;
		cout<<"\nArea of the circle is "<<ob.area(r);
		break;
	   }
	   case 2:
	   {
		cout<<"\nEnter the length & breadth of rectangle\n";
		cin>>len>>br;
		cout<<"\nArea of the rectangle is "<<ob.area(len,br);
		break;
	   }

		case 3:
		{
		 cout<<"\nEnter the height & base of triangle\n";
		 cin>>base>>hgt;
		 cout<<"\nArea of the triangle is "<<ob.area(base,hgt);
		 break;
		}

		case 4:
		{
		 exit(0);
		 break;
		}
		
		default:{
		cout<<"\nInvalid Choice\n";
		break;
		}
	  }
	}
	return(1);
}