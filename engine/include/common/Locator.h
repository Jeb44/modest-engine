//Locator.h
#pragma once

#include "common/assert.h"
#include "common/console/Console.h"
#include "common/Random.h"

class Console;
class Random;

class Locator {
public:
	explicit Locator();
	virtual ~Locator();
	
	static void initialize();

	static void provide(Console* service);
	static Console* getConsole();

	static void provide(Random* service);
	static Random* getRandom();

private:
	static Console* console;
	static Random* random;
};