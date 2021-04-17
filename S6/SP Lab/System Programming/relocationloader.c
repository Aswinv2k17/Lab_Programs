//RELOCATION LOADER
# include <stdio.h>
# include <string.h>
# include <malloc.h>
# include <stdlib.h>
char * hextobin(char hex[10])
{
char *bin=malloc(20);
int i,flag=0;
for(i=0;i<strlen(hex);i++)
{
switch(hex[i])
{
	case '0':
		if(flag==0)
		{
		strcpy(bin,"0000");
		flag=1;
		}
		else
		{
		strcat(bin,"0000");
		}
		break;



	case '1':
		if(flag==0)
		{
		strcpy(bin,"0001");
		flag=1;
		}
		else
		{
		strcat(bin,"0001");
		}
		break;


	case '2':
			if(flag==0)
		{
		strcpy(bin,"0010");
		flag=1;
		}
		else
		{
		strcat(bin,"0010");
		}
		break;




	case '3':
		if(flag==0)
		{
		strcpy(bin,"0011");
		flag=1;
		}
		else
		{
		strcat(bin,"0011");
		}
		break;

	case '4':
		if(flag==0)
		{
		strcpy(bin,"0100");
		flag=1;
		}
		else
		{
		strcat(bin,"0100");
		}
		break;



	case '5':
		if(flag==0)
		{
		strcpy(bin,"0101");
		flag=1;
		}
		else
		{
		strcat(bin,"0101");
		}
		break;


	case '6':
		if(flag==0)
		{
		strcpy(bin,"0110");
		flag=1;
		}
		else
		{
		strcat(bin,"0110");
		}
		break;


	case '7':
		if(flag==0)
		{
		strcpy(bin,"0111");
		flag=1;
		}
		else
		{
		strcat(bin,"0111");
		}
		break;


	case '8':
		if(flag==0)
		{
		strcpy(bin,"1000");
		flag=1;
		}
		else
		{
		strcat(bin,"1000");
		}
		break;


	case '9':
		if(flag==0)
		{
		strcpy(bin,"1001");
		flag=1;
		}
		else
		{
		strcat(bin,"1001");
		}
		break;

	case 'A':
	case 'a':
		if(flag==0)
		{
		strcpy(bin,"1010");
		flag=1;
		}
		else
		{
		strcat(bin,"1010");
		}
		break;
	

	
	case 'B':
	case 'b':
		if(flag==0)
		{
		strcpy(bin,"1011");
		flag=1;
		}
		else
		{
		strcat(bin,"1011");
		}
		break;
	
	case 'C':
	case 'c':
		if(flag==0)
		{
		strcpy(bin,"1100");
		flag=1;
		}
		else
		{
		strcat(bin,"1100");
		}
		break;
	
	case 'D':
	case 'd':
		if(flag==0)
		{
		strcpy(bin,"1101");
		flag=1;
		}
		else
		{
		strcat(bin,"1101");
		}
		break;
	
	case 'E':
	case 'e':
		if(flag==0)
		{
		strcpy(bin,"1110");
		flag=1;
		}
		else
		{
		strcat(bin,"1110");
		}
		break;
	
	case 'F':
	case 'f':
		if(flag==0)
		{
		strcpy(bin,"1111");
		flag=1;
		}
		else
		{
		strcat(bin,"1111");
		}
		break;
	

}}
return bin;
}

struct obcode{
	char opc[5];
	char addr[5];

	}obj[100];
int ocount=0;



void main()
{
char relocbit[3],start[10];
int i,j,addr,startaddr,diff,newaddr,prevcount=0;
char text[100];
char bin[100];
	FILE *fp;
fp=fopen("trec.txt","r");
printf("the address of the relocation");
scanf("%d",&addr);
fscanf(fp,"%s",text);
while(!feof(fp))
{
	if(text[0]=='T')
		{
		j=0;
		for(i=12;i<15;i++)
		{
			relocbit[j++]=text[i];
		}

		relocbit[j]='\0';
		strcpy(bin,hextobin(relocbit));
		i=16;
		while(i<strlen(text))
		{
			for(j=0;j<2;j++)
			{
			obj[ocount].opc[j]=text[i++];
			}


			
			obj[ocount].opc[j]='\0';


			for(j=0;j<4;j++)
			{
				obj[ocount].addr[j]=text[i++];
			}
			obj[ocount++].addr[j]='\0';
			if(text[i]=='^')
			{
				i++;
			}
		}


		for(i=prevcount,j=0;i<ocount;i++,j++)
		{
			if(bin[j]=='1')
			{
				newaddr=atoi(obj[i].addr)+diff;
				sprintf(obj[i].addr,"%d",newaddr);
			}
		}
		prevcount=ocount;
		}

		else if(text[0]='H')
		{
			j=0;
			for(i=7;i<13;i++)
			{
				start[j++]=text[i];
			}
			start[j]='\0';
			startaddr=atoi(start);
			diff= abs(startaddr-addr);
			}
			fscanf(fp,"%s",text);
			}

			for(i=0;i<ocount;i++)
			{
				printf("%d\t%s%s\n",addr,obj[i].opc,obj[i].addr);
				addr=addr+3;
			}
		}



/*OUTPUT
======

the address of the relocation 2000
2000	142033
2003	483039
2006	^12003
2009	6^4800
2012	302000
2015	012005
2018	102061
2021	C02003
2024	002002
2027	0C2039
2030	00002D
2033	0C2036
2036	483061
2039	082033
2042	4C0000
2045	454046
2048	000003
2051	000000

*/
