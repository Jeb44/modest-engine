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
	//modGameWorld.run();

	Vector3 a;
	Vector3 b(1.00f, 1.5f, 3.0f);
	Vector3 c = b * 2;
	console.print("A" + a.toString());
	console.print("B" + b.toString());
	console.print("C" + c.toString());


	console.print("B	| " + StringHelper::floatToString(Vector3::magnitude(b)));
	console.print("B2	| " + StringHelper::floatToString(Vector3::squareMagnitude(b)));
	console.print("C	| " + StringHelper::floatToString(Vector3::magnitude(c)));
	console.print("C2	| " + StringHelper::floatToString(Vector3::squareMagnitude(c)));

	console.print("B	| " + StringHelper::floatToString(b.magnitude()));
	console.print("B2	| " + StringHelper::floatToString(b.squareMagnitude()));
	console.print("C	| " + StringHelper::floatToString(c.magnitude()));
	console.print("C2	| " + StringHelper::floatToString(c.squareMagnitude()));

	// Shut down engine in REVERSE order
	modGameWorld.shutDown();
	console.shutDown();
	// ...

	return 0;
}

// Todo:
// - add scalar constructor for vectors
// - stringHelper: add ToString for bool, float, int, char
// - test stringHelper with typedef data types (F32, co.)
