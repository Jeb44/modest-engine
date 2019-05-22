//IConsolePrinter.h
#pragma once

#include "common/typedef.h"
#include <typeinfo>
#include <string>

 #define QUOTE(x) #x

class IConsolePrinter {
public:
	virtual ~IConsolePrinter();
	virtual void print(const C8* message) = 0;
	virtual void print(const std::string message) = 0;
	
protected:
	explicit IConsolePrinter();	
};