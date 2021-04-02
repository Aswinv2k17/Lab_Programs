//S7CS56
//TCP
//CLIENT 
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/un.h>
#include<arpa/inet.h>
int main()
{
char buffer[30],t[30];
struct sockaddr_in caddr;
int cid=socket(AF_INET,SOCK_STREAM,0);
printf("enter the port number");
unsigned int port;
scanf("%d",&port);
caddr.sin_family=AF_INET;
caddr.sin_port=htons(port);
caddr.sin_addr.s_addr=inet_addr("127.0.0.1");
int c=connect(cid,(struct sockaddr *)&caddr,sizeof(caddr));
if(c==-1)
{perror("connection failed");return (0);}
do
{
	printf("\nc:");
	scanf("%s",buffer);
	int s=send(cid,buffer,sizeof(buffer),0);
	if(s==-1)
	{
	perror("send failed");return (0);
	}
	int r=recv(cid,t,sizeof(t),0);
	if(r==-1)
		{
			perror("recieve failed");
			return 0;
		}
	if(strcmp(t,"quit")==0)
	  {		
		exit(0);
	   }
	printf("\ns: %s",t);
	
}while(strcmp(t,"quit")!=0);
}

/*OUTPUT

enter the port number5656

c:hai

s: hai
c:quit

s: hai
c:quit

s: quits	*/
