//S7CS56
//FTP USING TCP
//CLIENT
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/sendfile.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int port,fp,sock,l,p,r,len,s,flen,ch;
	struct sockaddr_in caddr;
	char rec[20],snd[20],filesz[20],filetxt[200],msg[10],fname[10];
	struct stat obj;

	for(int i=0;i<200;i++)
		filetxt[i]='\0';
	
	sock=socket(AF_INET,SOCK_STREAM,0);
	printf("enter the port number :");
	scanf("%d",&port);
	caddr.sin_family=AF_INET;
	caddr.sin_port=htons(port);
	caddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	int c=connect(sock,(struct sockaddr *)&caddr,sizeof(caddr));
	if(c==-1)
	{perror("connection failed");return (0);}

	printf("\n1.List\n\n2.Load\n\n3.Store\n\n-------------------------\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			{
				fp=open("listfile.txt",O_RDWR|O_CREAT,0700);
				strcpy(msg,"LIST");

				s=send(sock,msg,sizeof(msg),0);
				if(s==-1)
				{
				perror("send failed");return (0);
				}

				r=recv(sock,filesz,sizeof(filesz),0);
				if(r==-1)
				{
				perror("recieve failed");
				return 0;
				}
				
				printf("\n%d\n",atoi(filesz));
				flen=atoi(filesz);
				
				if(flen==0)
				{
				printf("List File Empty\n");
				return 0;
				}
				
				printf("File size:%d\n",flen);
				printf("CONTENT OF FILE\n");
				p=0;
				while(p<flen)
				{
					r=read(sock,filetxt,sizeof(filetxt));
					if(r==0)
						break;
					write(fp,filetxt,sizeof(filetxt));
					p++;
				}
				close(fp);
				printf("File Recieved\n");
				system("cat listfile.txt");
				break;
			}
		case 2:
			{
				fp=open("loadfile.txt",O_RDWR|O_CREAT,0700);
				strcpy(msg,"LOAD");
				strcat(msg,"");
				printf("\nenter the file name\n");
				scanf("%s",fname);
				strcat(msg,fname);

				s=send(sock,msg,sizeof(msg),0);
				if(s==-1)
				{
				perror("send failed");return (0);
				}

				r=recv(sock,filesz,sizeof(filesz),0);
				if(r==-1)
				{
				perror("recieve failed");
				return 0;
				}

				printf("\n%d\n",atoi(filesz));

				flen=atoi(filesz);
				if(flen==0)
				{
				printf("Load File Empty\n");
				return 0;
				}
				
				printf("File size:%d\n",flen);
				printf("CONTENT OF FILE\n");
				p=0;
				while(p<flen)
				{
					r=read(sock,filetxt,sizeof(filetxt));
					if(r==0)
						break;
					write(fp,filetxt,sizeof(filetxt));
					p++;
				}
				close(fp);
				printf("\nFile Recieved\n");
				system("cat loadfile.txt");
				break;
			}
		case 3:
			{
				strcpy(msg,"STORE");

				s=send(sock,msg,sizeof(msg),0);
				if(s==-1)
				{
				perror("send failed");return (0);
				}

				r=recv(sock,rec,sizeof(rec),0);
				if(r==-1)
				{
				perror("recieve failed");
				return 0;
				}

				printf("\nreceived file:%s\n",rec);
				stat(rec,&obj);
				

				fp=open(rec,O_RDONLY);

				sprintf(filesz,"%d",(int)obj.st_size);

				s=send(sock,filesz,sizeof(filesz),0);
				if(s==-1)
				{
				perror("send failed");return (0);
				}

				printf("FILE SIZE TRANSFERRED\n");
				if(fp==-1)
				{
					printf("FILE DOESNTEXIST\n");
					return 0;
				}
				s=sendfile(sock,fp,NULL,obj.st_size);
				if(s==-1)
				{
				perror("send failed");return (0);
				}

				printf("FILE SIZE TRANSFERRED\n");
				break;
			}
	}
 return 0;
}	

/*OUTPUT

enter the port number :1243

1.List

2.Load

3.Store

-------------------------
3

received file:sum.c
FILE SIZE TRANSFERRED
FILE SIZE TRANSFERRED      */
