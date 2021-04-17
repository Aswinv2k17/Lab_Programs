#include<stdio.h>
#include<string.h>
#include<math.h>
struct SYMTAB
	{	
		char symbol[30]; 
		char address [30]; 
	}s [100];
	int scount=0;
struct OBJCOD
	{ 
		char mne[10]; 
		char address [30];
	}o[100];
	int ocount=0;
void firstPass ()
{
	char label[30],opcode[30],operand[30],address[30];
	char loc[30];
	int flag,j;
	int startAddress,locctr,i;
	FILE *fp ,*f1;
	fp=fopen("source.txt","r ");
	f1=fopen("intermediate.txt","w");
	fscanf(fp,"%s%s%s",label,opcode,operand);
	while (!feof(fp))
	{ 
		printf("%s\t%s\t%s\n",label,opcode,operand);
		if (strcmp(opcode,"START")==0)
		{
			startAddress=atoi(operand);
			locctr=startAddress;
		}
		else
		{
			if (strcmp(label,"**")!=0)
			{
				strcpy(s[scount].symbol,label);
				sprintf(address,"%d",locctr);
				strcpy(s[scount++].address,address);
			}
			if (strcmp(opcode,"WORD")==0)
			{
				fprintf(f1,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
				locctr=locctr+3;
				fscanf(fp,"%s%s%s",label,opcode,operand);
				continue;
			}
			fprintf(f1,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
			locctr+=3;
		}
		fscanf(fp,"%s%s%s",label ,opcode ,operand);
	}
	fclose(f1);
	fclose(fp);
	printf ("Symbol Table\n");
	for(i=0;i<scount;i++)
	{
		printf("%s\t%s\n",s[ i ].symbol,s[i].address);
	}
	printf ("Intermediate Code of Assembler\n");
	f1=fopen("intermediate.txt","r");
	fscanf(f1,"%s%s%s%s",loc,label,opcode,operand);
	while (!feof(f1))
	{
		printf("%s\t%s\t%s\t%s\n",loc,label,opcode,operand);
		fscanf(f1,"%s%s%s%s",loc,label,opcode,operand);
	}
	fclose(f1);

}
void secondPass()
{
	char label[30],opcode[30],operand[30],address[30],loc[30];
	char opc[30],mnemo[30],prgmName[30];
	int flag,j;
	int startAddress,locctr,i;
	FILE *fp ,*f1;
	fp=fopen("intermediate.txt","r");
	fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
	while (!feof(fp))
	{
		if (strcmp(opcode,"START")==0)
		{
			startAddress=atoi(operand);
			locctr=startAddress;
			strcpy(prgmName,label);
		}
		else
		{
			f1=fopen("opcode.txt","r");
			fscanf(f1,"%s%s",opc,mnemo);
			while (!feof(f1))
			{
				if (strcmp(opcode,opc)==0)
				{
					strcpy(o[ocount].mne,mnemo);
					break;
				}
				fscanf(f1,"%s%s",opc,mnemo);
			} 
			fclose(f1);
			for(i=0;i<scount;i++)
			{
				if (strcmp(operand,s[i].symbol)==0)
				{
					strcpy(o[ocount++].address,s[i].address);
					break;
				}
			}
		}
		fscanf(fp,"%s%s%s%s",loc,label,opcode,operand);
	}
	printf("Object Code\n");
	for(i=0;i<ocount; i++)
	{
		printf("%s\t%s\n",o[i].mne,o[i].address);
	} 
}

void main()
{
 firstPass();
 secondPass();
}