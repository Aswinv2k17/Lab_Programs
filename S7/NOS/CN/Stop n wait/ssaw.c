//S7CS56
//STOP AND WAIT
//SERVER 
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
 char rec[30],snd[30];
 struct sockaddr_in saddr;
 int port,sock,n,r,len,s,pack,ack=0,data;
 sock=socket(AF_INET,SOCK_STREAM,0);
 if(sock==-1)
 {
 perror("socket creation failed");return (0);
 }
 
 printf("enter the port number ");
  scanf("%d",&port);
 
 saddr.sin_family=AF_INET;
  saddr.sin_port=htons(port);
  saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 
 int b=bind(sock,(struct sockaddr *)&saddr,sizeof(saddr));//bind
  if(b==-1)
	{
	 perror("bind failed");
	 return 0;
	}
 
 int l=listen(sock,10);//listen 
  if(l==-1)
	{
	 perror("listen failed");
	 return 0;
	}
  
 int d=sizeof(saddr);
 
 n=accept(sock,(struct sockaddr *)&saddr,&d);
 printf("\n server waiting\n");
  
 r=recv(n,(char *)&pack,sizeof(pack),0);
 if(r==-1)
 {
	perror("recieve failed");
	return 0;
 }

	printf("\nNo.of packets : %d\n",pack);
 strncpy(snd,"send data",10);
	s=send(n,snd,sizeof(snd),0);
		if(s==-1)
		{perror("send failed");return (0);}
 for(int i=0;i<pack;i++)
  {
  do
    {
	r=recv(n,(char *)&data,sizeof(data),0);
 	if(r==-1)
	 {
		perror("recieve failed");
		return 0;
	 }
	printf("\nrecieved data : %d",data);
	printf("\nenter the aclnowledgement : ");
		scanf("%d",&ack);
	if(ack==-1)
		printf("\n Resend the last packet\n");

	s=send(n,(char *)&ack,sizeof(ack),0);
	if(s==-1)
	 {
	    perror("send failed");return (0);
	 }
    }while(ack==-1);
 }
 printf("\n%d packets recieved successfully!!!",pack);
}


/*OUTPUT

enter the port number 9876

 server waiting

No.of packets : 4

recieved data : 4
enter the aclnowledgement :1

recieved data : 6
enter the aclnowledgement :1

recieved data : 5
enter the aclnowledgement :-1

 Resend the last packet

recieved data : 5
enter the aclnowledgement :1

recieved data : 8
enter the aclnowledgement :1   

4 packets recieved successfully!!! */
