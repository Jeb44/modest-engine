//GameWorldModule.h
#pragma once
#include "common/typedef.h"

#define MS_PER_UPDATE 60

namespace ME{
	class GameWorldModule {
	public:
		explicit GameWorldModule();
		virtual ~GameWorldModule();
		
		void startUp(); //final so okay?
		void shutDown();

		void run();

	private:
		F32 getCurrentTime();

		void processInputs();
		void update();
		void render();
		
	};
}

