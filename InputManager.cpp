#include "InputManager.h"
#include <SFML\Window\Event.hpp>

gel::InputManager::InputManager()
{
	
}

gel::InputManager::~InputManager()
{

}

void gel::InputManager::AddKeyAction(gel::KeyAction keyAct)
{
	m_Keys.push_back(keyAct);
}

void gel::InputManager::AddRTAction(gel::RealTimeAction rta)
{
	m_Actions.push_back(rta);
}

gel::KeyAction & gel::InputManager::GetKeyAction(int index)
{
	return m_Keys.at(index);
}

gel::RealTimeAction & gel::InputManager::GetRTAction(int index)
{
	return m_Actions.at(index);
}

void gel::InputManager::ProcessKeyboardInput(const sf::Event& event)
{
	// TODO : There maybe performance issue doing this check per key, instead of a global system
	for (auto & key : m_Keys)
	{
		if (event.type == static_cast<sf::Event::EventType>(key.GetAction()))
		{
			if (event.key.code == key.GetKey())
				key.GetCommand()();
		}
	}
}

void gel::InputManager::ProcessMouseInput(const sf::Event& event)
{
	for (auto & key : m_Keys)
	{
		if (event.type == sf::Event::MouseWheelMoved && static_cast<sf::Event::EventType>(key.GetAction()) == sf::Event::MouseWheelMoved)
		{
			key.GetDoubleCommand()(event.mouseWheel.delta);
		}
	}
}

void gel::InputManager::ProcessRealTimeInput()
{
	bool isPressed;
	for (auto & action : m_Actions)
	{
		isPressed = false;
		switch (action.GetActionType())
		{
		case gel::ActionType::KEY:
			if (sf::Keyboard::isKeyPressed(action.GetKey()))
				isPressed = true;
			break;
		case gel::ActionType::BUTTON:
			if (sf::Mouse::isButtonPressed(action.GetButton()))
				isPressed = true;
			break;
		}
		if (isPressed)
			action.GetCommand()();
	}
}