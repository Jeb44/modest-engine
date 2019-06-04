//Console.h
#pragma once

#include <string>
#include <list>

#include "common/Locator.h"
#include "common/typedef.h"
#include "common/console/IConsolePrinter.h"
// #include "common/console/NullPrinter.h" // use cmake to automaticly add the right console (maybe all should be included for runTimeSwitches?)
#include "common/console/WinConsolePrinter.h"
#include "common/Helper.h"

#include "../builds/meConfig.h"

#define QUOTE(x) #x

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

	void drawNextFrame(F32 frameRate);

private:
	const I32 headerSize;

	IConsolePrinter* printer;

	std::list<std::string*> messages;

	const C8* buildSenderMessage(const C8* message, const C8* sender);
	std::string buildSenderMessage(const std::string message, const std::string sender);

	// Add ConsoleBuffer class
	// Functins for buffering frames
	// std::string buffers[2];
	// std::string* currentBuffer;
	// std::string* nextBuffer;
	// void swapBuffer();
	// void clear();

	// Functions for printing frames
	void addFrameHeader(F32 frameRate);
	void removeOverdueMessages();
	void drawEmptySpaces();
	void drawMessages();

};