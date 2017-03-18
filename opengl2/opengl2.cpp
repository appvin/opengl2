#include <iostream>
#include <math.h>
#include <GL\freeglut.h>

using namespace std;

int x0, x1, y00, y11, x2, y2, x3, y3;

void display_B_line(int x0, int y0, int x1, int y1)
{ 
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

	cout << "complete" << endl;
} 

void display_B_circle(int x0, int y0, int r)
{
	int x = 0, y = r;
	double d = 3 - 2 * r;
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
	cout << "complete" << endl;
}

void display_DDA_line(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0, dy = y1 - y0, steps, k;
	GLfloat xi, yi, x = GLfloat(x0), y = GLfloat(y0);

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xi = dx / (GLfloat)steps;
	yi = dy / (GLfloat)steps;
	glVertex2i(int(round(x)), int(round(y)));
	for (k = 0; k < steps; k++)
	{
		x += xi;
		y += yi;
		glVertex2i(int(round(x)), int(round(y)));
	}
	cout << "complete" << endl;
}

void display_DDA_circle(int x0, int y0, int r)
{
	int x = 0, y = r;
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
		x++;
		y = int(round(sqrt(pow(r, 2) - pow(x, 2))));
	}
	cout << "complete" << endl;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	display_B_line(x0, y00, x1, y11);
	display_B_circle(x0, y00, abs(x1));
	display_DDA_line(x2, y2, x3, y3);
	display_DDA_circle(x2, y2, abs(x3));
	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{

	cout << "all input" << endl;
	cin >> x0 >> y00 >> x1 >> y11 >> x2 >> y2 >> x3 >> y3;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(500, 500);
	glutCreateWindow("one window");
	gluOrtho2D(-500, 500, -500, 500);
	glutDisplayFunc(&display);
	glutMainLoop();
	return 0;
}