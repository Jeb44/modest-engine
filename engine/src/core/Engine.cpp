//GameWorldModule.cpp
#include "core/Engine.h"

namespace ME{
	
	Engine::Engine() {}
	Engine::~Engine() {}

	void Engine::StartUp(){
		Locator::getConsole()->print("Startup", "GameWorldModule");
	}
	void Engine::ShutDown(){
		Locator::getConsole()->print("Shutdown", "GameWorldModule");
	}

	
	IMessageHandler* Engine::GetParent() const{
		return nullptr;
	}

	void Engine::SendToChildren(const Message& msg){
		for(auto system : m_systems){
			msg.Send(system);
		}
	}

	void Engine::MainLoop(){
		Locator::getConsole()->print("Run", "GameWorldModule");
		
		B8 quitGame = false;

		const sf::Time timePerFrame(sf::seconds(1.0f / UPDATE_RATE));
		sf::Clock clock;
		sf::Time deltaTime = sf::Time::Zero;
		sf::Time lag = sf::microseconds(0.0f);

		while(!quitGame /*&& modRender->WindowsIsOpen()*/){
			// ProcessInputs();
			deltaTime += clock.restart();
			// lag += deltaTime;

			while (deltaTime > timePerFrame){
				// TODO: implent "bail out" when loop is run too often (to catch up)
				
				deltaTime -= timePerFrame;
				// ProcessInputs(); //should be "events"
				Update(timePerFrame);
			}
			
			// Render(); // lag / MS_PER_UPDATE
		}
	}

	void Engine::Update(sf::Time deltaTime){
		Locator::getConsole()->print("Update (" + Helper::toString(deltaTime.asMilliseconds()) + ")");
		for(size_t i = 0, iLen = m_systems.size(); i < iLen; i++){
			m_systems[i].Update(deltaTime /*, ObjectFacotry->GetObjectList()*/);
		}
	}

	void Engine::SendMessage(/* Message* msg*/){
		// ...
	}
}