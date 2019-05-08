#include <iostream>

#include "../builds/meConfig.h"

#include "common/typedef.h"
#include "common/assert.h"

#define MS_PER_UPDATE 60

// This interface serves only as a function blueprint for every module.
// There is no array of "ISubsystemModule"s. This is just for clarity.
// Note: perhaps this is class uneccessary, because some modules might require arguments
class ISubsystemModule{
public:
	//Start Module by setting everything up
	virtual void startUp() = 0;
	virtual void shutDown() = 0;	
};

class GameWorldModule /*: public ISubsystemModule */{
public:
	GameWorldModule(){};
	~GameWorldModule(){};

	void startUp() /*final override*/; //final so okay?
	void shutDown() /*final override*/;

	void run();

private:
	F32 getCurrentTime();

	void processInputs();
	void update();
	void render();
};

void GameWorldModule::startUp(){}
void GameWorldModule::shutDown(){}

void GameWorldModule::run(){
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
	}
}

F32 GameWorldModule::getCurrentTime(){
	return 0.0f;
}
void GameWorldModule::processInputs(){}
void GameWorldModule::update(){}
void GameWorldModule::render(){}

//TODO: add (console) logger (avoiding)
void engineStartMessage(int argc, char* argv[]){
	if(argc < 2){
		std::cout << "Path: "	<< argv[0] 	<< std::endl
		<< "Version "
			<< ME_VERSION_MAJOR << "."
			<< ME_VERSION_MINOR << "."
			<< ME_VERSION_PATCH
		<< std::endl;
	}
}

int main(int argc, char* argv[]){	
	
	engineStartMessage(argc, argv);
	
	// List of the modules
	GameWorldModule modGameWorld;

	// Start up engine in the CORRECT order
	// ...
	modGameWorld.startUp();
	
	// Run game
	modGameWorld.run();

	// Shut down engine in REVERSE order
	modGameWorld.shutDown();
	// ...
	
	std::cout << std::endl << "[END] Press any key to close program..." << std::endl;
	getchar();

	return 0;
}

