#pragma once

void doAssert(const char* file, const char* function, const int line, const char* expr);

#define ASSERTION_ENABLED true
#define DEBUG_ENABLED true //debug -> mingw macro available?

#if ASSERTION_ENABLED
	//Evaluate expr: if false, show error message and abort program
	#define ASSERT(expr) ((expr) ? (void)0 : doAssert(__FILE__, __PRETTY_FUNCTION__, __LINE__, #expr))
	
	#if DEBUG_ENABLED
	//Evaluate expr: if false, show error message and abort program (only debug) (Use this for high-performance code)
	#define DEBUG_ASSERT(expr) ((expr) ? (void)0 : doAssert(__FILE__, __PRETTY_FUNCTION__, __LINE__, #expr))
	#endif
#endif

#if !ASSERTION_ENABLED
	//evaluate nothing
	#define ASSERT(expr)
#endif

#if !DEBUG_ENABLED
	//evaluate nothing
	#define DEBUG_ASSERT(expr)
#endif