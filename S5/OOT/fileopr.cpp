#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
class Payroll
	{
	 char name[20];
	 float salary;
	 public:
		void readdata(void);
		void writedata(void);
	};
	
	void Payroll::readdata(void)
	{
		cout<<name<<" "<<salary<<"\n";
	}
	
	void Payroll::writedata(void)
	{
		cout<<"\nEnter the name: ";
		cin>>name;
		cout<<"\nEnter salary: ";
		cin>>salary;
	}

int main()
{
 int n;
 cout<<"\n Enter the number of employees to be entered\n";
 cin>>n;
 Payroll p[10];
 fstream file;
 file.open("emp.dat",ios::in||ios::out);
 cout<<"\n Enter details of employees\n";
 for(int i=0;i<n;i++)
 {
	p[i].writedata();
	file.write((char *) &p[i],sizeof(p[i]));
 }
 file.seekg(0);
 cout<<"Output\n\n";
 for(int i=0;i<10;i++)
 {
	file.read((char *) &p[i],sizeof(p[i]));
	p[i].readdata();
 }
 file.seekg(0);
 file.close();
 return 0;
}

	
