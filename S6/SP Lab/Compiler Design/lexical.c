//LEXICAL ANALYZER

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char str1[30],fstr[30][30],kstr[30][30],istr[30][30],ostr[30][30],hstr[30][30],sstr[30][30],cstr[30][30];
int fcount=0,kcount=0,icount=0,ocount=0,hcount=0,scount=0,ccount=0;

void function()
{
	printf("\n %s",str1);
	strcpy(fstr[fcount++],str1);
	
}

void operator()
{
	printf("\n %s",str1);
	strcpy(ostr[ocount++],str1);
	
}

void keyword()
{printf("\n %s",str1);
	strcpy(kstr[kcount++],str1);
	
}

void identifier()
{
	printf("\n %s",str1);
	strcpy(istr[icount++],str1);
	
}

void header()
{
	printf("\n %s",str1);
	strcpy(hstr[hcount++],str1);
	
}

void strin()
{printf("\n %s",str1);
	strcpy(sstr[scount++],str1);
	
}

void consts()
{
	printf("\n %s",str1);
	strcpy(cstr[ccount++],str1);
	
}

void display()
{
 	printf("\n\nKEYWORDS\n");
	for(int i=0;i<kcount;i++)
	printf("%s\n",kstr[i]);

	printf("\n\nOPERATORS\n");
	for(int i=0;i<ocount;i++)
	printf("%s\n",ostr[i]);

	printf("\nFUNCTIONS\n");
	for(int i=0;i<fcount;i++)
	printf("%s\n",fstr[i]);

	printf("\n\nIDENTIFIERS\n");
	for(int i=0;i<icount;i++)
	printf("%s\n",istr[i]);

	printf("\n\nCONSTANTS\n");
	for(int i=0;i<ccount;i++)
	printf("%s\n",cstr[i]);

	printf("\n\nHEADER FILES\n");
	for(int i=0;i<hcount;i++)
	printf("%s\n",hstr[i]);

	printf("\n\nSTRING\n");
	for(int i=0;i<scount;i++)
	printf("%s\n",sstr[i]);
}

void main()
{
int i,flag=0,digit=0;
char ch[30];
char op[30][30]={"<",">","+","=","-","/","%","*",",","#","{","}","[","]",";",",","(",")",";",":","^"};
char func[30][30]={"main","scanf","printf"};
char key[23][30]={"break","case","char","default","do","else","float","for","goto","if","int",    "return","short","signed","sizeof","static","struct","switch","void","while","include"};
char hea[20][20]={"stdio.h","math.h","ctype.h","string.h","stdlib.h"};
FILE *fp;
fp=fopen("sample.txt","r");

while(!feof(fp))
{	flag=0;
	fscanf(fp,"%s",str1);
	printf("\n");
	for(i=0;i<5;i++)
	{
		if (strcmp(func[i],str1)==0)
		{
		 function();
		 flag=1;break;
		}
	}
	if(flag==0)
	{
		for(i=0;i<22;i++)
	{
		if (strcmp(op[i],str1)==0)
		{
		operator();
		flag=1;break;
		}
	}
	}
	if(flag==0)
	{
		for(i=0;i<22;i++)
	{
		if (strcmp(key[i],str1)==0)
		{
		keyword();
		flag=1;break;
		}
	}
	}
	if(flag==0)
	{
		for(i=0;i<5;i++)
	{
		if (strcmp(hea[i],str1)==0)
		{
		header();
		flag=1;break;
		}
	}
	}
	//string constants
	if(flag==0)
	{
		if (str1[0]=='"' && str1[strlen(str1)-1]=='"')
		{
		strin();
		flag=1;
		}
	}
	if(flag==0)
	{	digit=1;
		for(i=0;i<strlen(str1);i++)
	{
		if (str1[i]>47 && str1[i]<58)
		{
		digit=1;
		}
		else
		{
		 digit=0;break;
		}
	}
	if(digit==1)
		{
		consts();
		flag=1;
		}
	}
	if(flag==0)
	{
		identifier();
		printf("\n");
	}
}
display();
}


/*  OUTPUT

input file

include < stdio.h > void main ( ) int a , b , sum = 0 ; a = 20 ; b = 30 ;

 KEYWORDS
include
void
int


OPERATORS
<
>
(
)
,
,
=
;
=
;
=
;
;

FUNCTIONS
main


IDENTIFIERS
a
b
sum
a
b


CONSTANTS
0
20
30


HEADER FILES
stdio.h


STRING
    */
