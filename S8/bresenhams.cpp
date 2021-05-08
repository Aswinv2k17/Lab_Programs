//BRESENHAM

#include<GL/glut.h>
#include<stdio.h>

int step;
float dx,dy,x0,y0,x1,y1,x,y,p;
void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void BRESENHAMS()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	x=x0;y=y0;
	dx=x1-x0;
	dy=y1-y0;
	p=(2*dy)-dx;
	for(int i=0;i<dx;i++)
	{
		if(p<0)
		{
			glVertex2i(++x,y);
			p=p+(2*dy);
		}
		else
		{
			glVertex2i(++x,++y);
			p=p+(2*dy)-(2*dx);
		}
	}
	glEnd();
	glFlush();
}

int main(int argc,char **argv)
{
	printf("Enter the coordinates");
	scanf("%f%f%f%f",&x0,&y0,&x1,&y1);
	glutInit(&argc,argv);
	glutInitWindowPosition(20,20);
	glutInitWindowSize(200,200);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("BRESENHAMS");
	init();
	glutDisplayFunc(BRESENHAMS);
	glutMainLoop();
	return 0;
}
