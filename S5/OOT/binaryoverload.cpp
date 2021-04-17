#include<iostream>
#include<stdlib.h>
using namespace std;
class Float
{
 float a;
 public:
  Float(float p)
  {
   a=p;
  }
 Float operator+(Float c2)
  {
   Float c3(0);
   c3.a=a+c2.a;
   return c3;
  }
 friend Float operator-(Float c1,Float c2)
  {
   Float c3(0);
   c3.a=c1.a-c2.a;
   return c3;
  }
 Float operator*(Float c2)
  {
   Float c3(0);
   c3.a=a*c2.a;
   return c3;
  }
 friend Float operator/(Float c1,Float c2)
  {
   Float c3(0);
   c3.a=c1.a/c2.a;
   return c3;
  }
 float get()
  {
   return a;
  }
};
int main()
 {
   float x,y;int ch;
   cout<<"\nenter two values";
   cin>>x>>y;
   Float A(x);
 Float B(y);
while(ch!=0)
{
cout<<"\n1.addition\n2.subtraction\n3.multiplication\n4.division\n5.exit";
cout<<"\nenter the choice";
cin>>ch;

switch(ch)
{
case 1:
{
Float C=A+B;
cout<<"\nsum="<<C.get();
break;
}
case 2:
{
Float D=A-B;
cout<<"\ndifference="<<D.get();
break;
}
case 3:
{
Float P=A*B;
cout<<"\nproduct="<<P.get();
break;
}
case 4:
{
Float Q=A/B;
cout<<"\nquotient="<<Q.get();
break;
}
case 5:
{exit(0);
}
default:cout<<"\nwrong choice";
}
}
return 0;
}


output:

/*enter two values20
30

1.addition
2.subtraction
3.multiplication
4.division
5.exit
enter the choice1

sum=50
1.addition
2.subtraction
3.multiplication
4.division
5.exit
enter the choice2

difference=-10
1.addition
2.subtraction
3.multiplication
4.division
5.exit
enter the choice3

product=600
1.addition
2.subtraction
3.multiplication
4.division
5.exit
enter the choice4

quotient=0.666667
1.addition
2.subtraction
3.multiplication
4.division
5.exit
enter the choice5
*/

