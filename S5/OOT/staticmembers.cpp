#include<iostream>
using namespace std;
class test 
{
int a;
public:
	static int count;
void putdata()
{
a=50;
cout<<"\na="<<a;
++count;
}
static void dispcount()
{
cout<<"\ncount="<<count;
}
};
int test::count=0;

int main()
{
test a,b,c;
test::dispcount();
a.putdata();
test::dispcount();
b.putdata();
test::dispcount();
c.putdata();
return 0;
}



/*OUTPUT
count=0
a=50
count=1
a=50
count=2
a=50*/
