//GameWorldModule.h
#pragma once
#include "common/typedef.h"
#include "core/Entity.h"
#include "common/Locator.h"
#include "common/console/Console.h"
#include <list>

#define MS_PER_UPDATE 60

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
		F32 getCurrentTime();
		F32 currentFrameRate;

		void processInputs();
		void update();
		void render();
		
		std::list<Entity*> entities;

	};
}

