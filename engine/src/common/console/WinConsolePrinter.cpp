//WinCommandPromptCI.cpp
#include "common/console/WinConsolePrinter.h"

WinConsolePrinter::WinConsolePrinter() :
numOfColumns(80),
numOfRows(24){}

WinConsolePrinter::~WinConsolePrinter() {}

void WinConsolePrinter::print(const C8* message){
	std::cout << message << std::endl;
}

void WinConsolePrinter::print(const std::string message){
	std::cout << message << std::endl;	
}

I32 WinConsolePrinter::getColumns() const {
	return numOfColumns;
}

I32 WinConsolePrinter::getRows() const {
	return numOfRows;
}