#include<iostream>
using namespace std;
class matrix
{
public:
	int m[10][10],p,q;
 
 void read(void)
{
int i,j;
cout<<"enter the no: of rows";
cin>>p;
cout<<"enter the no: of columns";
cin>>q;
for(i=0;i<p;i++)
for(j=0;j<q;j++)
cin>>m[i][j];
}

 void display(void)
{
int i,j;
for(i=0;i<p;i++)
{
cout<<"\n";
for(j=0;j<q;j++)
{
cout<<m[i][j]<<"\t";
}
}
}

friend matrix multi(matrix,matrix);
};
matrix multi(matrix m1,matrix m2)
{
matrix m3;
m3.p=m1.p;
m3.q=m2.q;
int i,j,k;
if(m1.q!=m2.p)
{
cout<<"\nmultiplication not possible\n";
}
else
{
for(i=0;i<m1.p;i++)
{
for(j=0;j<m2.q;j++)
{
m3.m[i][j]=0;
for(k=0;k<m3.p;k++)
m3.m[i][j]=m3.m[i][j]+(m1.m[i][k]*m2.m[k][j]);
}
cout<<"\n";
}
return (m3);
}
}
int main()
{
 matrix mat1,mat2,mat3;
 cout<<"\nenter the first matrix\n";
mat1.read();
cout<<"\nyou entered the following matrix";
mat1.display();
cout<<"\nenter the second matrix\n";
mat2.read();
cout<<"\nyou entered the following matrix";
mat2.display();
mat3=multi(mat1,mat2);
if(mat1.q==mat2.p)
{
cout<<"\nmultiplication result\n";
mat3.display();
}
return 0;
}


/*OUTPUT
enter the first matrix
enter the no: of rows2
enter the no: of columns3
3
2
3
4
6
7

you entered the following matrix
3	2	3	
4	6	7	
enter the second matrix
enter the no: of rows3
enter the no: of columns1
4
5
6

you entered the following matrix
4	
5	
6	


multiplication result

22	
46
enter the first matrix
enter the no: of rows2
enter the no: of columns3
1
2
3
4
5
6

you entered the following matrix
1	2	3	
4	5	6	
enter the second matrix
enter the no: of rows1
enter the no: of columns1
12

you entered the following matrix
12	
multiplication not possible
*/	

	

