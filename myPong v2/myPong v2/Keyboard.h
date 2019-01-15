#ifndef myPONGv2_KEYBOARD
#define myPONGv2_KEYBOARD

#include "GLFW/glfw3.h"

class Keyboard
{
public:
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool key(int key);
	static bool keyDown(int key);
	static bool keyUp(int key);

private:
	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];


};
#endif
