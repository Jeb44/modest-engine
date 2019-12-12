//GameWorldModule.h
#pragma once
#include "common/typedef.h"
#include "common/assert.h"

#include "common/Locator.h"
#include "common/console/Console.h"
#include "common/Helper.h"

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <vector>
#include "core/Entity.h"
#include "SFML/Graphics.hpp"

#include "core/System.h"
#include "core/message/Message.h"
#include "core/message/IMessageHandler.h"

#include "core/RenderModule.h"

#define UPDATE_RATE 60.0f

namespace ME{
	class Engine : public IMessageHandler {
	public:
		explicit Engine();
		virtual ~Engine();

		
		void StartUp(); //final so okay?
		void ShutDown();
		
		virtual IMessageHandler* GetParent() const;
		virtual void SendToChildren(const Message& msg);

		void MainLoop();
		void Update(sf::Time deltaTime);
		void AddSystem(System* system);
		void SendMessage(/* Message* msg*/);


	private:
		// void ProcessInputs(); // input system
		// void Render(); // graphic system

		std::vector<System> m_systems;
	};
}

