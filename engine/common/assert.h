#pragma once

#define ASSERTION_ENABLED

#ifdef ASSERTION_ENABLED
	//Evaluate expr: if false, show error message and abort program
	#define ASSERT(expr) ((expr) ? (void)0 : doAssert(#expr, __FILE__, __LINE__))

	void doAssert(const char* expr, const char* file, const int line){
		std::cerr << "Assertion failed at " << file << ":" << line << std::endl;
		std::cerr << "Expression is: " << expr << std::endl;

		std::cout << std::endl << "[ERROR] Press any key to close program..." << std::endl;
		getchar();
		abort();
	}

#else
  #define ASSERT(expr) //evaluate nothing
#endif