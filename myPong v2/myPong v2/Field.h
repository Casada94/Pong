#ifndef myPONGv2_FIELD
#define myPONGv2_FIELD

#include "Vector2.h"
#include "Side.h"

class Field
{
private:
	Side sides[4];
	int score[2];

public:
	//Constructors
	Field();
	Field(int t, int r, int b, int l);
	Field(Vector2 a, Vector2 b, Vector2 c, Vector2 d);
	Field(int t, int r, int b, int l, Vector2 tl, Vector2 tr, Vector2 br, Vector2 bl);

	void CPUscore();
	void playerScore();
	void resetScore();

	//GLFW STUFF
	void Update(int width, int height);
	void Render();


	//Setters
	void setPointSide(int x, bool y);
	void addPoint(int x);

	//Getters
	bool isPointSide(int x);
	int getTopLimit();
	int getRightLimit();
	int getLeftLimit();
	int getBottomLimit();
	int getScore(int x);

};

#endif
