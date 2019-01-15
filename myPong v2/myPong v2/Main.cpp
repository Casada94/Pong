#include <string>
#include <iostream>
#include "Engine.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Ball.h"
#include "Paddle.h"
#include "Field.h"

using namespace std;


int main()
{
	cout << "hello world" << endl;

	Engine engine;
	engine.Initialize("Pong");


	Field field = Field();
	Paddle player = Paddle();
	Ball pong = Ball();
	

	while (true) {
		engine.Update();
		player.Update();
		field.Update();
		pong.Update(player, field.getRightLimit(), field.getTopLimit());
		
		//testSprite.setPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
		/*
		if (Mouse::buttonDown(GLFW_MOUSE_BUTTON_LEFT))
		{
			testSprite.rotateBy(100);
		}
		if (Mouse::buttonUp(GLFW_MOUSE_BUTTON_RIGHT))
		{
			testSprite.rotateBy(-100);
		}

		if (Mouse::button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			testSprite.rotateBy(-100);
		}
		
		if (Keyboard::key(GLFW_KEY_W))
		{
			testSprite.moveUp();
		}
		if (Keyboard::key(GLFW_KEY_S))
		{
			testSprite.moveDown();
		}*/
		if (Keyboard::key(GLFW_KEY_A))
		{
			player.moveLeft(field.getLeftLimit());
		}
		if (Keyboard::key(GLFW_KEY_D))
		{
			player.moveRight(field.getRightLimit());
		}

		engine.beginRender();
		field.Render();
		player.Render();
		pong.Render();

		engine.endRender();

	}


	return 0;
}