//GameWorldModule.cpp
#include "core/GameWorldModule.h"
#include "common/Locator.h"
#include "common/console/Console.h"
#include "common/Helper.h"

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System.hpp>

#include <iostream>

namespace ME{
	
	GameWorldModule::GameWorldModule() {}
	GameWorldModule::~GameWorldModule() {}

	void GameWorldModule::StartUp(){
		Locator::getConsole()->print("Startup", "GameWorldModule");

		window = new sf::RenderWindow(sf::VideoMode(640, 480), "Modest-Engine");
		
		texPlayer = new sf::Texture();
		if(!texPlayer->loadFromFile("../graphics/me_github_preview.png")){
			// Handle loading error
		}

		sprPlayer = new sf::Sprite(*texPlayer);
		sprPlayer->setPosition(100.0f, 100.0f);
	}
	void GameWorldModule::ShutDown(){
		Locator::getConsole()->print("Shutdown", "GameWorldModule");
		
		if(window->isOpen()){
			window->close();
		}
	}

	void GameWorldModule::Run(){
		Locator::getConsole()->print("Run", "GameWorldModule");
		
		B8 quitGame = false;

		const sf::Time TimePerFrame(sf::seconds(1.0f / 60.0f));
		sf::Clock clock;
		sf::Time deltaTime = sf::Time::Zero;
		sf::Time lag = sf::microseconds(0.0f);

		while(!quitGame && window->isOpen()){
			ProcessInputs();
			deltaTime += clock.restart();
			// lag += deltaTime;

			while (deltaTime > TimePerFrame){
				// TODO: implent "bail out" when loop is run too often (to catch up)
				
				deltaTime -= TimePerFrame;
				ProcessInputs(); //should be "events"
				Update(TimePerFrame);
			}
			
			Render(); // lag / MS_PER_UPDATE
		}
	}

	void GameWorldModule::AddEntity(Entity* entity){
		entities.push_back(entity);
	}


	bool GameWorldModule::RemoveEntity(Entity* entity){
		const auto removedComponent = std::find(
			entities.begin(), 
			entities.end(), 
			entity
		);

		const bool isFound = removedComponent != entities.end();
		if(isFound){
			entities.erase(removedComponent);
		}

		return isFound;
	}

	std::vector<Entity*> GameWorldModule::GetEnties(){
		return entities;
	}

	void GameWorldModule::ProcessInputs(){
		// Locator::getConsole()->print("Process Inputs");

		sf::Event event;
		while(window->pollEvent(event)){
			switch(event.type){
				case sf::Event::KeyPressed:
					HandlePlayerInput(event.key.code, true);
					break;
				case sf::Event::KeyReleased:
					HandlePlayerInput(event.key.code, false);
					break;
				case sf::Event::Closed:
					window->close();
					break;
				}
			}
		}
	

	void GameWorldModule::Update(sf::Time deltaTime){
		Locator::getConsole()->print("Update (" + Helper::toString(deltaTime.asMilliseconds()) + ")");
		for(size_t i = entities.size() - 1, iLen = 0; i <= iLen; i--){
			entities[i]->OnUpdate();
		}

		sf::Vector2f movement(0.0f, 0.0f);
		if(isMovingUp){
			movement.y -= 1.0f;
		}
		if(isMovingDown){
			movement.y += 1.0f;
		}
		if(isMovingLeft){
			movement.x -= 1.0f;
		}
		if(isMovingRight){
			movement.x += 1.0f;
		}

		sprPlayer->move(movement * deltaTime.asSeconds() * 10.0f);
	}

	void GameWorldModule::Render(){
		// Locator::getConsole()->print("Render");
		window->clear();
		window->draw(*sprPlayer);
		window->display();
	}

	void GameWorldModule::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed){
		if(key == sf::Keyboard::W){
			isMovingUp = isPressed;
		}
		else if(key == sf::Keyboard::S){
			isMovingDown = isPressed;
		}
		else if(key == sf::Keyboard::A){
			isMovingLeft = isPressed;
		}
		else if(key == sf::Keyboard::D){
			isMovingRight = isPressed;
		}
	}

}