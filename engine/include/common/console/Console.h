//Console.h
#pragma once

#include <string>

#include "common/Locator.h"
#include "common/typedef.h"
#include "common/console/IConsolePrinter.h"
// #include "common/console/NullPrinter.h" // use cmake to automaticly add the right console (maybe all should be included for runTimeSwitches?)
#include "common/console/WinConsolePrinter.h"

#include "../builds/meConfig.h"

class Console {
public:
	explicit Console();
	virtual ~Console();
	
	void startUp();
	void shutDown();

	void assignPrinter(IConsolePrinter* printer);

	void print(const C8* message, const C8* sender = "");
	void print(const std::string message, const std::string sender = "");
	void engineStartMessage(int argc, char* argv[]);
	void engineEndMessage();

private:
	std::string versionNumber;

	const C8* buildSenderMessage(const C8* message, const C8* sender);
	std::string buildSenderMessage(const std::string message, const std::string sender);

	IConsolePrinter* printer;	
};