#include<iostream>
#include<stdlib.h>
using namespace std;
class account
{
public:
char name[20], type[20];
int acno;
float bal=0,amt;

public:
void create()
{
cout<<"\n enter the name of the customer:";
cin>>name;
cout<<"\n enter the account type:";
cin>>type;
cout<<"\n enter the account number:";
cin>>acno;
}
void deposit()
{
cout<<"\n enter the amount to be deposited:";
cin>>amt;
bal=bal+amt;
}
void withdraw()
{
int amt2;
cout<<"enter withdraw amount";
cin>>amt2;
if(amt2>bal)
cout<<"\n insuffient balance";
else
bal-=amt2;
cout<<bal;
}





void display()
{
cout<<"\n---------------------------";
cout<<"\nAccount No:"<<acno;
cout<<"\nName:"<<name;
cout<<"\nAccount Type:"<<type;
cout<<"\nbalance:"<<bal;
}
};


class savings:public account
{
public:
float inst;
void intrest()
{
inst=bal*.1;
bal=bal+inst;
cout<<"\n balance amount after adding intrest :"<<bal;
}
};
class current:public account

{
public:
float min()
{
if (bal<1000)
cout<<" penalty of 100 imposed due to insufficient balance";
bal=bal-100;

}
};


 int main()
{
int ch,act,x,i=0,j=0,k,l,m,n,o,p;
savings s[20];
current c[20];
do
{
cout<< "\nenter the  choice";
 cout<<"\n 1.create new account\n2.deposit\n 3.withdraw \n4. intrest\n 5.penalty\n 6. display 7.exit\n";
cin>>ch;
switch(ch)
{
case 1:
cout<<" enter the account type:- 1.savings 2. current\n";
cin>>act;
if (act==1)
{

s[i].create();
i++;
}
else if (act==2)
{

c[j].create();
j++;
}
break;
case 2:
cout<<"enter the account number:";
cin>>x;
cout<<"enter the account type:- 1.savings 2. current:\n";
cin>>act;
if(act==1)
{
for(l=0; l<10;l++)

if(s[l].acno==x)
s[l].deposit();

}
else if (act==2)
{
for(p=0;p<10;p++)
{
if(c[p].acno==x)
c[p].deposit();

}
}
break;

case 3:
cout<<"enter the account number";
cin>>x;
cout<<"enter the account type:- 1.savings 2. current:";
cin>>act;
if (act==1)
{
for(m=0; m<10;m++)

if(s[m].acno==x)
s[m].withdraw();

}
else if (act==2)
{
for(m=0;m<10;m++)
{
if(c[m].acno==x)
c[m].withdraw();

}
}
break;
case 4:
cout<<"enter the account number";
cin>>x;
for(n=0;n<10;n++)
{
if (s[n].acno==x)
s[n].intrest();

}
break;

case 5:
cout<<"enter the account number";
cin>>x;
for(o=0;o<10;o++)
{
if (c[o].acno==x)
c[o].min();

}
break;

case 6:
cout<<"enter the account number";
cin>>x;
cout<<"enter the account type:- 1.savings 2. current;";
cin>>act;
if (act==1)
{
for(m=0; m<10;m++)

{
if(s[m].acno==x)
s[m].display();
}
}
else if (act==2)
{
for(m=0;m<10;m++)
{
if(c[m].acno==x)

c[m].display();
}
}
break;
case 7:
exit(0);
break;
 default:
cout<<"invalid choice entry";
break;
}
}while(1);
}

