#include <iostream>

#include "common/assert.h"
#include "common/typedef.h"
#include "../builds/meConfig.h"


#include "common/Locator.h"
#include "core/GameWorldModule.h"
#include "common/console/Console.h"

#include "math/Vector3.h"

#include <string>
#include <typeinfo>

#define MS_PER_UPDATE 60

int main(int argc, char* argv[]){

	// WinConsolePrinter console;
	// one hi;
	// float lul = 5;
	// hi.printName();
	// test::print(hi, "hewwo");
	// std::cout << "[" << typeid(lul).name() << ": " << QUOTE(lul) << "] " << "meow" << std::endl;

	// List of the modules
	ME::GameWorldModule modGameWorld;
	Console console;
	
	// Start up engine in the CORRECT order
	console.startUp();
	console.engineStartMessage(argc, argv);
	modGameWorld.startUp();
	// ...


	// Run game
	modGameWorld.run();


	// Shut down engine in REVERSE order
	modGameWorld.shutDown();
	console.shutDown();
	// ...

	return 0;
}
