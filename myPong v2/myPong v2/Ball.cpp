#include "Ball.h"
#include "GLFW/glfw3.h"
#include "Paddle.h"
#include <iostream>

using namespace std;

Ball::Ball()
{
	position = Vector2(500, 500);
	vec = Vector2(5, 5);
	scalar = 10;
}


Ball::Ball(int sclr)
{
	position = Vector2(500, 500);
	vec = Vector2(5, 5);
	scalar = sclr;
}

Ball::Ball(Vector2 vec, int sclr)
{
	position = Vector2(500, 500);
	this->vec = vec;
	scalar = sclr;
}

//
Ball::Ball(Vector2 pos, Vector2 vec, int sclr)
{
	position = pos;
	this->vec = vec;
	scalar = sclr;
}

//
void Ball::Update(Paddle player, int width, int height)
{
	int x = position.getX();
	int y = position.getY();
	int playPos = player.getPostion().getX();
	Vector2 deflect = player.getPostion() - player.getLastPos();

	if (25 >= x || x >= width - 10)
		vec.invertX();
	if (y <= 25 || y >= height-10)
		vec.invertY();
	if ((x >= playPos && x <= (playPos + player.getLength())) && player.getPostion().getY() + 5 == y)
	{
		vec = vec + deflect % 7;
		vec.invertY();
	}
		
	
	position = (position + vec);

}

//
void Ball::Render()
{
	int i;
	int triangleAmount = 40; //# of triangles used to draw circle
	GLfloat x = position.getX();
	GLfloat y = position.getY();
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (scalar * cos(i *  twicePi / triangleAmount)),
			y + (scalar * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	glFlush();
}

//setting ball size
void Ball::setScalar(int x)
{
	scalar = x;
}

//setting ball movement/direction vector
void Ball::setVector(Vector2& x)
{
	vec = x;
}

//
void Ball::setPosition(Vector2 pos)
{
	position = pos;
}

//getting ball size
int Ball::getScalar()
{
	return scalar;
}

//getting entire vector
Vector2 Ball::getMovement()
{
	return vec;
}

Vector2 Ball::getPostion()
{
	return position;
}