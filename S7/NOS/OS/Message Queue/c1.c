//MSG QUEUE
//CLIENT 1

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
	char da[10];
 }d;
int main()
 {
	int m;

	key_t k=ftok("msg.c",m);

	int id=msgget(k,0666|IPC_CREAT);
	if(id==-1)
	printf("\n id not created ");
	do
	{
		printf("\n enter the string : ");
		gets(d.da);

		d.type=1;
	
		int s=msgsnd(id,(void *) &d,sizeof(d),1);
		if(s==-1)
		printf("\n msg not send ");
		if(strcmp(d.da,"quit")==0)
		return 0;
	}while(1);

	return 0;
 }
 
/* OUTPUT

 enter the string : very fine dress

 enter the string : quit */

        
