//Function Template
#include<iostream>
#include<stdlib.h>
using namespace std;
template<class T>
int linear(T a[],T key, int n)
{
int i;
for(i=0;i<n;i++)
if (a[i]==key)
return(i);
return -1;
}


int main()
{
int x[20], k1,ch,i,l,f;
float y[20],k2;
cout<<"\n menu\n";
do
{
cout<<"\n1. linear search for integers \n 2. linear search for floating point numbers\n3. exit\n";
cout<<"enter your choice\n";
cin>>ch;
switch(ch)
{
 case 1:
cout<< "\n enter the limit\n";
cin>>l;
cout<<"\n enter the integer numbers\n";
for(i=0;i<l;i++)
{
cin>>x[i];
}
cout<<"\n enter the elment to be searched in the list\n";
cin>>k1;
f=linear(x,k1,l);
if(f==-1)
cout<<"\n element not in the list\n";
else
cout<<"\n elment found at position "<<f;
break;
case 2:
cout<< "\n enter the limit\n";
cin>>l;
cout<<"\n enter the floating numbers\n";
for(i=0;i<l;i++)
{
cin>>y[i];
}
cout<<"\n enter the elment to be searched in the list\n";
cin>>k2;
f=linear(y,k2,l);
if(f==-1)
cout<<"\n element not in the list\n";
else
cout<<"\n elment found at position "<<f;
break;
case 3:
exit(0);
break;
default:
cout<<"invalid choice entry";
break;
}
}while(1);
}



/*OUTPUT
-----------
 menu

1. linear search for integers 
 2. linear search for floating point numbers
3. exit
enter your choice
1

 enter the limit
3

 enter the integer numbers
2
1
5

 enter the elment to be searched in the list
5

 elment found at position 2
1. linear search for integers 
 2. linear search for floating point numbers
3. exit
enter your choice
2

 enter the limit
4

 enter the floating numbers
12.1
33.5
23
5.7

 enter the elment to be searched in the list
5.7

 elment found at position 3
1. linear search for integers 
 2. linear search for floating point numbers
3. exit
enter your choice
*/

