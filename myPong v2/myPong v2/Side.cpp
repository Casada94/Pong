#include "Side.h"
#include "GLFW/glfw3.h"

//base constructor
Side::Side()
{
	point = false;
	width = 10;
}

//single bool variable constructor
Side::Side(bool p)
{
	point = p;
	width = 10;
}

//single int variable constructor
Side::Side(int w)
{
	point = false;
	width = w;
}

//setting vertices
Side::Side(Vector2 a, Vector2 b)
{
	point = false;
	width = 10;
	vertA = a;
	vertB = b;
}

//full constructor
Side::Side(bool p, int w, Vector2 a, Vector2 b)
{
	point = p;
	width = w;
	vertA = a;
	vertB = b;
}


//sets whether or not a side is "solid" or will score a point
void Side::setPoint(bool p)
{
	point = p;
}

//sets width of side lines
void Side::setWidth(int w)
{
	width = w;
}

void Side::setVertices(Vector2 a, Vector2 b)
{
	vertA = a;
	vertB = b;
}

//returns point
bool Side::getPoint()
{
	return point;
}

//returns width value
int Side::getWidth()
{
	return width;
}

//
Vector2& Side::getVertices()
{
	Vector2 temp[2] = { vertA, vertB };
	return *temp;
}

//
Vector2 Side::getVertA()
{
	return vertA;
}

//
void Side::Render()
{
	glColor3f(1, 1, 1);
	glLineWidth(30);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_LINES);
	glVertex2i(vertA.getX(), vertA.getY());
	glVertex2i(vertB.getX(), vertB.getY());
	
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glFlush();
}

