//S7CS56
//UDP
//SERVER 
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
 struct sockaddr_in saddr,cin;
 int sid=socket(AF_INET,SOCK_DGRAM,0);
 unsigned int port;
 printf("enter the port number");
 scanf("%d",&port);
 cin.sin_family=AF_INET;
 cin.sin_port=htons(port);
 cin.sin_addr.s_addr=inet_addr("127.0.0.1");

 int b=bind(sid,(struct sockaddr *)&cin,sizeof(cin));//bind
 if(b==-1)
	{
	 perror("bind failed");
	 return 0;
	}
 do
 {
	printf("\nc:");
	int m=sizeof(saddr);
	int r=recvfrom(sid,buf,30,0,(struct sockaddr*)&saddr,&m);
	if(r==-1)
		{
			perror("recieve failed");
			return 0;
		}
	printf("%s",buf);
	if(strcmp(buf,"quit")==0)
	  {		
		return(0);
	   }
	printf("\ns:");
	scanf("%s",buf);
	int s=sendto(sid,buf,30,0,(struct sockaddr*)&saddr,sizeof(saddr));
	if(s==-1)
	{
	perror("send failed");return (0);
	}
	if(strcmp(buf,"quit")==0)
	  {		
		return(0);
	   }
 }while(1);
close(sid);
 }

/*OUTPUT

enter the port number4545

c:hai
s:halo

c:quit
*/
