//S7CS56
//UDP
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
 char buf[30],tmp[30];
 struct sockaddr_in caddr,sin,cin;
 int cid=socket(AF_INET,SOCK_DGRAM,0);
 unsigned int port,port1;
 printf("enter the port number");
 scanf("%d",&port);
 caddr.sin_family=AF_INET;
 caddr.sin_port=htons(port);
 caddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 printf("enter the port number");
 scanf("%d",&port1);
 cin.sin_family=AF_INET;
 cin.sin_port=htons(port1);
 cin.sin_addr.s_addr=inet_addr("127.0.0.1");

 int b=bind(cid,(struct sockaddr *)&cin,sizeof(cin));//bind
 if(b==-1)
	{
	 perror("bind failed");
	 return 0;
	}
 do
 {
	printf("\nc:");
	scanf("%s",tmp);
	int s=sendto(cid,tmp,30,0,(struct sockaddr*)&caddr,sizeof(caddr));
	if(s==-1)
	{
	perror("send failed");return (0);
	}
	if(strcmp(tmp,"quit")==0)
	  {		
		break;
	   }
	int n=sizeof(sin);
	int r=recvfrom(cid,buf,30,0,(struct sockaddr*)&sin,&n);
	if(r==-1)
		{
			perror("recieve failed");
			return 0;
		}
	if(strcmp(buf,"quit")==0)
	  {		
		exit(0);
	   }
	printf("\ns: %s",buf);
 }while(1);
close(cid);
 }


/*OUTPUT

enter the port number4545
enter the port number5151

c:hai

s: halo
c:quit
*/
