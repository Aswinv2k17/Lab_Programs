#include<iostream>
#include<string.h>
using namespace std;
class DB;
class DM
{
int met;
int cm;
public:
DM();
DM(int a,int b)
{
met=a;
cm=b;
}
void display()
{
cout<<"\ndistance is "<<met<<" metres and "<<cm<<" cms";
}
friend void add_dm(DM,DB);
friend void add_db(DM,DB);
};
class DB
{
int ft;
int in;
public:
DB();
DB(int a,int b){ft=a;in=b;}
void display()
{
cout<<"\ndistance is "<<ft<<" feet and "<<in<<" inches";
}
friend void add_dm(DM,DB);
friend void add_db(DM,DB);
};
void add_dm(DM d1,DB d2)
{
int temp;
temp=(d2.ft*12+d2.in)*2.54+(d1.met*100+d1.cm);
int a=temp/100;
int b=temp%100;
DM d21(a,b);
d21.display();
}
void add_db(DM d3,DB d4)
{
int temp;
temp=(d3.met*100+d3.cm)*0.393701+(d4.ft*12+d4.in);
int a=temp/12;
int b=temp%12;
DB d21(a,b);
d21.display();
}
int main()
{
int ms,cs,fs,is;
cout<<"\nenter distance in m and cms";
cin>>ms>>cs;
cout<<"\nenter distance in feet and inches";
cin>>fs>>is;
DM m(ms,cs);DB f(fs,is);
add_dm(m,f);
add_db(m,f);
return 0;
}
/*output:
-------

enter distance in m and cms20
40

enter distance in feet and inches20
60

distance is 28 metres and 2 cms
distance is 91 feet and 11 inches */

