//MSG QUEUE
//SERVER

#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<arpa/inet.h>

struct data
 {
	int type;
	char da[15];
 }d;
 
int main()
 {
	int m;
	char tmp[10][10],tst[10],rp[10];

	key_t k=ftok("msg.c",m);
	
	int j=0,l=strlen(d.da),p=0;

	int id=msgget(k,0666|IPC_CREAT);
	if(id==-1)
	printf("\n id not created ");
	do
	{
		int r=msgrcv(id,(void *) &d,sizeof(d),0,1);
		if(r==-1)
		printf("\n msg not recieved ");
	
		if(strcmp(d.da,"quit")==0)
		return 0;

		if(d.type==1)
			{
				int k=0;
				printf("\nmsg from client 1 :");
				puts(d.da);
				printf("\nenter the string to search :");
				gets(tst);
				printf("\nenter the string to replace :");
				gets(rp);
				
				for(int i=0;d.da[i]!='\0';i++)
				  {
					if(d.da[i]!=' ')
					{
					tmp[j][k]=d.da[i];
					k++;
					}
					
					if(d.da[i]==' ')
					{j++;k=0;}
				  }
				for(int b=0;b<=j;b++)
				{
					if(strcmp(tmp[b],tst)==0)
					{
						strcpy(tmp[b],rp);
						break;
					}
				}
				char t[20];
				printf("\nThe changed string : ");
		
				for(int b=0;b<=j;b++)
				{
					for(int i=0;tmp[b][i]!='\0';i++)
					{
						t[p++]=tmp[b][i];
					}
					
					t[p++]=' ';					
					
				}
				puts(t);
			}
			if(d.type==2)
			{
				printf("\nmsg from client 2 :");
				puts(d.da);
				int count=1;
				char to[20];
				for(int i=0;d.da[i]!='\0';i++)
				{
				 if(d.da[i]==' ')
					count++;
				}
				printf("\ncount=%d",count);
				
			}
		
	}while(1);

	return 0;
 }

/* OUTPUT

msg from client 2 :a bad day

count=3
msg from client 1 :very fine dress

enter the string to search :fine

enter the string to replace :beauty

The changed string : very beauty dress ���

msg from client 2 :humble request

count=2 	*/
