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
	
	void print(const C8* message) override;
	void print(const std::string message) override;
	
private:
	
};