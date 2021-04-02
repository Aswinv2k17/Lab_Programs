//S7CS56
//STOP AND WAIT
//CLIENT
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/un.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
int main()
 {
 char rec[30];
 struct sockaddr_in caddr;
 int sock=socket(AF_INET,SOCK_STREAM,0),l,n,data,pack,ack=0;
 if(sock==-1)
  {
 	perror("socket creation failed");return (0);
  }
 printf("enter the port number ");
  unsigned int port;
  scanf("%d",&port);

 caddr.sin_family=AF_INET;
  caddr.sin_port=htons(port);
  caddr.sin_addr.s_addr=inet_addr("127.0.0.1");

 int c=connect(sock,(struct sockaddr *)&caddr,sizeof(caddr));

 if(c==-1)
   {
	perror("connection failed");return (0);
   }

 printf("\nenter the no.of packets ");
 	scanf("%d",&pack);
	
 int s=send(sock,(char *)&pack,sizeof(pack),0);
	if(s==-1)
	{
	perror("send failed");return (0);
	}
	
 int r=recv(sock,rec,sizeof(rec),0);
	if(r==-1)
		{
			perror("recieve failed");
			return 0;
		}
 printf("\n%s ...",rec);
 for(int i=0;i<pack;i++)
 {
   printf("\ndata to send :");
	scanf("%d",&data);
   do
    {
		
	int s=send(sock,(char *)&data,sizeof(data),0);
	if(s==-1)
	 {
		perror("send failed");return (0);
	 }
	int r=recv(sock,(char *)&ack,sizeof(ack),0);
	if(r==-1)
		{
			perror("recieve failed");
			return 0;
		}
	printf("\nack of data %d : %d",data,ack);
	if(ack==-1)
	printf("\n resending data.....\n");
	
   }while(ack==-1);
 }
 printf("\n%d packets send successfully!!!",pack);
}
/*OUTPUT

enter the port number 9876

enter the no.of packets 4

send data ...
data to send :4
 
ack of data 4 : 1
data to send :6

ack of data 6 : 1
data to send :5

ack of data 5 : -1
 resending data.....

ack of data 5 : 1
data to send :8

ack of data 8 : 1

4 packets send successfully!!! */
