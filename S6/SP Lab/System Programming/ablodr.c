#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int hextodecimal(char achex[])
{
	int ilength,icount,aidecimal[10],itemp;
	int ddecimal=0;
	ilength=strlen(achex);
	for(icount=0;icount<ilength;icount++)
	{
	switch(achex[icount])
		{
			case '0':
					aidecimal[icount]=0;break;
			case '1':
					aidecimal[icount]=1;break;
			case '2':
					aidecimal[icount]=1;break;
			case '3':
					aidecimal[icount]=3;break;
			case '4':
					aidecimal[icount]=4;break;
			case '5':
					aidecimal[icount]=5;break;
			case '6':
					aidecimal[icount]=6;break;
			case '7':
					aidecimal[icount]=7;break;
			case '8':
					aidecimal[icount]=8;break;
			case '9':
					aidecimal[icount]=9;break;
			case 'A':
			case 'a':
					aidecimal[icount]=10;break;
			case 'B':
			case 'b':
					aidecimal[icount]=11;break;
			case 'C':
			case 'c':
					aidecimal[icount]=12;break;
			case 'D':
			case 'd':
					aidecimal[icount]=13;break;
			case 'E':
			case 'e':
					aidecimal[icount]=14;break;
			case 'F':
			case 'f':
					aidecimal[icount]=15;break;
		}
	}
	itemp=ilength-1;
	for(icount=0;icount<ilength;icount++,itemp--)
	{
		ddecimal=ddecimal+(aidecimal[icount]*pow(16,itemp));
	}
	return ddecimal;
}
void main()
{
	FILE *object,*loader;
	int index=0,icount,flag,objindex=0,iloc,length,rem;
	char record[100],location[100],objectcode[100];

	object=fopen("object.TXT","r");
	while(!feof(object))
	{
		fscanf(object,"%s",record);
		if(record[0]=='H')
		{
			flag=0;
			for(icount=0;icount<strlen(record);icount++)
			{
				if(record[icount]=='^')
				{
					flag++;
				}
				if(flag==2)
				{
					for(icount=icount+1;record[icount]!='^';icount++)
					{
						location[index++]=record[icount];
					}
					location[index]='\0';
					break;
				}
			}
		}
		else if(record[0]=='T')
		{
			flag=0;
			for(icount=0;icount<strlen(record);icount++)
			{
				if(record[icount]=='^')
				{
					flag++;
				}
				if(flag==3)
				{
					for(icount=icount+1;icount<strlen(record);icount++)
					{
						if(record[icount]=='^')
						{
							objectcode[objindex++]=record[icount];
						}
					}
					objectcode[objindex]='\0';
					break;
				}
			}		
		}
	}
	fclose(object);
	rem=(objindex)%8;
	iloc=hextodecimal(location);
	loader=fopen("absoluteloader.txt","w");
	for(icount=0;icount<objindex;icount++)
	{
		if(icount%32==0)
		{
			//itoa(iloc,location,16);
			sprintf(location,"%d",iloc);
			fprintf(loader,"\n%s",location);
			iloc+=16;
		}
		if(icount%8==0)
		{
			fprintf(loader,"\t");
		}
		fprintf(loader,"%c",objectcode[icount]);
	}
	for(icount=0;icount<(8-rem);icount++)
	{
		fprintf(loader,"X");
	}
	fclose(loader);
}

