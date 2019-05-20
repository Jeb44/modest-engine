//NullPrinter.h
#pragma once

#include "common/typedef.h"
#include "IConsolePrinter.h"

class NullPrinter : public IConsolePrinter {
public:
	explicit NullPrinter();
	virtual ~NullPrinter();
	
	virtual void print(const C8* message) override;
	
private:
	
};