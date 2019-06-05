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

	// alternatives:
	// - .net framework?
	// - cmake config?
	I32 getColumns() const override;
	I32 getRows() const override;
	
private:
	// Define macro / cmake ?
	const I32 numOfColumns;
	const I32 numOfRows;
};