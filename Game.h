#pragma once
#include <glad\glad.h>
#include <Gel\Systems\Window.h>

class Game
{
public:
	Game();
	~Game();

	void start();
private:
	void preLoad();
	void gameLoop();
	void update();
	void display();
private:
	gel::Window m_Window;
};