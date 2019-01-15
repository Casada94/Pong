#ifndef myPONGv2_SIDE
#define myPONGv2_SIDE

#include"Vector2.h"

class Side
{
private:
	bool point;
	int width;
	Vector2 vertA;
	Vector2 vertB;

public:
	//Constructors
	Side();
	Side(bool p);
	Side(int w);
	Side(Vector2 vertA, Vector2 vertB);
	Side(bool p, int w, Vector2 vertA, Vector2 vertB);
	
	//Setters
	void setPoint(bool p);
	void setWidth(int w);
	void setVertices(Vector2 vertA, Vector2 vertB);

	//Getters
	bool getPoint();
	int getWidth();
	Vector2& getVertices();
	Vector2 getVertA();
	
	//DRAW
	void Render();

};

#endif
