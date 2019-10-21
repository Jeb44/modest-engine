//Locator.h
#pragma once

#include "common/assert.h"
#include "common/console/Console.h"

class Console;

class Locator {
public:
	explicit Locator();
	virtual ~Locator();
	
	static void initialize();

	static void provide(Console* service);
	static Console* getConsole();

private:
	static Console* console;
};