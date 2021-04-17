//S6 CSE
//One pass assembler

#include<stdio.h>
#include<string.h>
#include<math.h>
struct SYTAB
{
char symbol[30];
char address[30];
}s[100];
int scount=0;
struct OBJCOD
{
char mne[10];
char address[30];
int flag;
}o[100];
int ocount=0;
int hexToDecimal(char acHex[])
{
int len,i,temp;
int dec=0;
len=strlen(acHex);
for(i=0;i<len;i++)
{
switch(acHex[i])
{
case '0':
	temp=0;
	break;
case '1':
temp=1;
break;

case'2':
temp=2;
break;

case '3':
temp=3;
break;
 case '4':
temp=4;
break;


case '5':
temp=5;
break;

case '6':
temp=6;
break;

case '7':
temp=7;
break;


case '8':
temp=8;
break;

case '9':
temp=9;
break;
case 'a':
	case 'A':
		temp=10;
		break;
	case 'b':
	case 'B':
		temp=11;
		break;
	case 'c':
	case 'C':
		temp=12;
		break;
	case 'd':
	case 'D':
		temp=13;
		break;
	case 'e':
	case 'E':
		temp=14;
		break;
	case 'f':
	case 'F':
		temp=15;
		break;
}
dec=dec+temp*pow(16,len-i-1);
}
return dec;
}
void onePass()
{
char label[30],opcode[30],operand[30],address[30],opc[30],mnemo[30],c[50];
char loc[30],startAddress[30],prgmname[30],byte[30];
int flag,j,temp,length;
int locctr=0,i;
FILE *fp,*fl;
fp=fopen("source.txt","r");
fscanf(fp,"%s%s%s",label,opcode,operand);
while(!feof(fp))
{
flag=0;
if(strcmp(opcode,"START")==0)
{
	strcpy(prgmname,label);
	strcpy(startAddress,operand);
	locctr=hexToDecimal(operand);
	fscanf(fp,"%s%s%s",label,opcode,operand);
}
if(strcmp(label,"**")!=0)
{
	strcpy(s[scount].symbol,label);
	sprintf(address,"%x",locctr);
	strcpy(s[scount++].address,address);
}
if(strcmp(opcode,"WORD")==0)
{
	strcpy(o[ocount].mne,"00");
	strcpy(o[ocount].address,"000");
	strcat(o[ocount].address,operand);
	o[ocount++].flag=1;
	locctr+=3;
}

else if(strcmp(opcode,"RESW")==0)
{
locctr+=atoi(operand)*3;
}

else if(strcmp(opcode,"RESB")==0)
{
locctr+=atoi(operand);
}

else if(strcmp(opcode,"BYTE")==0)
{

			strcpy(o[ocount].address,operand);
			/*for(i=0;operand[i]!='\0';i++)
			{
			temp=operand[i];
			sprintf(byte,"%x",temp);

			strcat(o[ocount++].address,byte);
			}*/
		o[ocount++].flag=1;
locctr+=strlen(operand);
}
else
{
	fl=fopen("opcode.txt","r");
fscanf(fl,"%s%s",opc,mnemo);
while(!feof(fl))
{
if(strcmp(opcode,opc)==0)
{
strcpy(o[ocount].mne,mnemo);
break;
}
fscanf(fl,"%s%s",opc,mnemo);
}
fclose(fl);
for(i=0;i<scount;i++)
{
if(strcmp(operand,s[i].symbol)==0)
{
strcpy(o[ocount].address,s[i].address);
o[ocount++].flag=1;
flag=1;
break;
}
}
if(flag==0)
{
strcpy(o[ocount].address,operand);
o[ocount++].flag=0;
}
locctr+=3;
}
fscanf(fp,"%s%s%s",label,opcode,operand);
}
fclose(fp);
for(i=0;i<ocount;i++)
{
if(o[i].flag==0)
{
for(j=0;j<scount;j++)
{
if(strcmp(o[i].address,s[j].symbol)==0)
{
strcpy(o[i].address,s[j].address);
}
}
}
}
printf("symbol table\n");
for(i=0;i<scount;i++)
{
printf("%s\t%s\n",s[i].symbol,s[i].address);
}
// record format'
length=locctr-hexToDecimal(startAddress);
fp=fopen("record.txt","w");
fprintf(fp,"H^%s^00%s^0000%x",prgmname,startAddress,length);
fprintf(fp,"\nT^%s^%x",startAddress,length);
for(i=0;i<ocount;i++)
{
fprintf(fp,"^%s%s",o[i].mne,o[i].address);
}
fprintf(fp,"\nE^00%s",startAddress);
fclose(fp);

printf("RECORD TEXT\n");
fp=fopen("record.txt","r");
fgets(c,50,fp);
printf("%s\n",c);
while(!feof(fp))
{


fgets(c,50,fp);
printf("%s\n",c);


}
}
void main()
{
onePass();
}




/*
INPUT FILE
__________

source.txt
COPY   START 1000
**     LDA   NUM1 
**     LDX  NUM2
LOOP   ADD   NUM2
**     DEC   NUM1
**     JNZ   LOOP
NUM1   BYTE  05
NUM2   RESW  2
**     END

opcode.txt
LDA 50
LDX 60
ADD 70
DEC 80
JNZ 90


OUTPUT
-----------
\symbol table
LOOP	1006
NUM1	100f
NUM2	1011
RECORD TEXT
H^COPY^001000^000017

T^1000^17^50100f^601011^701011^80100f^901006^05

E^001000

*/
