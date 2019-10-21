//GameWorldModule.h
#pragma once
#include "common/typedef.h"

#include <vector>
#include "core/Entity.h"
#include "SFML/Graphics.hpp"

#define MS_PER_UPDATE 0.167

namespace ME{
	class GameWorldModule {
	public:
		explicit GameWorldModule();
		virtual ~GameWorldModule();
		
		void StartUp(); //final so okay?
		void ShutDown();

		void Run();

		void AddEntity(Entity* entity);
		bool RemoveEntity(Entity* entity);	//return true, if successfull delted
		std::vector<Entity*> GetEnties();

	private:
		void ProcessInputs();
		void Update(sf::Time deltaTime);
		void Render();

		void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

		sf::RenderWindow* window;
		sf::Texture* texPlayer;
		sf::Sprite* sprPlayer;
		
		std::vector<Entity*> entities;

		bool isMovingUp;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
	};
}

