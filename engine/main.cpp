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
	Vector3 b(1.0f, 0.0f, 0.0f);
	Vector3 c(0.0f, 1.0f, 0.0f);
	console.print("A" + a.toString());
	console.print("B" + b.toString());
	console.print("C" + c.toString());

	// b.normalize();
	//c.normalize();
	Vector3 s = c.cross(b);
	Vector3 t = b.cross(c);

	console.print("A" + a.toString());
	console.print("B" + b.toString());
	console.print("C" + c.toString());
	console.print("t" + t.toString());
	console.print("s" + s.toString());

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
// - normalizing (0.00, 0.00, 0.00) results in (na, na, na)
