#include "Game.h"
#include <functional>
#include <iostream>
#include <glm\gtc\matrix_transform.hpp>

Game::Game()
{
}

Game::~Game()
{
}

void Game::start()
{
	m_Window.createWindow("Test", 50, 50, 800, 600, false);
	preLoad();
	gameLoop();
}

void Game::preLoad()
{
	openGLParams();
	addDefaultKeys();
	m_Cube.CreateCube();
	m_Camera.SetLookAt(glm::vec3(0, 0, 1), glm::vec3(0), glm::vec3(0, 1, 0));
	m_Camera.CreatePerspective(m_Camera.GetZoom(), static_cast<float>(m_Window.GetSize().x) / static_cast<float>(m_Window.GetSize().y), 0.1, 100.0);
}

void Game::addDefaultKeys()
{
	gel::KeyAction keyAction;
	gel::RealTimeAction rta;
	keyAction.SetAction(gel::Action::KeyDown);
	
	keyAction.SetKey(sf::Keyboard::Escape);
	std::function<void()> command = [&win = this->m_Window]() { win.close(); };
	keyAction.SetCommand(command);
	m_IOManager.AddKeyAction(keyAction);

	keyAction.SetAction(gel::Action::WheelMoved);
	std::function<void(double)> doubleCommand = [&cam = this->m_Camera](double delta) { cam.Zoom(delta); };
	keyAction.SetDoubleCommand(doubleCommand);
	m_IOManager.AddKeyAction(keyAction);

	rta.SetKey(sf::Keyboard::Up);
	command = [&cam = this->m_Camera]() {cam.Move(gel::CameraMovement::UP); };
	rta.SetCommand(command);
	m_IOManager.AddRTAction(rta);

	rta.SetKey(sf::Keyboard::Down);
	command = [&cam = this->m_Camera]() {cam.Move(gel::CameraMovement::DOWN); };
	rta.SetCommand(command);
	m_IOManager.AddRTAction(rta);

	rta.SetKey(sf::Keyboard::Left);
	command = [&cam = this->m_Camera]() {cam.Move(gel::CameraMovement::LEFT); };
	rta.SetCommand(command);
	m_IOManager.AddRTAction(rta);

	rta.SetKey(sf::Keyboard::Right);
	command = [&cam = this->m_Camera]() {cam.Move(gel::CameraMovement::RIGHT); };
	rta.SetCommand(command);
	m_IOManager.AddRTAction(rta);
}

void Game::openGLParams()
{
	glClearColor(.02f, 0.4f, 0.6f, 1.0f);
	glEnable(GL_DEPTH_TEST);
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
	glm::mat4 view, proj;
	view = m_Camera.GetView();
	proj = m_Camera.GetProjection();
	m_Cube.Update(view, proj);
	sf::Event e;
	while (m_Window.GetWindowRef().pollEvent(e))
	{
		m_IOManager.ProcessKeyboardInput(e);
		m_IOManager.ProcessMouseInput(e);
		m_IOManager.ProcessRealTimeInput();
		if (e.type == sf::Event::Closed)
		{
			m_Window.close();
		}
		if (e.type == sf::Event::Resized)
		{
			glViewport(0, 0, e.size.width, e.size.height);
			m_Camera.CreatePerspective(m_Camera.GetZoom(), static_cast<float>(m_Window.GetSize().x) / static_cast<float>(m_Window.GetSize().y), 0.1, 100.0);
			openGLParams();
		}
	}
}

void Game::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_Cube.Draw();
	m_Window.display();
}