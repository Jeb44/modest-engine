//Console.h
#pragma once

#include "common/Locator.h"
#include "common/typedef.h"
#include "common/console/IConsolePrinter.h"
#include "common/console/NullPrinter.h"
#include "common/console/WinConsolePrinter.h"

class Console {
public:
	explicit Console();
	virtual ~Console();
	
	void startUp();
	void shutDown();

	void print(const C8* message);
	
	void assignPrinter(IConsolePrinter* printer);

private:
	IConsolePrinter* printer;
	
};