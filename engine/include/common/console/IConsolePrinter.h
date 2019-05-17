//IConsolePrinter.h
#pragma once

#include "common/typedef.h"
#include <typeinfo>

 #define QUOTE(x) #x

class IConsolePrinter {
public:
	virtual ~IConsolePrinter();
	virtual void print(C8* message) = 0;
	
protected:
	explicit IConsolePrinter();	
};