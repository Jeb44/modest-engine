//assert.cpp
#include "common/assert.h"

#include <iostream>

void doAssert(const char* expr, const char* file, const int line){
	std::cerr << "Assertion failed at " << file << ":" << line << std::endl;
	std::cerr << "Expression is: " << expr << std::endl;

	std::cout << std::endl << "[ASSERT] Press any key to close program..." << std::endl;
	getchar();
	abort(); //applies only to mingw?
}
