//2 D transformation
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int v,x[10],y[10],i,xt[10],yt[10],ch,tx,ty,sx,sy;
int r;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void setPixel()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0);
	glBegin(GL_LINE_LOOP);
	for(i=0;i<v;i++)
	{
		glVertex2i(x[i],y[i]);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for(i=0;i<v;i++)
	{
		glVertex2i(xt[i],yt[i]);
	}
	glEnd();
	glFlush();
}

int main(int argc,char **argv)
{
	printf("Enter no:of vertices");
	scanf("%d",&v);
	printf("\n Enter the points to be plotted");
	for(i=0;i<v;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	printf("\n menu: \n 1.translation\n 2.scaling\n 3.rotation");
	printf("\n enter the choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			 printf("\n Perform translation");
			 printf("\nenter translation values");
			scanf("%d%d",&tx,&ty);
			for(i=0;i<v;i++)
			{
				xt[i]=x[i]+tx;
				yt[i]=y[i]+ty;
			}
			break;
		case 2:
			printf("\n Perform Scaling");
			 printf("\nenter scaling values");
			scanf("%d%d",&sx,&sy);
			for(i=0;i<v;i++)
			{
				xt[i]=x[i]*sx;
				yt[i]=y[i]*sy;
			}
			break;
		case 3:
			printf("\n Perform rotation");
			 printf("\nenter rotation angle");
			scanf("%d",&r);
			r=r*(3.14/180);
			for(i=0;i<v;i++)
			{
				xt[i]=(x[i]*cos(r))-(y[i]*sin(r));
				yt[i]=(x[i]*sin(r))+(y[i]*cos(r));
			}
			break;
	}
	glutInit(&argc,argv);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(200,200);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("2-D TRANS");
	init();
	glutDisplayFunc(setPixel);
	glutMainLoop();
	return 0;
}

