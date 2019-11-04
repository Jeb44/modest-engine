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

#include "core/RenderModule.h"

#define MS_PER_UPDATE 0.167

namespace ME{
	class GameWorldModule {
	public:
		explicit GameWorldModule();
		virtual ~GameWorldModule();
		
		void StartUp(); //final so okay?
		void ShutDown();

		void Run();

		void setRenderModule(RenderModule* renderModule);

		void AddEntity(Entity* entity);
		bool RemoveEntity(Entity* entity);	//return true, if successfull delted
		std::vector<Entity*> GetEnties();

	private:
		void ProcessInputs();
		void Update(sf::Time deltaTime);
		void Render();

		void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

		
		std::vector<Entity*> entities;

		RenderModule* modRender;

		bool isMovingUp;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
	};
}

