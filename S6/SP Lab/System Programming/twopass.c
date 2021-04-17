//Two Pass

#include<stdio.h>
#include<string.h>
#include<math.h>
struct obj
	{
	char mne[50];
	char address[50];
	}o[100];
int ocount=0;
int hexToDecimal(char acHex[])
{
int len,temp,i;
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
	case '2':
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
void twopass()
{
	char label[30],opcode[30],operand[30],address[30],byte[30],c[50];
	char loc[30],prgmname[30],opc[30],mnemo[30],prg[30],sym[30],adr[30],pgrmName[30];
	int flag,i,temp,length;
	char startaddress[30];

	int locctr;
	FILE *fp,*f1,*f2;

        fp=fopen("intermediate.txt","r");
	fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
	while(!feof(fp))
		{
			if (strcmp(opcode,"START")==0)
				{
					strcpy(prgmname,label);
					strcpy(startaddress,operand);
					strcpy(pgrmName,label);

				}
			else	
			{if(strcmp(opcode,"RESW")==0)
			{
			fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
			locctr=locctr+atoi(operand)*3;
			continue;
			}
			else if(strcmp(opcode,"WORD")==0)
			{
			strcpy(o[ocount].mne,"00");
			strcpy(o[ocount].address,"000");
			strcat(o[ocount++].address,operand);
			locctr=locctr+3;
			}
			else if(strcmp(opcode,"RESB")==0)
			{
			fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
			locctr+=atoi(operand);continue;
			}
			else if(strcmp(opcode,"BYTE")==0)
			{
			strcpy(o[ocount].mne,"");
			strcpy(o[ocount].address,"");
			for(i=0;operand[i]!='\0';i++)
				{
				temp=operand[i];
				sprintf(byte,"%x",temp);
				strcat(o[ocount].address,byte);
				}
			ocount++;
			locctr=locctr+strlen(operand);
			}
			else
			{
			f1=fopen("opcode.txt","r");
			fscanf(f1,"%s%s",opc,mnemo);
			while(!feof(f1))
				{
				if (strcmp(opcode,opc)==0)
				{
				strcpy(o[ocount].mne,mnemo);
				break;
				}
			fscanf(f1,"%s%s",opc,mnemo);
				}
			fclose(f1);
			f2=fopen("symtab.txt","r");
			while(!feof(f2))
				{
				if (strcmp(operand,sym)==0)
				{
				strcpy(o[ocount++].address,adr);
				break;
				}
				fscanf(f2,"%s%s",sym,adr);
				}
				fclose(f2);
				locctr+=3;
			}
			}
	
			fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
		}
		fclose(fp);

	length=locctr-hexToDecimal(startaddress);
	fp=fopen("record.txt","w");
	fprintf(fp,"H^%s00%s^0000%x",prgmname,startaddress,length);
	fprintf(fp,"\nT^%s^%x",startaddress,length);
	for(i=0;i<ocount;i++)
	fprintf(fp,"^%s%s",o[i].mne,o[i].address);
	
	fprintf(fp,"\nE^00%s",startaddress);
	fclose(fp);
	fp=fopen("record.txt","r");
	fgets(c,50,fp);
	printf("%s\n",c);
	while(!feof(fp))
	{
	 fgets(c,50,fp);
	printf("%s\n",c);
	}
}
int main()
{
 twopass();
}
