//WinCommandPromptCI.cpp
#include "common/console/WinConsolePrinter.h"

WinConsolePrinter::WinConsolePrinter() {}

WinConsolePrinter::~WinConsolePrinter() {}

 void WinConsolePrinter::print(C8* message){
	// std::cout << "[" << typeid(sender) << ": " << QUOTE(sender) << "] " << message << std::endl;
	// std::cout<<typeid(A).name()<<"\t"<< quote(A) <<"\n";
	std::cout << message << std::endl;
	
 }
