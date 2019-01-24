#include "Engine.h"
#include "Mouse.h"
#include "Keyboard.h"


int Engine::SCREEN_HEIGHT = 1200;
int Engine::SCREEN_WIDTH = 1150;
GLFWwindow* Engine::window = NULL;
float Engine::dt = 0;

Engine::Engine()
{

}

Engine::~Engine()
{


}


bool Engine::Initialize(const char* windowTitle)
{
	if (!glfwInit())
	{
		cout << "error initializing glfw" << endl;
		return false;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL)
	{
		cout << "Error Creating Window" << endl;
		return false;
	}

	//GLFW SETUP
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);

	glfwSetKeyCallback(window, Keyboard::keyCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPosition = (mode->width - SCREEN_HEIGHT) / 2;
	int yPosition = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPosition, yPosition);

	//GL SETUP
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	//ALPHA BLENDING
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastDt = (float)glfwGetTime();

	return true;
}

void Engine::Update()
{
	glfwGetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);

	float now = (float)glfwGetTime();
	dt = (now - lastDt);
	lastDt = now;
	glfwPollEvents();
}

void Engine::beginRender()
{

	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	//Drawing Area START

}


void Engine::endRender()
{
	glfwSwapBuffers(window);	//Drawing Area END

}

float Engine::getDt()
{
	return dt;
}