//GameWorldModule.cpp
#include "core/GameWorldModule.h"


// using chrono = std::chrono;


namespace ME{
	
	GameWorldModule::GameWorldModule() {}
	GameWorldModule::~GameWorldModule() {}

	void GameWorldModule::startUp(){
		std::cout << "[Startup] GameWorldModule" << std::endl;
		console = Locator::getConsole();		
	}

	void GameWorldModule::shutDown(){
		std::cout << "[Shutdown] GameWorldModule" << std::endl;
	}

	void GameWorldModule::run(){
		typedef std::chrono::duration<int, std::nano> nanosec;
		using clock = std::chrono::high_resolution_clock;
		B8 quitGame = false;

		auto timeStart = clock::now();
		nanosec lag(0);

		while(true){
			auto currentTime = clock::now();
			auto deltaTime = currentTime - timeStart;
			timeStart = currentTime;
			lag += std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime);		

			processInputs();

			while (lag >= timestep){
				update();
				lag -= timestep;
			}

			render();

			if(quitGame){
				break;
			}
		}
	}

	//outdated -> F64 not required
	F64 GameWorldModule::getCurrentTime(){
		return (F64)std::chrono::high_resolution_clock::to_time_t(
			std::chrono::high_resolution_clock::now()
			);
	}
	void GameWorldModule::processInputs(){
		// std::cout << "Input!" << std::endl;
	}
	void GameWorldModule::update(){

	}

	void GameWorldModule::render(){
		// console->testPrint();
		// console->drawNextFrame(currentFrameRate);
	}


	void GameWorldModule::registerEntity(Entity* entity){
		entities.push_back(entity);
	}
}
