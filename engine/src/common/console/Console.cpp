//Console.cpp
#include "common/console/Console.h"

Console::Console() 
: versionNumber(ME::getVersionNumber())
{}

Console::~Console() {}

void Console::startUp(){
	// printer = new NullPrinter(); // use cmake to specify start-console?
	printer = new WinConsolePrinter();
	Locator::provide(this);

	versionNumber = ME::getVersionNumber();
}

void Console::shutDown(){
	delete printer;
}

void Console::assignPrinter(IConsolePrinter* printer){
	this->printer = printer;
}

void Console::print(const std::string message, const std::string sender){
	std::string newMessage = message;
	if(sender != ""){
		newMessage = buildSenderMessage(message, sender);
	}
	printer->print(newMessage);
}

void Console::engineStartMessage(int argc, char* argv[]){
	std::string message = "";
	message += std::string("[Modest-Engine] Start") +  "\n";
	message += "Version " + ME::getVersionNumber() + "\n";
	message += "Execution Path: " + std::string(argv[0]) + "\n";

	printer->print(message);
}

void Console::engineEndMessage(){
	printer->print("[Modest-Engine] End");
	// std::cin.ignore();
	// getchar(); // IConsolePrinter Command?
}

std::string Console::buildSenderMessage(const std::string message, const std::string sender){
	return "[" + sender + "] " + message;
}