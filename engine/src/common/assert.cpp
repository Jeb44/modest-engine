//assert.cpp
#include "common/assert.h"

#include <iostream>

void doAssert(const char* file, const char* function, const int line, const char* expr){
	std::cerr << "[ASSERT] File: " << file << ":" << line << std::endl;
	std::cerr << "[ASSERT] Funciton: " << function << std::endl;
	std::cerr << "[ASSERT] Expression: " << expr << std::endl;

	std::cout << std::endl << "[ASSERT] Press any key to close program..." << std::endl;
	getchar();
	abort(); //applies only to mingw?
}
