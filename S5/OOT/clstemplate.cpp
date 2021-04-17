//Class Template
#include<iostream>
#include<stdlib.h>
using namespace std;
int l;
 template<class T>
class vector
{
T *v;
int size;
public:
int i;
vector(int l)
{
v=new T[size=l];
for (int i=0;i<size;i++)
v[i]=0;
}
void create(int y)
{
cout<< "\n enter the array elements\n";
for (int i=0;i<y;i++)
cin>>v[i];
}
void display()
{
cout<<"\n (";
for( int i=0;i<size;i++)
cout<<" "<<v[i];
cout<<")\n";
}
void modify(int a)
{
for(int i=0;i<=size;i++)
if(i==a)
{
cout<<"\n enter the changed dats";
cin>>v[i-1];
}
}
void mul( int m)
{
for(int i=0;i<size;i++)
v[i]=v[i]*m;
}
};




int main()
{
int x[20],j,y,i,ch;
cout<<"\n enter the limit";
cin>>l;
vector<int>v1(l);
do
{
cout<<"\n menu\n 1. ro create vector\n 2. to modify vector\n 3.to multiply by a scalar value\n 4. to display the vector\n5.exit\n enter the choice\n";
cin>>ch;
switch(ch)
{
case 1:
v1.create(l);
break;
case 2:
v1.display();
cout<< "\n enter the position of the index to be modified";
cin>>j;
v1.modify(j);
break;
case 3:
cout<<"\n enter the scalar value\n";
cin>>y;
v1.mul(y);
break;
case 4:
v1.display();
break;
case 5:
exit(0);
break;
default:
cout<<"\n invalid choice entry";
break;
}
}while(1);
}




/*OUTPUT
---------
enter the limit5

 menu
 1. ro create vector
 2. to modify vector
 3.to multiply by a scalar value
 4. to display the vector
5.exit
 enter the choice
1

 enter the array elements
1
2
3
4
5

 menu
 1. ro create vector
 2. to modify vector
 3.to multiply by a scalar value
 4. to display the vector
5.exit
 enter the choice
4

 ( 1 2 3 4 5)

 menu
 1. ro create vector
 2. to modify vector
 3.to multiply by a scalar value
 4. to display the vector
5.exit
 enter the choice
2

 ( 1 2 3 4 5)

 enter the position of the index to be modified3

 enter the changed dats4

 menu
 1. ro create vector
 2. to modify vector
 3.to multiply by a scalar value
 4. to display the vector
5.exit
 enter the choice
4

 ( 1 2 4 4 5)

 menu
 1. ro create vector
 2. to modify vector
 3.to multiply by a scalar value
 4. to display the vector
5.exit
 enter the choice
3

 enter the scalar value
12

 menu
 1. ro create vector
 2. to modify vector
 3.to multiply by a scalar value
 4. to display the vector
5.exit
 enter the choice
4

 ( 12 24 48 48 60)

 menu
 1. ro create vector
 2. to modify vector
 3.to multiply by a scalar value
 4. to display the vector
5.exit
 enter the choice
*/
