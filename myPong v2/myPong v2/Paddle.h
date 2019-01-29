#ifndef myPONGv2_PADDLE
#define myPONGv2_PADDLE

#include "Vector2.h"

class Paddle
{
private:
	Vector2 position;
	Vector2 lastPos;
	Vector2 speed;
	int length;

public:
	//Constructors
	Paddle();
	Paddle(int spd);
	Paddle(Vector2 pos);
	Paddle(int spd, int lng);
	Paddle(Vector2 pos, int spd, int sclr);

	//GLFW STUFF
	void Update(int x);
	void Render();

	//Movement
	void moveLeft(int width);
	void moveRight(int width);

	//Setters
	void setSpeed(int spd);
	void setLength(int lng);
	void setPostion(Vector2 pos);

	//Getters
	int getSpeed();
	int getLength();
	Vector2 getPostion();
	Vector2 getLastPos();
};

#endif
