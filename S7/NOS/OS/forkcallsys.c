//Fork call system

#include<unistd.h>
#include<stdio.h>

void main()
{
	int p2,p3,p4,p5,p6,p7;
	p2=fork();
	if(p2==0)
	{
		p4=fork();
		if(p4==0)
		{
			printf("p4\t=%d\n",getpid());
		}
		else
		{
			p5=fork();
			if(p5==0)
			{
				printf("p5\t=%d\n",getpid());
			}
			else
			{
				printf("p2\t=%d\n",getpid());
			}
		}
	}
	else
	{
		p3=fork();
		if(p3==0)
		{
			p6=fork();
			if(p6==0)
			{
				printf("p6\t=%d\n",getpid());
			}
			else
			{
				p7=fork();
				if(p7==0)
					printf("p7\t=%d\n",getpid());
				else
					printf("p3\t=%d\n",getpid());
			}
		}
		else
		{
			printf("p1\t=%d\n",getpid());
		}
	}
}

/* OUTPUT
  =======
p1	=4498
p2	=4499
p5	=4502
p4	=4501
s7cs15@sys13:~$ p6	=4503
p3	=4500
p7	=4504*/
	 
