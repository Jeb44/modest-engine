//WinCommandPromptCI.h
#pragma once

#include "IConsolePrinter.h"
#include "common/typedef.h"
#include <iostream>
#include <typeinfo>

class WinConsolePrinter : public IConsolePrinter{
public:
	explicit WinConsolePrinter();
	virtual ~WinConsolePrinter();
	
	void print(C8* message) override;
private:
	
};