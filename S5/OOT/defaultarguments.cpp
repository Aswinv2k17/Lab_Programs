#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;
class A
{
double m;int n;
public:
	void power(double a,int b);
};
void A:: power(double a,int b=2)
{
m=a;n=b;
cout<<"\nthe power of "<<m<<"raised to"<<n<<"="<<(pow(m,n));
}

int main()
{ 
A ob;
char chr;
double a;int b,c;
do
{
cout<<"\nEnter the value of m\n";
cin>>a;
cout<<"\t\tMENU\n1.Without Default Argument \n2.With Default Argument \n3.Exit";
cout<<"\nEnter Choice\n";
cin>>c;
switch(c)
{
case 1:{
cout<<"\nWithout Default Argument";
cout<<"\nEnter the value of n\n";
cin>>b;
ob.power(a,b);
break;
}
case 2:{
cout<<"\nWith Default Argument";
ob.power(a);
break;
}
case 3:{
exit(0);
break;
}
default:{
	cout<<"\nInvalid Choice\n";
	break;
}
}
cout<<"\nDo you want to continue?\n (Y/N)";
cin>>chr;
}
while(chr=='Y'||chr=='y');
	return(0);
}
