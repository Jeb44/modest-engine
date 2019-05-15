//ConsoleCI.h
#pragma once

#include "typedef.h"
#include <typeinfo>

 #define QUOTE(x) #x

class ConsoleCI {
public:
	virtual ~ConsoleCI();
	virtual void print(C8* message) = 0;
	
protected:
	explicit ConsoleCI();	
};