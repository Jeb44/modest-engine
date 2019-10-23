#include <iostream>

#include <SFML/Graphics.hpp>

#include "common/assert.h"
#include "common/typedef.h"
#include "../builds/meConfig.h"
#include <iostream>

#include "common/Locator.h"
#include "core/GameWorldModule.h"
#include "common/console/Console.h"

#include "math/Vector3.h"
#include "common/datastructures/Array.h"

#include "common/Random.h"

#include "common/Helper.h"
#include "core/IEntityComponent.h"
#include "core/TestComponent.h"
#include "core/Entity.h"
#include <algorithm>
#include <vector>

#include <string>
#include <typeinfo>

int main(int argc, char* argv[]){

	// List of the modules
	Console console;
	ME::GameWorldModule modGameWorld;
	
	// Start up engine in the CORRECT order
	Locator::initialize();
	console.startUp();
	// Random::StartUp();
	console.engineStartMessage(argc, argv);
	// ...
	modGameWorld.StartUp();
	
	for(size_t i = 0, iLen = 20; i < iLen; i++){
		// auto var = Random::GetFloat(0, 1);
		// console.print(Helper::toString(var));	
	}

	// Run game
	//modGameWorld.Run();

	// Shut down engine in REVERSE order
	modGameWorld.ShutDown();
	// ... 
	// Random::ShutDown();
	console.engineEndMessage();
	console.shutDown();
	return 0;
}
