#pragma once

#define ASSERTION_ENABLED true
#define DEBUG true //debug -> mingw macro available?

#if ASSERTION_ENABLED
	//Evaluate expr: if false, show error message and abort program
	#define ASSERT(expr) ((expr) ? (void)0 : doAssert(#expr, __FILE__, __LINE__))
	
	#if DEBUG
	//Evaluate expr: if false, show error message and abort program (only debug) (Use this for high-performance code)
	#define DEBUG_ASSERT(expr) ((expr) ? (void)0 : doAssert(#expr, __FILE, __LINE__))
	#endif

	void doAssert(const char* expr, const char* file, const int line){
		std::cerr << "Assertion failed at " << file << ":" << line << std::endl;
		std::cerr << "Expression is: " << expr << std::endl;

		std::cout << std::endl << "[ASSERT] Press any key to close program..." << std::endl;
		getchar();
		abort(); //applies only to mingw?
	}
#endif

#if !ASSERTION_ENABLED
	//evaluate nothing
	#define ASSERT(expr) 
#endif

#if !DEBUG
	//evaluate nothing
	#define DEBUG_ASSERT(expr)
#endif