#include <iostream>

#include "common/assert.h"
#include "common/typedef.h"
#include "../builds/meConfig.h"


#include "common/Locator.h"
#include "core/GameWorldModule.h"
#include "common/console/Console.h"

#include "math/Vector3.h"
#include "common/datastructures/Array.h"

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

	Array<I32> array0;
	console.print(Helper::toString(array0.getSize()));
	console.print(Helper::toString(array0.getMaxSize()));
	console.print(Helper::toString(array0.isEmpty()));
	console.print("");
	
	Array<I32> array1(8);
	console.print(Helper::toString(array1.getSize()));
	console.print(Helper::toString(array1.getMaxSize()));
	console.print(Helper::toString(array1.isEmpty()));
	console.print("");

	Array<I32> array2(10, 10);
	console.print(Helper::toString(array2.getSize()));
	console.print(Helper::toString(array2.getMaxSize()));
	console.print(Helper::toString(array2.isEmpty()));
	console.print("");

	for(size_t i = 0, iLen = array1.getSize(); i < iLen; i++){
		array1.at(i) = i;
	}

	for(size_t i = 0, iLen = array2.getSize(); i < iLen; i++){
		array2.at(i) = i;
	}
	
	console.print(Helper::toString(array2));
	console.print(Helper::toString(array2.get(), array2.getSize()));

	// Run game
	//modGameWorld.run();



	// Shut down engine in REVERSE order
	modGameWorld.shutDown();
	console.shutDown();
	// ...

	return 0;
}
