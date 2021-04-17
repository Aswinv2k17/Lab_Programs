#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
class bank
{
	char name[20],b[100],atype[20];
	int ano;
	float bal;
	public:
		void get()
		{
			cout<<"\nEnter account number : ";
			cin>>ano;
			cout<<"\nEnter name : ";
			cin>>name;
			cout<<"\nEnter account type : ";
			cin>>atype;
			cout<<"\nEnter balance amount : ";
			cin>>bal;
		}
		int get_n()
		{
		return ano;
		}
		void deposit()
		{
			float amt;
			cout<<"\nEnter amount to deposit:"
			cin>>amt;
			bal=bal+amt;
			cout<<bal;
		}
		void withdraw()
		{
			float amt;
			cout<<"\nEnter amount to withdraw:"
			cin>>amt;
			if(bal>=amt)
			{
			bal=bal-amt;
			cout<<"\nCurrent balance:"<<bal;
			}
			else
			cout<<"\nInsufficient balance\n";
		}
		void display()
		{
			cout<<"\n\nAccount number:"<<ano;
			cout<<"\nName:"<<name;
			cout<<"\nAccount type:"<<atype;
			cout<<"\nBalance:"<<bal;
		}
}bk[100];

int main()
{
	int n,j,ch,ano,z;
	char nm[20],t[20],b[100];
	int flag=0;
	while(1)
	{
	 cout<<"\t\tMENU"<<"\n1. Details \n2.Deposit\n 3.Withdraw\n 4.Display\n 5.Exit\n";
	 cout<<"\nEnter Choice\n";
	 cin>>ch;
	switch(ch)
	{
	 case 1:{
		cout<<"Enter the no of customers:\n";
		cin>>z;
		for(int i=0;i<z;i++)
		{
		 cout<<"Enter details of "<<(i+1) <<"customer:\n";
		 bk[i].get();
		}
		break;
	 }
	 case 2:{
		cout<<"\nEnter the account no:\n";
		cin>>n;
		for(int i=0;i<z;i++)
		{
		 if(bk[i].get_n()==n)
		 {
			flag=1;
			j=i;
			break;
		 }
		 else
			 flag=0;
		}
		if (flag == 1)
			bk[j].deposit();
			else
				cout<<"\nNo such account no.";
		break;
	 }
	 case 3:{
		cout<<"\nEnter the account no:";
		cin>>n;
		for(int i=0;i<z;i++)
		{
		  if(n==bk[i].get_n())
		  {
			flag=1;
			j=i;
			break;
		  }
		  else
			  flag = 0;
		}
		if (flag == 1)
			bk[j].withdraw();
			else
				cout<<"\nNo such account no.";
		break;
	 }
	 case 4:{
		cout<<"\nEnter the account no:";
		cin>>n;
		for(int i=0;i<z;i++)
		{
		  if(n==bk[i].get_n())
		  {
			flag=1;
			j=i;
			break;
		  }
		  else
			  flag = 0;
		}
		if (flag == 1)
			bk[j].display();
			else
				cout<<"\nNo such account no.";
		break;
	 }
	 case 5:{
		exit(1);
	 }
	 default:cout<<"\nWrong choice\n";
	}
	}
	return 0;
}