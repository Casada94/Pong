#include "GLFW/glfw3.h"
#include "Paddle.h"
#include <iostream>
#include "Engine.h"

using namespace std;

//argumentless constructor
Paddle::Paddle()
{
	position = Vector2(500, 50);
	speed = Vector2(1000, 0);
	length = 150;
}

//single vector argument constructor
Paddle::Paddle(Vector2 pos)
{
	position = pos;
	speed = Vector2(1000, 0);
	length = 150;
}

//constructor w/ non default speed
Paddle::Paddle(int spd)
{
	position = Vector2(450, 50);
	speed = Vector2(spd, 0);
	length = 150;
}

//constructor to customize paddle values
Paddle::Paddle(int spd, int lng)
{
	position = Vector2(450, 50);
	speed = Vector2(spd, 0);
	length = lng;
}

//constructor to customize paddle values
Paddle::Paddle(Vector2 pos, int spd, int lng)
{
	position = pos;
	speed = Vector2(spd, 0);
	length = lng;
}

//Updates last position to tell if a player is moving or not
void Paddle::Update(int x)
{
	position.setY(x);
	lastPos = position;

}

//Draws players paddle to the screen
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

//Moves players paddle to the left 
void Paddle::moveLeft(int width)
{
	Vector2 temp;
	lastPos = position;
	temp = position - (speed*Engine::getDt());

	if (temp.getX() > width)
		position = temp;
}

//moves players paddle to the right
void Paddle::moveRight(int width)
{
	Vector2 temp;
	lastPos = position;
	temp = position + (speed*Engine::getDt());

	if (temp.getX() < (width - length))
		position = temp;

}

//SETTERS
void Paddle::setSpeed(int spd)
{
	speed = Vector2(spd, 0);
}

void Paddle::setLength(int lng)
{
	length = lng;
}

void Paddle::setPostion(Vector2 pos)
{
	position = pos;
	lastPos = pos;
}

//GETTERS
int Paddle::getSpeed()
{
	return speed.getX();
}

int Paddle::getLength()
{
	return length;
}

Vector2 Paddle::getPostion()
{
	return position;
}

Vector2 Paddle::getLastPos()
{
	return lastPos;
}

