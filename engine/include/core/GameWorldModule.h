//GameWorldModule.h
#pragma once
#include <list>
#include <iostream>
#include <ctime>
#include <chrono>

#include "common/typedef.h"
#include "core/Entity.h"
#include "common/Locator.h"
#include "common/console/Console.h"

constexpr std::chrono::nanoseconds timestep(16);


namespace ME{
	class GameWorldModule {

	public:
		explicit GameWorldModule();
		virtual ~GameWorldModule();
		
		void startUp(); //final so okay?
		void shutDown();

		void run();

		void registerEntity(Entity* entity);
		// void unregisterEntity(Entity* entity);

	private:
		F64 getCurrentTime();
		F64 currentFrameRate;

		void processInputs();
		void update();
		void render();
		
		Console* console;

		std::list<Entity*> entities;

	};
}

