#include <iostream>

#include "../builds/meConfig.h"
#include "core/GameWorldModule.h"

#include "include/common/typedef.h"
#include "include/common/assert.h"

#define MS_PER_UPDATE 60

//TODO: add (console) logger (avoiding)
void engineStartMessage(int argc, char* argv[]){
	if(argc > 0){
		std::cout
			<< "[Modest-Engine] " 
			<< "Version "
			<< ME_VERSION_MAJOR << "."
			<< ME_VERSION_MINOR << "."
			<< ME_VERSION_PATCH
		<< std::endl
			<< "Path: "
			<< argv[0] 
		<< std::endl;
	}
}

int main(int argc, char* argv[]){

	engineStartMessage(argc, argv);

	// List of the modules
	ME::GameWorldModule modGameWorld;

	// Start up engine in the CORRECT order
	// ...
	modGameWorld.startUp();
	
	// Run game
	//modGameWorld.run();

	// Shut down engine in REVERSE order
	modGameWorld.shutDown();
	// ...
	
	std::cout << std::endl << "[END] Press any key to close program..." << std::endl;
	getchar();

	return 0;
}

