#include <string>
#include <iostream>
#include "Engine.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Ball.h"
#include "Paddle.h"
#include "Field.h"
#include <cstdlib> 
#include <ctime> 

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

int main()
{
	Engine engine;
	engine.Initialize("Pong");
	Field field = Field();
	Paddle player = Paddle(Vector2(450, field.getBottomLimit() + 40));
	Paddle CPU = Paddle(Vector2(450, field.getTopLimit() - 40), 1065, 150);
	Ball pong = Ball();
	
	bool pause = true;

	while (true) 
	{
		engine.Update();

		//allows for pausing of game
		if (!pause)
		{
			pong.Update(&field, &player, &CPU, field.getRightLimit(), field.getTopLimit(), &pause);
			player.Update();
			CPU.Update();
			field.Update();

			if (Keyboard::key(GLFW_KEY_A))
			{
				player.moveLeft(field.getLeftLimit());
			}
			if (Keyboard::key(GLFW_KEY_D))
			{
				player.moveRight(field.getRightLimit());
			}

		}

		//unpausing of game
		if (Keyboard::keyUp(GLFW_KEY_SPACE))
		{
			pause = !pause;
			
		}

		//end of game; start of new round
		if (field.getScore(1) >= 10)
		{
			pause = true;
			cout << "CPU Wins!" << endl;
			PlaySound(TEXT("good.wav"), NULL, SND_FILENAME | SND_ASYNC);
			field.resetScore();
		}else if (field.getScore(0) >= 10)
		{
			pause = true;
			cout << "Player Wins!" << endl;
			PlaySound(TEXT("you_will_die.wav"), NULL, SND_FILENAME | SND_ASYNC);
			field.resetScore();
		}

		//CPU logic for game decision making
		if (pong.getMovement().getY() > 0)		//ball going up
		{
			if (((CPU.getPostion().getX() + 75) < pong.getPostion().getX()) && pong.getPostion().getY() > 500)	//cpu to the left of ball
			{
				if (pong.getMovement().getX() < 0 && pong.getMovement().getY() < 500)		//ball moving left
				{
					

				}
				else if ((pong.getPostion().getX() > 650 && pong.getPostion().getY() < 350))		//ball will hit wall
				{
					if(pong.getMovement().getX() < 0)
						CPU.moveRight(field.getRightLimit());
					else
						CPU.moveLeft(field.getLeftLimit());
				}
				else
					CPU.moveRight(field.getRightLimit());
				
			}
			else if (((CPU.getPostion().getX() + 75) > pong.getPostion().getX()) && pong.getPostion().getY() > 500)	//cpu to the right of ball
			{
				if (pong.getMovement().getX() > 0 && pong.getMovement().getY() < 500)		//ball moving right
				{
				}
				else if ((pong.getPostion().getX() < 350 && pong.getPostion().getY() < 350))		//ball will hit wall
				{
					CPU.moveRight(field.getRightLimit());
				}									//ball moving left
				else	
				CPU.moveLeft(field.getLeftLimit());
			}
		}
		else if (pong.getMovement().getY() < 0)
		{
			if ((CPU.getPostion().getX() + 75) < 475)
				CPU.moveRight(field.getRightLimit());
			else if((CPU.getPostion().getX() + 75) > 525)
				CPU.moveLeft(field.getLeftLimit());
		}

		//Rendering of all objects
		engine.beginRender();
		field.Render();
		player.Render();
		CPU.Render();
		pong.Render();

		engine.endRender();
	}
	return 0;
}


