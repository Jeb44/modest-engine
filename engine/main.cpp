#include <iostream>

#include "../builds/meConfig.h"
#include "core/GameWorldModule.h"

#include "include/common/typedef.h"
#include "include/common/assert.h"
#include "include/common/WinCommandPromptCI.h"

#include <string>
#include <typeinfo>

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

namespace test{
	template<class T>

	//print(Printable)

	void print(T sender, std::string message){
		std::cout << "[" << typeid(sender).name() << ": " << QUOTE(sender) << "] " << message << std::endl;
	
		// locator.provide(string);
	}
}

class one{
public:
	void printName(){
		test::print(this, "hello");
	}
};

int main(int argc, char* argv[]){

	engineStartMessage(argc, argv);

	// WinCommandPromptCI<asdf> console;
	one hi;
	float lul = 5;
	hi.printName();
	test::print(hi, "hewwo");
	std::cout << "[" << typeid(lul).name() << ": " << QUOTE(lul) << "] " << "meow" << std::endl;

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

