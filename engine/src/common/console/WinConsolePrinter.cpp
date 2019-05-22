//WinCommandPromptCI.cpp
#include "common/console/WinConsolePrinter.h"

WinConsolePrinter::WinConsolePrinter() {}

WinConsolePrinter::~WinConsolePrinter() {}

void WinConsolePrinter::print(const C8* message){
	std::cout << message << std::endl;
	
}

void WinConsolePrinter::print(const std::string message){
	std::cout << message << std::endl;
	
}