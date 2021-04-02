//S7CS56
//FTP USING TCP
//SERVER
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
#include<string.h>
#include<fcntl.h>

int main()
{
	int port,fp,sock,n,p,r,len,s,flen,ch;
	struct sockaddr_in saddr;
	char rec[20],tmp[20],filesz[20],filetxt[200],msg[10],fname[10];
	struct stat obj;

	for(int i=0;i<200;i++)
		filetxt[i]='\0';
	
	sock=socket(AF_INET,SOCK_STREAM,0);
	printf("\nenter the port number");
	scanf("%d",&port);
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(port);
	saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	int b=bind(sock,(struct sockaddr *)&saddr,sizeof(saddr));
	if(b==-1)
	{perror("binding failed");return (0);}

	printf("\n server waiting\n");

	int l=listen(sock,10);//listen 
 	 if(l==-1)
		{
		 perror("listen failed");
		 return 0;
		}
  
	 int d=sizeof(saddr);
 
	 n=accept(sock,(struct sockaddr *)&saddr,&d);
	 strncpy(rec,"",20);
  
	 r=recv(n,rec,sizeof(rec),0);
	 if(r==-1)
	 {
		perror("\nrecieve failed");
		return 0;
	 }

	for(int i=0;i<4;i++)
	{
		tmp[i]=rec[i];
	}

	if(strcmp(tmp,"LIST")==0)
	{
		printf("\n...List operation..\n");
		system("Is-al>sendlist.txt");
		fp=open("sendlist.txt",O_RDONLY);
		stat("sendlist.txt",&obj);
		sprintf(filesz,"%d",(int)obj.st_size);
		
		s=send(n,filesz,sizeof(filesz),0);
		if(s==-1)
		{
		 perror("send failed");
		 return 0;
		}
	
		printf("\nFile size transfered\n");

		s=sendfile(n,fp,NULL,obj.st_size);
		if(s==-1)
		{
		 perror("\nsend file failed");
		 return 0;
		}
	}

	if(strcmp(tmp,"LOAD")==0)
	{
		printf("\n...Load operation..\n");
		strcpy(fname,rec+5);
		stat(fname,&obj);

		fp=open(fname,O_RDONLY);
		if(fp==-1)
		{
		 perror("\n FILE DOESN'T EXIST\n");
		 return 0;
		}
		
		sprintf(filesz,"%d",(int)obj.st_size);
		
		s=send(n,filesz,sizeof(filesz),0);
		if(s==-1)
		{
		 perror("send failed");
		 return 0;
		}
	
		printf("\nFile size transfered\n");

		s=sendfile(n,fp,NULL,obj.st_size);
		if(s==-1)
		{
		 perror("send file failed");
		 return 0;
		}
	}

	if(strcmp(tmp,"STOR")==0)
	{
		printf("\n...Store operation...\n");
		printf("\nEnter the file name:");
		scanf("%s",fname);

		s=send(n,fname,sizeof(fname),0);
		if(s==-1)
		{
		 perror("\nsend failed");
		 return 0;
		}

		fp=open("storefile.txt",O_RDWR|O_CREAT,0700);
		
		r=recv(n,filesz,sizeof(filesz),0);
		if(r==-1)
		{
		 perror("\nsend failed");
		 return 0;
		}

		flen=atoi(filesz);
		if(flen==0)
		{
		 printf("\nStore file empty");
		 return 0;
		}

		printf("\nfile size:%d\n",flen);

		printf("\nFile Contents\n");
		p=0;
		while(p<flen)
		{
			r=read(n,filetxt,sizeof(filetxt));
			if(r==0)
			{
			 break;
			}
			write(fp,filetxt,sizeof(filetxt));
			p++;
		}
		close(fp);
		printf("\nFile received\n");
		system("cat storefile.txt");
	}

}


/*OUTPUT

enter the port number1243

 server waiting

...Store operation...

Enter the file name:sum.c

file size:91

File Contents

File received
#include<stdio.h>
#include<stdlib.h>
void main()
{
int a=1,b=2,c;
c=a+b;
printf("%d",c);
}                    */		
