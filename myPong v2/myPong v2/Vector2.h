#ifndef myPONGv2_VECTOR2
#define myPONGv2_VECTOR2

class Vector2
{
private:
	int x;
	int y;

public:
	Vector2();
	Vector2(int x, int y);
	Vector2(const Vector2& other);

	void invertX();
	void invertY();
	void setX(int a);
	void setY(int a);

	int getX();
	int getY();
	int& getXY();

	Vector2& operator=(const Vector2& other);
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator-(const int other);
	Vector2 operator+(const int other);
	Vector2 operator%(const int& width);
	Vector2 operator*(float x1);
};

#endif
