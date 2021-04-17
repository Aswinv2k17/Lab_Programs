//Constructors and destructors
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class book
{
char author[25],title[20],publ[20];
int price,stockp;
public:
	 void insert()
{
cout<<"\nenter title";
cin>>title;
cout<<"\nenter author";
cin>>author;
cout<<"\nenter publisher";
cin>>publ;
cout<<"\nenter price";
cin>>price;
cout<<"\nenter stock";
cin>>stockp;
}
public:
	book()
{
strcpy(title,"NULL");
strcpy(author,"NULL");
strcpy(publ,"NULL");
price=0;
stockp=0;
}
public:
	int books(char titl[20],char auth[20])
{
int f=0;
if(strcmp(titl,title)==0)
{
if(strcmp(auth,author)==0)
{
f=1;
}
}
return (f);
}
void search()
{
display();
stock();
}
void display()
{
cout<<"\nbook details";
cout<<"\n------------";
cout<<"\ntitle"<<title;
cout<<"\nauthor"<<author;
cout<<"\npublisher"<<publ;
cout<<"\nprice"<<price;
}
void stock()
{
int nc;
cout<<"\nenter the no: of copies required";
cin>>nc;
if(nc>stockp)
{
cout<<"\nrequired no: of copies unavailable";
}
else
{
cout<<"\ntotal price"<<price*nc;
stockp=stockp-nc;
}
}
~book(){}
};
int main()
{
int i,n,ch,f;
char titl[20],auth[20];
book b[10];
while(1)
{
cout<<"\ninventory";
cout<<"\n---------";
cout<<"\n1.Insert";
cout<<"\n2.Search";
cout<<"\n3.Exit";
cout<<"\nenter your choice";
cin>>ch;
switch(ch)
{
case 1:
{
cout<<"\nenter no: of books to be inserted";
cin>>n;
for(i=0;i<n;i++)
b[i].insert();
break;
}
case 2:
{
cout<<"\nenter the title";
cin>>titl;
cout<<"\nenter the author";
cin>>auth;
f=0;
for(i=0;i<n;i++)
{
f=b[i].books(titl,auth);
if(f==1)
break;
}
if(f==1)
{
b[i].search();
}
else
{
cout<<"\nbook not available";
}
break;
}
case 3:{
return 0;
break;
}
default:cout<<"\nwrong choice";
}
}
return 0;
}


/*OUTPUT
inventory
---------
1.Insert
2.Search
3.Exit
enter your choice1

enter no: of books to be inserted 2

enter title Bleach

enter author Kubo

enter publisher Shounen

enter price 500

enter stock 20

enter title Java

enter author Kozhi

enter publisher Manu   

enter price 999

enter stock15

inventory
---------
1.Insert
2.Search
3.Exit
enter your choice2

enter the title Java

enter the author Kozhi

book details
------------
titleJava
authorKozhi
publisherManu
price999
enter the no: of copies required 9

total price8991
inventory
---------
1.Insert
2.Search
3.Exit
enter your choice 2

enter the title Bleach

enter the author Kubo

book details
------------
titleBleach
authorKubo
publisherShounen
price500
enter the no: of copies required 5

total price2500
inventory
---------
1.Insert
2.Search
3.Exit
enter your choice 2

enter the title Bleach

enter the author Kubo

book details
------------
titleBleach
authorKubo
publisherShounen
price500
enter the no: of copies required 16

required no: of copies unavailable
inventory
---------
1.Insert
2.Search
3.Exit
enter your choice 3
s5cs07@sslsb-desktop:~/Niranjan$*/ 



