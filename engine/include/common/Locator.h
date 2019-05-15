//Locator.h
#pragma once


#include "ConsoleCI.h"

class Locator {
public:
	explicit Locator();
	virtual ~Locator();
	
	static void provide(ConsoleCI* service);
	static ConsoleCI* getConsole();
private:
	
};