//Locator.h
#pragma once

// #include "common/console/Console.h"
#include "common/assert.h"

class Console;

class Locator {
public:
	explicit Locator();
	virtual ~Locator();
	
	static void provide(Console* service);
	static Console* getConsole();

private:
	static Console* console;
	
};