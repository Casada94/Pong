#ifndef myPONGv2_BALL
#define myPONGv2_BALL

#include "Vector2.h"
#include "Field.h"
#include "Math.h"
#include "Paddle.h"
#include <iostream>

class Ball
{
private:
	Vector2 position;
	Vector2 vec;
	int scalar;

public:
	//Constructors
	Ball();
	Ball(int sclr);
	Ball(Vector2 vec, int sclr);
	Ball(Vector2 pos, Vector2 vec, int sclr);

	void Update(Paddle player, int width, int height);
	void Render();


	//Setters
	void setScalar(int x);
	void setVector(Vector2& x);
	void setPosition(Vector2 pos);

	//Getters
	int getScalar();
	Vector2 getMovement();
	Vector2 getPostion();
};


#endif