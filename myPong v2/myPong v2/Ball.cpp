#include "Ball.h"
#include "GLFW/glfw3.h"
#include "Paddle.h"
#include "Engine.h"

#include <cstdlib> 
#include <ctime> 

#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

//Basic no-argument constructor
Ball::Ball()
{
	position = Vector2(500, 500);
	vec = Vector2(750, 1000);
	scalar = 10;
}

//single argument constructor
Ball::Ball(int sclr)
{
	position = Vector2(500, 500);
	vec = Vector2(750, 1000);
	scalar = sclr;
}

//two argument constructor
Ball::Ball(Vector2 vec, int sclr)
{
	position = Vector2(500, 500);
	this->vec = vec;
	scalar = sclr;
}

//3 argument constructor
Ball::Ball(Vector2 pos, Vector2 vec, int sclr)
{
	position = pos;
	this->vec = vec;
	scalar = sclr;
}

/*
The ball is the most important asset in the game. Thus its responsibilities are greatest

this function uses the other assets to determing what actions the ball should take,
whether to bounce of a side, paddle, or score a point.
*/
void Ball::Update(Field *field, Paddle *player, Paddle *CPU, int width, int height, bool *pause)
{
	srand((unsigned)time(0));
	int x = position.getX();
	int y = position.getY();
	int playPos = player->getPostion().getX();
	Vector2 deflect = player->getPostion() - player->getLastPos();
	int cpuPos = CPU->getPostion().getX();
	Vector2 deflectCPU = CPU->getPostion() - CPU->getLastPos();
	float dT = Engine::getDt();

	if (25 >= x)
	{
		setPosition(Vector2(25, y));
		if (vec.getX() < -500)
		{
			vec = vec + 100;
		}

		PlaySound(TEXT("hitWall.wav"), NULL, SND_FILENAME | SND_ASYNC);

		vec.invertX();
	}
	else if (x >= width - scalar)
	{
		setPosition(Vector2(width - scalar, y));
		if (vec.getX() > 500)
		{
			vec = vec - 100;
		}
		PlaySound(TEXT("hitWall.wav"), NULL, SND_FILENAME | SND_ASYNC);
		vec.invertX();
	}
	if (y <= 25)
	{
		if (field->isPointSide(0))
		{
			field->addPoint(1);
			setPosition(Vector2(500, 500));
			player->setPostion(Vector2(450, 50));
			*pause = true;

			PlaySound(TEXT("you_suck.wav"), NULL, SND_FILENAME | SND_ASYNC);

			int upDown[2] = { -1000,1000 };
			int leftRight[2] = { -1,1 };
			int i = rand() % 750;
			int x = rand() % 2;
			cout << i << endl;
			setVector(Vector2(i * leftRight[x], upDown[x]));
		}
		else
		{
			setPosition(Vector2(x, 25));
			vec.invertY();
		}
	}
	else if (y >= height - 10)
	{
		if (field->isPointSide(2))
		{
			field->addPoint(0);
			setPosition(Vector2(500, 500));
			player->setPostion(Vector2(450, 50));

			*pause = true;

			srand((unsigned)time(0));
			int upDown[2] = { -1000,1000 };
			int leftRight[2] = { -1,1 };
			int i = rand() % 750;
			int x = rand() % 2;
			cout << i << endl;
			setVector(Vector2(i * leftRight[x], upDown[i % 2]));
		}
		else
		{
			setPosition(Vector2(x, height - 10));
			vec.invertY();
		}
	}
	//hit detection	
	if ((x >= playPos && x <= (playPos + player->getLength())) && y < player->getPostion().getY() + 10 && y > player->getPostion().getY() - 20)
	{
		if ((vec.getX() + deflect.getX()) > 1350)
			vec = Vector2(1350, vec.getY());
		else if ((vec.getX() + deflect.getX()) < -1350)
			vec = Vector2(-1350, vec.getY());
		else
			vec = vec + (deflect * 100);

		setPosition(Vector2(x, player->getPostion().getY() + 10));

		PlaySound(TEXT("hitPaddle.wav"), NULL, SND_FILENAME | SND_ASYNC);
		vec.invertY();
	}
	if ((x >= cpuPos && x <= (cpuPos + CPU->getLength())) && y > CPU->getPostion().getY() - 10 && y < CPU->getPostion().getY() + 20)
	{
		if ((vec.getX() + deflectCPU.getX()) > 1350)
			vec = Vector2(1350, vec.getY());
		else if ((vec.getX() + deflectCPU.getX()) < -1350)
			vec = Vector2(-1350, vec.getY());
		else
			vec = vec + (deflectCPU * 100);

		PlaySound(TEXT("hitPaddle.wav"), NULL, SND_FILENAME | SND_ASYNC);
		setPosition(Vector2(x, CPU->getPostion().getY() - 10));

		vec.invertY();
	}
	position = position + (vec*dT);
}

//Draws the ball to the screen
void Ball::Render()
{
	int i;
	int triangleAmount = 10; //# of triangles used to draw circle
	GLfloat x = position.getX();
	GLfloat y = position.getY();
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

//SETTERS
void Ball::setScalar(int x)
{
	scalar = x;
}

void Ball::setVector(Vector2 x)
{
	vec = x;
}

void Ball::setPosition(Vector2 pos)
{
	position = pos;
}

//GETTERS
int Ball::getScalar()
{
	return scalar;
}

Vector2 Ball::getMovement()
{
	return vec;
}

Vector2 Ball::getPostion()
{
	return position;
}