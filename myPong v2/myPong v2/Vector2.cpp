#include "Vector2.h"
#include <iostream>

using namespace std;

//default constructor
Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

//two int argument constructor
Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

//copy constructor
Vector2::Vector2(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;
}

//SETTERS
void Vector2::setX(int a)
{
	x = a;
}

void Vector2::setY(int a)
{
	x = y;
}

//DIRECTIONAL CHANGE
void Vector2::invertX()
{
	x = x * -1;
}

void Vector2::invertY()
{
	cout << y << endl;
	this->y = this->y * (-1);
	cout << y << endl;
}

//GETTERS
int Vector2::getX()
{
	return x;
}

int Vector2::getY()
{
	return y;
}

int& Vector2::getXY()
{
	int temp[2] = { this->x, this->y };
	return *temp;
}

//OPERATOR OVERLOAD
Vector2& Vector2::operator=(const Vector2& other)
{
	this->x = other.x;
	this->y = other.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	Vector2 temp;
	temp.x = this->x + other.x;
	temp.y = this->y + other.y;
	return temp;
}

Vector2 Vector2::operator-(const Vector2& other)
{
	Vector2 temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;

	return temp;
}

Vector2 Vector2::operator-(const int other)
{
	Vector2 temp;
	temp.x = this->x - other;
	temp.y = this->y;
	return temp;
}

Vector2 Vector2::operator+(const int other)
{
	Vector2 temp;
	temp.x = this->x + other;
	temp.y = this->y;
	return temp;
}

Vector2 Vector2::operator%(const int& width)
{
	Vector2 temp;
	temp.x = this->x % width;
	temp.y = this->y % width;
	return temp;
}

Vector2 Vector2::operator*(float x1)
{
	Vector2 temp;
	temp.x = x * x1;
	temp.y = y * x1;
	return temp;
}
