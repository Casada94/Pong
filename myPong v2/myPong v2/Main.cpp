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


	int cpuX;
	int pongX;
	int pongY;
	int pongMoveX;
	int pongMoveY;

	bool pause = true;

	while (true)
	{
		engine.Update();

		//allows for pausing of game
		if (!pause)
		{
			pong.Update(&field, &player, &CPU, field.getRightLimit(), field.getTopLimit(), &pause);
			player.Update(field.getBottomLimit() + 40);
			CPU.Update(field.getTopLimit() - 40);
			field.Update(engine.SCREEN_WIDTH, engine.SCREEN_HEIGHT);

			if (Keyboard::key(GLFW_KEY_A))
			{
				player.moveLeft(field.getLeftLimit());
			}
			if (Keyboard::key(GLFW_KEY_D))
			{
				player.moveRight(field.getRightLimit());
			}

			cpuX = CPU.getPostion().getX();
			//int cpuY = CPU.getPostion().getY();
			pongX = pong.getPostion().getX();
			pongY = pong.getPostion().getY();
			pongMoveX = pong.getMovement().getX();
			pongMoveY = pong.getMovement().getY();


			//CPU logic for game decision making
			if (pongMoveY > 0)		//ball going up
			{
				if (((cpuX + 75) < pongX) && pongY > 500)	//cpu to the left of ball
				{
					if (pongX < 0 && pongMoveY < 500)		//ball moving left
					{
					}
					else if ((pongX > 650 && pongY < 350))		//ball will hit wall
					{
						if (pongMoveX < 0)
							CPU.moveRight(field.getRightLimit());
						else
							CPU.moveLeft(field.getLeftLimit());
					}
					else
						CPU.moveRight(field.getRightLimit());

				}
				else if (((cpuX + 75) > pongX) && pongY > 500)	//cpu to the right of ball
				{
					if (pongMoveX > 0 && pongMoveY < 500)		//ball moving right
					{
					}
					else if ((pongX < 350 && pongY < 350))		//ball will hit wall
					{
						CPU.moveRight(field.getRightLimit());
					}									//ball moving left
					else
						CPU.moveLeft(field.getLeftLimit());
				}
			}
			else if (pongMoveY < 0)
			{
				if ((cpuX + 75) < ((field.getRightLimit() / 2) - 50))
					CPU.moveRight(field.getRightLimit());
				else if ((cpuX + 75) > field.getRightLimit() / 2)
					CPU.moveLeft(field.getLeftLimit());
			}
		}

		//unpausing of game
		if (Keyboard::keyUp(GLFW_KEY_SPACE))
		{
			pause = !pause;

		}

		//end of game; start of new round
		if (field.getScore(0) >= 10)
		{
			pause = true;
			cout << "CPU Wins!" << endl;
			PlaySound(TEXT("good.wav"), NULL, SND_FILENAME | SND_ASYNC);
			field.resetScore();
		}
		else if (field.getScore(1) >= 10)
		{
			pause = true;
			cout << "Player Wins!" << endl;
			PlaySound(TEXT("you_will_die.wav"), NULL, SND_FILENAME | SND_ASYNC);
			field.resetScore();
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



