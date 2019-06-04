//GameWorldModule.cpp
#include "core/GameWorldModule.h"

#include <iostream>
#include <ctime>
#include <chrono>

namespace ME{
	
	GameWorldModule::GameWorldModule() {}
	GameWorldModule::~GameWorldModule() {}

	void GameWorldModule::startUp(){
		std::cout << "[Startup] GameWorldModule" << std::endl;

		
	}
	void GameWorldModule::shutDown(){
		std::cout << "[Shutdown] GameWorldModule" << std::endl;
	}

	void GameWorldModule::run(){
		B8 quitGame = false;

		F32 previous = getCurrentTime();
		F32 lag = 0.0f;

		while(true){
			F32 current = getCurrentTime();
			F32 elapsed = current - previous;
			previous = current;

			lag += elapsed;
			processInputs();

			while (lag >= MS_PER_UPDATE){
				update();
				lag -= MS_PER_UPDATE;
			}

			render();

			if(quitGame){
				break;
			}
		}
	}

	F32 GameWorldModule::getCurrentTime(){
		return (F32)std::chrono::system_clock::to_time_t(
			std::chrono::system_clock::now()
			);
	}
	void GameWorldModule::processInputs(){
		// std::cout << "Input!" << std::endl;
	}
	void GameWorldModule::update(){
		// std::cout << "Update!" << std::endl;
	}
	void GameWorldModule::render(){
		// std::cout << "Render!" << std::endl;

		// switch buffer (console function i guess?)
		// give console current time and framerate
		// send console information to display (vector3, etc.) -> ConsoleMessage class (add persistence?)
		// display new frame
	}


	void GameWorldModule::registerEntity(Entity* entity){
		entities.push_back(entity);
	}
}
