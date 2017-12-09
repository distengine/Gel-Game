#pragma once
#include <glad\glad.h>
#include <Gel\Graphics\Shapes\Cube.h>
#include <Gel\Systems\Camera.h>
#include <Gel\Systems\Window.h>
#include "InputManager.h"

class Game
{
public:
	Game();
	~Game();

	void start();
private:
	void preLoad();
	void addDefaultKeys();
	void openGLParams();
	void gameLoop();
	void update();
	void display();
private:
	gel::Window m_Window;
	gel::InputManager m_IOManager;
	gel::Cube m_Cube;
	gel::Camera m_Camera;
};