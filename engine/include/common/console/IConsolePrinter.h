//IConsolePrinter.h
#pragma once

#include "common/typedef.h"
#include <typeinfo>
#include <string>

class IConsolePrinter {
public:
	virtual ~IConsolePrinter();
	virtual void print(const C8* message) = 0;
	virtual void print(const std::string message) = 0;

	// get console width 
	// get console height
	virtual I32 getRows() const = 0;
	virtual I32 getColumns() const = 0;
	
protected:
	explicit IConsolePrinter();	

	I32 rows;
	I32 columns;
};