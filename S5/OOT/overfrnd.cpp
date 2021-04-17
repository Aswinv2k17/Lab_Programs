//Operator overloading using friend function
#include<iostream>
using namespace std;
class complex
{
float num1,num2;
public:
void accept()
{
cout<<"\n enter two numbers";
cin>>num1>>num2;
}
friend complex operator+(complex c1, complex c2);
void display()
{
cout<<num1<<"+"<<num2<<"i"<<"\n";
}
};
complex operator+(complex c1, complex c2)
{
complex c;
c.num1=c1.num1+c2.num1;
c.num2=c1.num2+c2.num2;
return(c);
}
int main()
{
complex c1,c2,sum;
c1.accept();
c2.accept();
sum=c1+c2;
cout<<"\nentered values:\n";
 c1.display();
cout<<"\t";
c2.display();
cout<<"\n addition of real and imaginary numbers:\n";
cout<<"\t";
sum.display();
return 0;
}


/*OUTPUT
----------
 enter two numbers2
4

 enter two numbers2
1

entered values:
2+4i
	2+1i

 addition of real and imaginary numbers:
	4+5i
*/
