#include<iostream>
using namespace std;
class unary
{
int x,y,z;float a;
public:
void getdata(int p,int q,int r)
{
x=p;
y=q;
z=r;
}
void operator-()
{
x=-x;
y=-y;
z=-z;
}
void display()
{
cout<<"x="<<x<<" y="<<y<<" z="<<z;
}
};
int main()
{
unary S;int m,n,o;
cout<<"enter three numbers";
cin>>m>>n>>o;
S.getdata(m,n,o);
cout<<"\nS:";
S.display();
-S;
cout<<"\n -S:";
S.display();
return 0;
}


/*OUTPUT

enter three numbers9  
6
3

S:x=9 y=6 z=3
 -S:x=-9 y=-6 z=-3





