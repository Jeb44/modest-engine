//WinCommandPromptCI.h
#pragma once

#include "ConsoleCI.h"
#include "typedef.h"
#include <iostream>
#include <typeinfo>

class WinCommandPromptCI : public ConsoleCI{
public:
	explicit WinCommandPromptCI();
	virtual ~WinCommandPromptCI();
	
	void print(C8* message) override;
private:
	
};