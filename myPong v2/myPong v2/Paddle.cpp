#include "GLFW/glfw3.h"
#include "Paddle.h"
#include <iostream>

using namespace std;

//argumentless constructor
Paddle::Paddle()
{
	position = Vector2(500, 50);
	speed = Vector2(5, 0);
	length = 50;
}

//constructor w/ non default speed
Paddle::Paddle(int spd)
{
	position = Vector2(500, 50);
	speed = Vector2(5, 0);
	length = 50;
}


//constructor to customize
Paddle::Paddle(int spd, int lng)
{
	position = Vector2(500, 50);
	speed = Vector2(5, 0);
	length = lng;
}

//
Paddle::Paddle(Vector2 pos, int spd, int lng)
{
	position = pos;
	speed = Vector2(5, 0);
	length = lng;
}

//
void Paddle::Update()
{
	lastPos = position;
}

//
void Paddle::Render()
{
	
	glColor3f(1, 1, 1);
	glLineWidth(30);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_LINES);
	glVertex2i(position.getX(), position.getY());
	glVertex2i(position.getX() + length, position.getY());

	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glFlush();
	
}

//
void Paddle::moveLeft(int width)
{
	Vector2 temp;
	lastPos = position;
	temp = position - speed;

	if (temp.getX() > width)
		position = temp;
}

//
void Paddle::moveRight(int width)
{
	Vector2 temp;
	lastPos = position;
	temp = position + speed;

	if (temp.getX() < (width- 50))
		position = temp;
	
}

//sets speed of paddle
void Paddle::setSpeed(int spd)
{
	speed = Vector2(spd, 0);
}

//sets scalar
void Paddle::setLength(int lng)
{
	length = lng;
}

//
void Paddle::setPostion(Vector2 pos)
{
	position = pos;
	lastPos = pos;
}

//returns speed of paddle
int Paddle::getSpeed()
{
	return speed.getX();
}

//returns scalar of paddle
int Paddle::getLength()
{
	return length;
}

//
Vector2 Paddle::getPostion()
{
	return position;
}

Vector2 Paddle::getLastPos()
{
	return lastPos;
}

