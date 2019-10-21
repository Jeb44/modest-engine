//Console.h
#pragma once

#include <string>

#include "common/Locator.h"
#include "common/typedef.h"
#include "common/console/IConsolePrinter.h"
#include "common/console/WinConsolePrinter.h"

#include "../builds/meConfig.h"

class Console {
public:
	explicit Console();
	virtual ~Console();
	
	void startUp();
	void shutDown();

	void assignPrinter(IConsolePrinter* printer);

	void print(const std::string message, const std::string sender = "");
	void engineStartMessage(int argc, char* argv[]);
	void engineEndMessage();

private:
	std::string versionNumber;

	std::string buildSenderMessage(const std::string message, const std::string sender);

	IConsolePrinter* printer;	
};