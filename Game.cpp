#include "Game.h"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::start()
{
	m_Window.createWindow("Test", 50, 50, 800, 400, false);
	preLoad();
	gameLoop();
}

void Game::preLoad()
{
	glClearColor(.02f, 0.4f, 0.6f, 1.0f);
}

void Game::gameLoop()
{
	while (m_Window.isOpen())
	{
		update();
		display();
	}
}

void Game::update()
{
	sf::Event e;
	while (m_Window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			m_Window.close();
		if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Escape)
			{
				m_Window.close();
			}
		}
	}
}

void Game::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	m_Window.display();
}