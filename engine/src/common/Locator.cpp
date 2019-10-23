//Locator.cpp
#include "common/Locator.h"

Console* Locator::console = 0;
Random* Locator::random = 0;

Locator::Locator() {}

Locator::~Locator() {
	delete console;
	delete random;
}

void Locator::initialize(){
	console = nullptr;
	random = nullptr;
}

void Locator::provide(Console* service){
	ASSERT(service != nullptr);
	console = service;
}

Console* Locator::getConsole(){
	ASSERT(console != nullptr);
	return console;
}

void Locator::provide(Random* service){
	ASSERT(service != nullptr);
	random = service;
}

Random* Locator::getRandom(){
	ASSERT(random != nullptr);
	return random;
}