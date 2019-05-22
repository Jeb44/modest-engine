//NullPrinter.h
#pragma once

#include "common/typedef.h"
#include "IConsolePrinter.h"

class NullPrinter : public IConsolePrinter {
public:
	explicit NullPrinter();
	virtual ~NullPrinter();
	
	void print(const C8* message) override;
	void print(const std::string message) override;
	
private:
	
};