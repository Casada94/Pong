#include "Field.h"
#include "GLFW/glfw3.h"

//default vertices
Vector2 vertA = Vector2(15, 15);
Vector2 vertB = Vector2(1015, 15);
Vector2 vertC = Vector2(1015, 1015);
Vector2 vertD = Vector2(15, 1015);


//
Field::Field()
{
	sides[0] = Side(1, 10, vertA, vertB);
	sides[1] = Side(0,10,vertB, vertC);
	sides[2] = Side(1,10, vertC, vertD);
	sides[3] = Side(0,10,vertD, vertA);
}

//
Field::Field(int t, int r, int b, int l)
{
	sides[0] = Side(t, 10, vertA, vertB);
	sides[1] = Side(r, 10, vertB, vertC);
	sides[2] = Side(b, 10, vertC, vertD);
	sides[3] = Side(l, 10, vertD, vertA);
}

//
Field::Field(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
	sides[0] = Side(1, 10, a, b);
	sides[1] = Side(0, 10, a, b);
	sides[2] = Side(1, 10, a, b);
	sides[3] = Side(0, 10, a, b);
}

//
Field::Field(int t, int r, int b, int l, Vector2 tl, Vector2 tr, Vector2 br, Vector2 bl)
{
	sides[0] = Side(t, 10, tl, tr);
	sides[1] = Side(r, 10, tr, br);
	sides[2] = Side(b, 10, br, bl);
	sides[3] = Side(l, 10, bl, tl);
}

//
void Field::Update()
{

}

//
void Field::Render()
{
	for (int i = 0; i < 4; i++)
		sides[i].Render();
}

//
void Field::setPointSide(int x, bool y)
{
	sides[x].setPoint(y);
}


//
bool Field::isPointSide(int x)
{
	return sides[x].getPoint();
}

//
int Field::getTopLimit()
{
	return sides[2].getVertA().getY();
}

//
int Field::getRightLimit()
{
	return sides[1].getVertA().getX();
}

//
int Field::getLeftLimit()
{
	return sides[3].getVertA().getX();
}

//
int Field::getBottomLimit()
{
	return sides[0].getVertA().getY();
}

