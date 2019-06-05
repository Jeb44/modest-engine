//GameWorldModule.cpp
#include "core/GameWorldModule.h"



namespace ME{
	
	GameWorldModule::GameWorldModule() {}
	GameWorldModule::~GameWorldModule() {}

	void GameWorldModule::startUp(){
		std::cout << "[Startup] GameWorldModule" << std::endl;
		entitiesCount = 0;

		registerEntity(new Goomba("       Goomba"));
		auto fastGoomba = new Goomba("Fast   Goomba");
		fastGoomba->setMovespeed(1.35f);
		registerEntity(fastGoomba);
  		registerEntity(new FlyingGoomba("Flying Goomba"));
	}
	void GameWorldModule::shutDown(){
		std::cout << "[Shutdown] GameWorldModule" << std::endl;
	}

	void GameWorldModule::run(){
		while(true){
			processInputs();
			update();
			render();
		}
	}

	void GameWorldModule::processInputs(){
		// std::cout << "Input!" << std::endl;
	}
	void GameWorldModule::update(){
		for(size_t i = 0, iLen = entitiesCount; i < iLen; i++){
			if(entities[i]->isDead()){
				continue;
			}
			entities[i]->update(timestep);
		}

		// Delete dead entities
	}
	
	void GameWorldModule::render(){
		Console* console = Locator::getConsole();

		for(size_t i = 0, iLen = entitiesCount; i < iLen; i++){
			console->print(entities[i]->getTransform()->getPosition()->toString(), entities[i]->getName());
		}
	}

	void GameWorldModule::registerEntity(Entity* entity){
		if(entitiesCount < MAX_ENTITIES){
			entities[entitiesCount++] = entity;
		}
	}
}
