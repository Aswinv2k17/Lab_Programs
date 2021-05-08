//Mid-Point Circle
#include<GL/glut.h>
#include<stdio.h>
float r,x,y,p;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void MPC()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2i(0,r);
	x=0;y=r;
	p=1-r;
	while(x<=y)
	{
		if(p<0)
		{
			++x;
			glVertex2i(x,y);
			glVertex2i(-x,-y);
			glVertex2i(-x,y);
			glVertex2i(x,-y);
			glVertex2i(y,x);
			glVertex2i(-y,-x);
			glVertex2i(-y,x);
			glVertex2i(y,-x);
			p=p+((2*x)+2)+1;
		}
		else
		{
			++x;
			--y;
			glVertex2i(x,y);
			glVertex2i(-x,-y);
			glVertex2i(-x,y);
			glVertex2i(x,-y);
			glVertex2i(y,x);
			glVertex2i(-y,-x);
			glVertex2i(-y,x);
			glVertex2i(y,-x);
			p=p+((2*x)+2)+1-((2*y)+1);
		}
	}
	glEnd();
	glFlush();
}

int main(int argc,char **argv)
{
	printf("Enter the radius");
	scanf("%f",&r);
	glutInit(&argc,argv);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(200,200);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("MID-POINT CIRCLE");
	init();
	glutDisplayFunc(MPC);
	glutMainLoop();
	return 0;
}

