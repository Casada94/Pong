#include "Field.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <String>

using namespace std;

//default vertices
Vector2 vertA = Vector2(15, 15);
Vector2 vertB = Vector2(1015, 15);
Vector2 vertC = Vector2(1015, 1185);
Vector2 vertD = Vector2(15, 1185);


//Basic no argument constructor
Field::Field()
{
	score[0] = 0;
	score[1] = 0;
	sides[0] = Side(1, 10, vertA, vertB);
	sides[1] = Side(0,10,vertB, vertC);
	sides[2] = Side(1,10, vertC, vertD);
	sides[3] = Side(0,10,vertD, vertA);
}

//4 argument constructor for setting what sides will count for points
Field::Field(int t, int r, int b, int l)
{
	score[0] = 0;
	score[1] = 0;
	sides[0] = Side(t, 10, vertA, vertB);
	sides[1] = Side(r, 10, vertB, vertC);
	sides[2] = Side(b, 10, vertC, vertD);
	sides[3] = Side(l, 10, vertD, vertA);
}

//4 argument constructo for setting the vertexes of the field
Field::Field(Vector2 a, Vector2 b, Vector2 c, Vector2 d)
{
	score[0] = 0;
	score[1] = 0;
	sides[0] = Side(1, 10, a, b);
	sides[1] = Side(0, 10, a, b);
	sides[2] = Side(1, 10, a, b);
	sides[3] = Side(0, 10, a, b);
}

//8 argument constructor for setting vertices and if sides score points
Field::Field(int t, int r, int b, int l, Vector2 tl, Vector2 tr, Vector2 br, Vector2 bl)
{
	score[0] = 0;
	score[1] = 0;
	sides[0] = Side(t, 10, tl, tr);
	sides[1] = Side(r, 10, tr, br);
	sides[2] = Side(b, 10, br, bl);
	sides[3] = Side(l, 10, bl, tl);
}

//
void Field::Update()
{

}

//Calls side's render function to draw all four sides of a the field
void Field::Render()
{
	for (int i = 0; i < 4; i++)
		sides[i].Render();

	glColor3f(1, 1, 1);
	glLineWidth(10);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_LINES);
	CPUscore();
	playerScore();

	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glFlush();
}

//vertices for CPU score numbers
void Field::CPUscore()
{
	switch (score[0])
	{
	case 0:
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1050, 20);		//bottom left vert
		glVertex2i(1100, 120);		//top right vert
		glVertex2i(1100, 20);		//bottom right vert
		glVertex2i(1050, 120);
		glVertex2i(1100, 120);
		glVertex2i(1050, 20);
		glVertex2i(1100, 20);
		break;
	case 1: 
		glVertex2i(1075, 120);
		glVertex2i(1075, 20);
		break;
	case 2:
		glVertex2i(1050, 120);
		glVertex2i(1100, 120);
		glVertex2i(1100, 120);
		glVertex2i(1100, 70);			//right middle vert
		glVertex2i(1100, 70);
		glVertex2i(1050, 70);			//left middle vert
		glVertex2i(1050, 70);
		glVertex2i(1050, 20);
		glVertex2i(1050, 20);
		glVertex2i(1100, 20);
		break;
	case 3:
		glVertex2i(1050, 120);
		glVertex2i(1100, 120);
		glVertex2i(1100, 120);
		glVertex2i(1100, 70);
		glVertex2i(1100, 70);
		glVertex2i(1075, 70);		//center middle
		glVertex2i(1100, 70);
		glVertex2i(1100, 20);		//bottom right vert
		glVertex2i(1100, 20);		//bottom right vert
		glVertex2i(1050, 20);		//bottom left vert
		break;
	case 4:
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1050, 70);			//left middle vert
		glVertex2i(1050, 70);			//left middle vert
		glVertex2i(1100, 70);			//right middle vert
		glVertex2i(1100, 120);		//top right vert
		glVertex2i(1100, 20);		//bottom right vert
		break;
	case 5:
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1100, 120);		//top right vert
		glVertex2i(1050, 120);			//top left vert
		glVertex2i(1050, 70);			//left middle vert
		glVertex2i(1050, 70);		//left middle vert
		glVertex2i(1100, 70);		//right middle vert
		glVertex2i(1100, 70);			//right middle vert
		glVertex2i(1100, 20);			//bottom right vert
		glVertex2i(1100, 20);		//bottom right vert
		glVertex2i(1050, 20);		//bottom left vert
		break;
	case 6:
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1100, 120);		//top right vert
		glVertex2i(1050, 120);			//top left vert
		glVertex2i(1050, 20);			//bottom left vert
		glVertex2i(1050, 20);		//bottom left vert
		glVertex2i(1100, 20);		//bottom right vert
		glVertex2i(1100, 20);			//bottom right vert
		glVertex2i(1100, 70);			//right middle vert
		glVertex2i(1100, 70);		//right middle vert
		glVertex2i(1050, 70);		//left middle vert
		break;
	case 7:
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1100, 120);		//top right vert
		glVertex2i(1100, 120);			//top right vert
		glVertex2i(1100, 20);			//bottom right vert
		break;
	case 8:
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1050, 20);		//bottom left vert
		glVertex2i(1100, 120);			//top right vert
		glVertex2i(1100, 20);			//bottom right vert
		glVertex2i(1050, 120);
		glVertex2i(1100, 120);
		glVertex2i(1050, 20);
		glVertex2i(1100, 20);
		glVertex2i(1100, 70);		//right middle vert
		glVertex2i(1050, 70);		//left middle vert
		break;
	case 9:
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1100, 120);		//top right vert
		glVertex2i(1050, 120);		//top left vert
		glVertex2i(1050, 70);		//left middle vert
		glVertex2i(1050, 70);		//left middle vert
		glVertex2i(1100, 70);		//right middle vert
		glVertex2i(1100, 120);		//top right vert
		glVertex2i(1100, 20);			//bottom right vert
		break;
	case 10:
		glVertex2i(1075, 120);		//top left vert
		glVertex2i(1075, 20);		//bottom left vert
		glVertex2i(1110, 120);		//top right vert
		glVertex2i(1110, 20);		//bottom right vert
		glVertex2i(1075, 120);
		glVertex2i(1110, 120);
		glVertex2i(1075, 20);
		glVertex2i(1110, 20);
		glVertex2i(1045, 120);
		glVertex2i(1045, 20);
		break;
	default:{}
		
	}
}

//vertices for players score numbers
void Field::playerScore()
{
	switch (score[1])
	{
	case 0:
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1050, 910);		//bottom left vert
		glVertex2i(1100, 1010);		//top right vert
		glVertex2i(1100, 910);		//bottom right vert
		glVertex2i(1050, 1010);
		glVertex2i(1100, 1010);
		glVertex2i(1050, 910);
		glVertex2i(1100, 910);
		break;
	case 1:
		glVertex2i(1075, 1010);
		glVertex2i(1075, 910);
		break;
	case 2:
		glVertex2i(1050, 1010);
		glVertex2i(1100, 1010);
		glVertex2i(1100, 1010);
		glVertex2i(1100, 960);			//right middle vert
		glVertex2i(1100, 960);
		glVertex2i(1050, 960);			//left middle vert
		glVertex2i(1050, 960);
		glVertex2i(1050, 910);
		glVertex2i(1050, 910);
		glVertex2i(1100, 910);
		break;
	case 3:
		glVertex2i(1050, 1010);
		glVertex2i(1100, 1010);
		glVertex2i(1100, 1010);
		glVertex2i(1100, 960);
		glVertex2i(1100, 960);
		glVertex2i(1075, 960);		//center middle
		glVertex2i(1100, 960);
		glVertex2i(1100, 910);		//bottom right vert
		glVertex2i(1100, 910);		//bottom right vert
		glVertex2i(1050, 910);		//bottom left vert
		break;
	case 4:
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1050, 960);			//left middle vert
		glVertex2i(1050, 960);			//left middle vert
		glVertex2i(1100, 960);			//right middle vert
		glVertex2i(1100, 1010);		//top right vert
		glVertex2i(1100, 910);		//bottom right vert
		break;
	case 5:
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1100, 1010);		//top right vert
		glVertex2i(1050, 1010);			//top left vert
		glVertex2i(1050, 960);			//left middle vert
		glVertex2i(1050, 960);		//left middle vert
		glVertex2i(1100, 960);		//right middle vert
		glVertex2i(1100, 960);			//right middle vert
		glVertex2i(1100, 910);			//bottom right vert
		glVertex2i(1100, 910);		//bottom right vert
		glVertex2i(1050, 910);		//bottom left vert
		break;
	case 6:
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1100, 1010);		//top right vert
		glVertex2i(1050, 1010);			//top left vert
		glVertex2i(1050, 910);			//bottom left vert
		glVertex2i(1050, 910);		//bottom left vert
		glVertex2i(1100, 910);		//bottom right vert
		glVertex2i(1100, 910);			//bottom right vert
		glVertex2i(1100, 960);			//right middle vert
		glVertex2i(1100, 960);		//right middle vert
		glVertex2i(1050, 960);		//left middle vert
		break;
	case 7:
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1100, 1010);		//top right vert
		glVertex2i(1100, 1010);			//top right vert
		glVertex2i(1100, 910);			//bottom right vert
		break;
	case 8:
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1050, 910);		//bottom left vert
		glVertex2i(1100, 1010);			//top right vert
		glVertex2i(1100, 910);			//bottom right vert
		glVertex2i(1050, 1010);
		glVertex2i(1100, 1010);
		glVertex2i(1050, 910);
		glVertex2i(1100, 910);
		glVertex2i(1100, 960);		//right middle vert
		glVertex2i(1050, 960);		//left middle vert
		break;
	case 9:
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1100, 1010);		//top right vert
		glVertex2i(1050, 1010);		//top left vert
		glVertex2i(1050, 960);		//left middle vert
		glVertex2i(1050, 960);		//left middle vert
		glVertex2i(1100, 960);		//right middle vert
		glVertex2i(1100, 1010);		//top right vert
		glVertex2i(1100, 910);			//bottom right vert
		break;
	case 10:
		glVertex2i(1075, 1010);		//top left vert
		glVertex2i(1075, 910);		//bottom left vert
		glVertex2i(1110, 1010);		//top right vert
		glVertex2i(1110, 910);		//bottom right vert
		glVertex2i(1075, 1010);
		glVertex2i(1110, 1010);
		glVertex2i(1075, 910);
		glVertex2i(1110, 910);
		glVertex2i(1045, 1010);
		glVertex2i(1045, 910);
		break;
	default: {}

	}
}




//Sets a given side to be point scoring or not
void Field::setPointSide(int x, bool y)
{
	sides[x].setPoint(y);
}


//checks if a side is point scoring or not
bool Field::isPointSide(int x)
{
	return sides[x].getPoint();
}

//adds to the field score
void Field::addPoint(int x)
{
	score[x]++;
}

void Field::resetScore()
{
	score[0] = 0;
	score[1] = 0;
}

//GETTERS
int Field::getTopLimit()
{
	return sides[2].getVertA().getY();
}

int Field::getRightLimit()
{
	return sides[1].getVertA().getX();
}

int Field::getLeftLimit()
{
	return sides[3].getVertA().getX();
}

int Field::getBottomLimit()
{
	return sides[0].getVertA().getY();
}

int Field::getScore(int x)
{
	return score[x];
}



