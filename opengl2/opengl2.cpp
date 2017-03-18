#include <iostream>
#include <math.h>
#include <GL\freeglut.h>

using namespace std;
const double Pi = 3.1415926536;

void display_B_line() 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	int x0, x1, y0, y1;
	cin >> x0 >> y0 >> x1 >> y1;
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	bool flag = 1;
	if (dx < dy)
	{
		flag = 0;
		int t0 = x0, t1 = x1, td = dx;
		x0 = y0; x1 = y1;
		y0 = t0; y1 = t1;
		dx = dy; dy = td;
	}
	int p = 2 * dy - dx;
	int x = x0, y = y0;
	int xi = (x1 - x0) > 0 ? 1 : -1;
	int yi = (y1 - y0) > 0 ? 1 : -1;
	glBegin(GL_POINTS);
	glVertex2i(x0, y0);
	while (x != x1)
	{
		x += xi;
		if (p <= 0)
		{
			p += 2 * dy;
		}
		else
		{
			y += yi;
			p += 2 * dy - 2 * dx;
		}
		if (flag)
			glVertex2i(x, y);
		else
			glVertex2i(y, x);
	}
	glEnd();
	glFlush(); 
	cout << "complete" << endl;
} 

void display_B_circle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x0, y0, r;
	cin >> x0 >> y0 >> r;
	int x = 0, y = r;
	double d = 3 - 2 * r;
	glBegin(GL_POINTS);
	while (x <= y)
	{
		glVertex2i(x0 + x, y0 + y);
		glVertex2i(x0 + x, y0 - y);
		glVertex2i(x0 - x, y0 + y);
		glVertex2i(x0 - x, y0 - y);
		glVertex2i(x0 + y, y0 + x);
		glVertex2i(x0 + y, y0 - x);
		glVertex2i(x0 - y, y0 + x);
		glVertex2i(x0 - y, y0 - x);
		if (d < 0)
		{
			d += 4 * x + 6;
		}
		else
		{
			d += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	
	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Bresenham's ");
	gluOrtho2D(-500, 500, -500, 500);
	glutDisplayFunc(&display_B_circle);
	glutMainLoop();
	return 0;
}