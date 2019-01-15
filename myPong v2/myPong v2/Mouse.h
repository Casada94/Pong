#ifndef myPONGv2_MOUSE
#define myPONGv2_MOUSE

#include "GLFW/glfw3.h"


class Mouse
{
public:
	static void MousePosCallback(GLFWwindow* window, double x, double y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	static double getMouseX();
	static double getMouseY();

	static bool buttonDown(int button);
	static bool buttonUp(int button);
	static bool button(int button);

private:
	static double mouseX;
	static double mouseY;

	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];

};


#endif
