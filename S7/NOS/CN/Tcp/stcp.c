//S7CS56
//TCP
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
 struct sockaddr_in saddr;
 int sid=socket(AF_INET,SOCK_STREAM,0);
 unsigned int port;
 printf("enter the port number");
 scanf("%d",&port);
 saddr.sin_family=AF_INET;
 saddr.sin_port=htons(port);
 saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 int b=bind(sid,(struct sockaddr *)&saddr,sizeof(saddr));//bind
 if(b==-1)
	{
	 perror("bind failed");
	 return 0;
	}
 int l=listen(sid,10);//listen 
 if(l==-1)
	{
	 perror("listen failed");
	return 0;
	}
  int d=sizeof(saddr);
 int a=accept(sid,(struct sockaddr *)&saddr,&d);
 do
  {
	int r=recv(a,buf,sizeof(buf),0);
	if(r==-1)
		{
			perror("recieve failed");
			return 0;
		}
	if(strcmp(tmp,"quit")==0)
		exit(0);
	   
	printf("\nc: %s",buf);
	printf("\ns:");
		scanf("%s",tmp);
		int s=send(a,tmp,sizeof(tmp),0);
		if(s==-1)
		{perror("send failed");return (0);}
	
  }while(1);
}


/*OUTPUT


enter the port number5656

c: hai
s:hai

c: quit
s:hai

c: quit
s:quit
       */
