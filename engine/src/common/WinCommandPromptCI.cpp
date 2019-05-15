//WinCommandPromptCI.cpp
#include "common/WinCommandPromptCI.h"

WinCommandPromptCI::WinCommandPromptCI() {}

WinCommandPromptCI::~WinCommandPromptCI() {}

 void WinCommandPromptCI::print(C8* message){
	// std::cout << "[" << typeid(sender) << ": " << QUOTE(sender) << "] " << message << std::endl;
	std::cout << message << std::endl;
//     std::cout<<typeid(A).name()<<"\t"<< quote(A) <<"\n";
	
 }
