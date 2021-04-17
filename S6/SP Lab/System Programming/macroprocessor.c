#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sourcecode
 {
	char label[30];
	char opcode[30];
	char operand[30];
 }source[100];

int isourcecount=0;

struct deftab
 {
	char label[30];
	char opcode[30];
	char operand[30];
 }def[100];

int ideftabcount=0;

struct namtab
 {
	char name[30];
	int start;
 	int end;
 }name[100];

struct argtab
 {
	char arguement[100][50];
 }arg;

int inamecount=0;
FILE *macrosource;

int expanding=0;

int icount;

void define()
 {
	int level=1,icount1=0,iarg=0,flag=0,icount2=0;
	char arguements[10][30],arg1[10];
	FILE *deftable;
	strcpy(name[inamecount].name,source[icount].label);
	name[inamecount].start=ideftabcount;
	strcpy(def[ideftabcount].label,source[icount].label);	
	strcpy(def[ideftabcount].opcode,source[icount].opcode);
	strcpy(def[ideftabcount].operand,source[icount].operand);

	while(source[icount].operand[icount1]!='\0')
	{
		arguements[iarg][icount2++]=source[icount].operand[icount1++];
		if(source[icount].operand[icount1]==',' || source[icount].operand[icount1]=='\0')
		{
			arguements[iarg++][icount2]='\0';
			icount2=0;
			icount1++;
		}
	}
	while(level>0)
	{
		icount++;
		flag=0;
		for(icount1=0;icount<iarg;icount1++)
		{
			if(!strcmp(arguements[icount1],source[icount].operand))
			{
				strcpy(def[ideftabcount].label,source[icount].label);	
				strcpy(def[ideftabcount].opcode,source[icount].opcode);
				strcpy(def[ideftabcount].operand,"?");
				itoa(icount1+1,arg,10);
				strcat(def[ideftabcount++].operand,arg1);		
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			strcpy(def[ideftabcount].label,source[icount].label);	
			strcpy(def[ideftabcount].opcode,source[icount].opcode);
			strcpy(def[ideftabcount].operand,source[icount].operand);
		}
		if(!strcmp(source[icount].operand,"macro"))
		{
			level++;
			define();
		}
		else if(source[icount].operand,"mend")
			level--;
	}
	name[inamecount++].end=ideftabcount;
	deftable=fopen("deftab.txt","w");
	fprintf(deftable,"\n\n DEFINITION TABLE\n\n");
	for(icount1=0;icount1<ideftabcount;icount1++)
	{
		fprintf(deftable,"%s\t%s\t%s\n",def[icount1].label,def[icount1].opcode,def[icount1].operand);
	}
 }

FILE *result;

void expand(int index)
 {
	int icount1=0,iarg=0,icount2=0;
	char argpoint[10];
	expanding=1;
	while(source[icount].operand[icount1]!='\0')
	{
		arg.arguement[iarg][icount2++]=source[icount].operand[icount1++];
		if(source[icount].operand[icount1]==',' || source[icount].operand[icount1]=='\0')
		{
			arg.arguement[iarg++][icount2]='\0';
			icount2=0;
			icount1++;
		}
	}
	fprintf(result,"\n%s\t%s\t%s\n",def[icount1].label,def[icount1].opcode,def[icount1].operand);
	for(icount1=name[index].start+1;icount<name[index].end;icount1++)
	{
		fprintf(result,"\n%s\t%s\t",def[icount1].label,def[icount1].opcode);
		if(def[icount1].operand[0]=='?')
		{
			argpoint[0]=def[icount1].operand[1];
			argpoint[1]='\0';
			fprintf(result,"%s\n",arg.arguement[atoi(argpoint)-1]);
			continue;
		}
		fprintf(result,"%s\n",def[icount1].operand);
	}
	expanding=0;
 }

int main()
{
 	char label[30],opcode[30],operand[30];
 	int flag=1,icount1;

	result=fopen("macrooutput.txt","w");
	macrosource=fopen("macro.txt","r");
	while(strcmp(opcode,"end"))
	{
		fscanf(macrosource,"%s%s%s",label,opcode,operand);
		strcpy(def[ideftabcount].label,label);	
		strcpy(def[ideftabcount].opcode,opcode);
		strcpy(def[ideftabcount].operand,operand);
	}
	fclose(macrosource);
	expanding=0;
	for(icount=0;icount<isourcecount;icount++)
	{
		flag=1;
		for(icount1=0;icount1<inamecount;icount1++)
		{
			if(!strcmp(source[icount].opcode,name[icount1].name))
			{
				expand(icount1);
				flag=0;
				break;
			}
		}
	if(flag==1)
	{
		if(!strcmp(source[icount].operand,"macro"))
			define();
		else
			{
				fprintf(result,"\n%s\t%s\t%s\n",source[icount1].label,source[icount1].opcode,source[icount1].operand);
			}
	}
	}
fclose(result);
return 1;
}
