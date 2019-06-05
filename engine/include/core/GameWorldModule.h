//GameWorldModule.h
#pragma once
#include "common/typedef.h"
#include "core/Entity.h"
#include "core/Goomba.h"
#include "core/FlyingGoomba.h"
#include "common/console/Console.h"
#include <list>
#include <iostream>
#include <ctime>
#include <chrono>

#define MAX_ENTITIES 10
constexpr F32 timestep = 0.167;

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
		void processInputs();
		void update();
		void render();
		
		Entity* entities[MAX_ENTITIES];
		size_t entitiesCount;
	};
}

