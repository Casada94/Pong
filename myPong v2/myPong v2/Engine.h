#ifndef myPONGv2_ENGINE
#define myPONGv2_ENGINE


#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")
#include <iostream>

using namespace std;

class Engine
{
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	~Engine();

	bool Initialize(const char* windowTitle);

	void Update();
	void beginRender();
	void endRender();

	static float getDt();


private:
	static GLFWwindow* window;

	static float dt;
	float lastDt;
};


#endif
