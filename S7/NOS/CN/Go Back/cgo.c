//S7CS56
//GO BACK N ARQ
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
 int port,sock,wsize,r,k=0,pack,fno,i;
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

 int c=connect(sock,(struct sockaddr *)&saddr,sizeof(saddr));
 if(c==-1)
 	{perror("connection failed");return (0);}

 printf("\nEnter the window size\n");
 scanf("%d",&wsize);
 
 int s=send(sock,(char *)&wsize,sizeof(wsize),0);
	if(s==-1)
	{
	perror("send failed");return (0);
	}

 printf("\nEnter the packets number\n");
 scanf("%d",&pack);
 s=send(sock,(char *)&pack,sizeof(pack),0);
	if(s==-1)
	{
	perror("send failed");return (0);
	}

 fno=pack/wsize;
 s=send(sock,(char *)&fno,sizeof(fno),0);
	if(s==-1)
	{
	perror("send failed");return (0);
	}

 int count=0;
 while (count<fno)
 {
   s=send(sock,(char *)&k, sizeof(k),0);
   if(k>pack)
	return 0;

   for(int i=0;i<wsize;i++)
   { 
     	if (k==pack-1)
	{
		tmp[i]=data[k];
		break;
	}
	else
		tmp[i]=data[k++];
   }
  count++;
  s=send(sock,tmp,sizeof(tmp),0);

  r=recv(sock,ack,sizeof(ack),0);

	for(i=0;i<wsize;i++)
	{
		printf("\nack of data %d : %d",tmp[i],ack[i]);
		if(ack[i]==-1)
		{
			if(k==pack-1)
			{printf("\n resending data from %d\n",k+1);
			count--;break;}
			else
			{
				printf("\n resending data from %d\n",tmp[i]);
				if(i==0)
				{
					k=k-wsize;
				}
				else
					k--;
				count=count-1;
				break;
			}
		}
		else
		{	
			if(k==pack-1)
				break;
		}
	}
	s=send(sock,(char *)&count,sizeof(count),0);
	if(k==pack)
		break;
 }
 printf("\n%d packets send successfully!!!",pack);
}
/* OUTPUT
Enter a port no: 
4556

Enter the window size
2

Enter the packets number
8

ack of data 1 : 1
ack of data 2 : 1
ack of data 3 : -1
 resending data from 3

ack of data 3 : 1
ack of data 4 : 1
ack of data 5 : 1
ack of data 6 : 1
ack of data 7 : 1
8 packets send successfully!!!  */
