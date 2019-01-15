#include "Mouse.h"


double Mouse::mouseX = 0;
double Mouse::mouseY = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };



void Mouse::MousePosCallback(GLFWwindow* window, double x, double y)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	mouseX = x;
	mouseY = height - y;
}

void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button < 0)
		return;

	if (action != GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

	if (action == GLFW_RELEASE && buttons[button] == true)
	{
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;
}



double Mouse::getMouseX()
{
	return mouseX;
}

double Mouse::getMouseY()
{
	return mouseY;
}

bool Mouse::buttonDown(int button)
{
	bool x = buttonsDown[button];
	buttonsDown[button] = false;
	return x;

}

bool Mouse::buttonUp(int button)
{
	bool x = buttonsUp[button];
	buttonsUp[button] = false;
	return x;
}

bool Mouse::button(int button)
{
	return buttons[button];
}