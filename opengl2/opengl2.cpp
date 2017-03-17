#include <iostream>
#include <GL\freeglut.h>

using namespace std;

void Display() 
{ 
	glClear(GL_COLOR_BUFFER_BIT);
	int x0, x1, y0, y1;
	//cin >> x0 >> y0 >> x1 >> y1;
	x0 = -100;
	x1 = 200;
	y0 = -100;
	y1 = 100;
	int dx = x1 - x0;
	int dy = y1 - y0;
	double m = dy / dx;
	glBegin(GL_POINTS);
	glVertex2i(x0, y0);
	int p = 2 * dy - dx;
	int x = x0, y = y0;
	while (x!=x1)
	{
		x = x + 1;
		if (p <= 0)
		{
			p += 2 * dy;
		}
		else
		{
			y = y + 1;
			p += 2 * dy - 2 * dx;
		}
		cout << x << " " << y << endl;
		glVertex2i(x, y);
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
	glutDisplayFunc(&Display);
	glutMainLoop();
	return 0;
}