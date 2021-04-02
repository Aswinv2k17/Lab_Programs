//S7CS56
// GO BACK N ARQ
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
 int port,k=0,sock,wsize,pack,fno,s;
 int data[10]={1,2,3,4,5,6,7,8,9,10},tmp[10],ack[10];
 struct sockaddr_in saddr;

 sock=socket(AF_INET,SOCK_STREAM,0);
 	if(sock==-1)
	 {
	  printf("SOCKET CREATION ERROR\n");
	  return 0;
	 }

 printf("Enter a port no: \n");
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
 
 int n=accept(sock,(struct sockaddr *)&saddr,&d);
	
	printf("\n server waiting\n");
  
 int r=recv(n,(char *)&wsize,sizeof(wsize),0);
	printf("\nWINDOW SIZE : %d",wsize);

     r=recv(n,(char *)&pack,sizeof(pack),0);
	printf("\nPACK SIZE : %d",pack);

     r=recv(n,(char *)&fno,sizeof(fno),0);
	printf("\nFRAME NO : %d",fno);

  int count=0;
 while (count<fno)
 {
	r=recv(n,(char *)&k,sizeof(k),0);
 	if(k>pack)
	 {
		return 0;
	 }
	r=recv(n,tmp,sizeof(tmp),0);

	for(int i=0;i<wsize;i++)
	{
		if(k==pack-1)
		{
			printf("\ndata recieved %d",tmp[i]);
			break;
		}
		else
			printf("\ndata recieved %d",tmp[i]);

	}
	for(int i=0;i<wsize;i++)
	{
		if(k==pack-1)
		{
			printf("\nEnter the acknowledgement for the frame %d",i+1);
			scanf("%d",&ack[i]);break;
		}
		else
			{
				printf("\nEnter the acknowledgement of frame %d",i+1);
				scanf("%d",&ack[i]); 
			}
	}
	s=send(n,ack,sizeof(ack),0);
	r=recv(n,(char *)&count,sizeof(count),0);
 }
  printf("\n%d packets recieved successfully!!!",pack);
 }
/* OUTPUT
Enter a port no: 
4556

 server waiting

WINDOW SIZE : 2
PACK SIZE : 8
FRAME NO : 4
data recieved 1
data recieved 2
Enter the acknowledgement of frame 11

Enter the acknowledgement of frame 21

data recieved 3
data recieved 4
Enter the acknowledgement of frame 1-1

Enter the acknowledgement of frame 21

data recieved 3
data recieved 4
Enter the acknowledgement of frame 11

Enter the acknowledgement of frame 21

data recieved 5
data recieved 6
Enter the acknowledgement of frame 11

Enter the acknowledgement of frame 21

data recieved 7
data recieved 8
Enter the acknowledgement of frame 11

Enter the acknowledgement of frame 2-1

8 packets recieved successfully!!!  */



