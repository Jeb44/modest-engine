//Locator.cpp
#include "common/Locator.h"

Console* Locator::console = 0;

Locator::Locator() {}

Locator::~Locator() {
	delete console;
}

void Locator::initialize(){
	console = nullptr;
}

void Locator::provide(Console* service){
	ASSERT(service != nullptr);
	console = service;
}

Console* Locator::getConsole(){
	ASSERT(console != nullptr);
	return console;
}
