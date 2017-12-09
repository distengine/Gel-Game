#pragma once
#include <Gel\Systems\KeyAction.h>
#include <Gel\Systems\Window.h>
#include <Gel\Systems\RealTimeAction.h>
#include <vector>

namespace gel
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();
		void AddKeyAction(gel::KeyAction keyAct);
		void AddRTAction(gel::RealTimeAction rta);
		gel::KeyAction& GetKeyAction(int index);
		gel::RealTimeAction& GetRTAction(int index);
		void ProcessKeyboardInput(const sf::Event& event);
		void ProcessMouseInput(const sf::Event& event);
		void ProcessRealTimeInput();
	private:
		std::vector<gel::KeyAction> m_Keys; // Keys are event based polling so only one event can be proccessed at a time
		std::vector<gel::RealTimeAction> m_Actions; // Actions are direct keyboard polling instead of event based polling
	};
}