//Console.cpp
#include "common/console/Console.h"

Console::Console() {}
Console::~Console() {}

void Console::startUp(){
	// printer = new NullPrinter(); // use cmake to specify start-console

	printer = new WinConsolePrinter();
	Locator::provide(this);
}

void Console::shutDown(){
	delete printer;
}

void Console::print(const C8* message){
	printer->print(message);
}

void Console::assignPrinter(IConsolePrinter* printer){
	this->printer = printer; 
}

