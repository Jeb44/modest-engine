#pragma once

#define ASSERTION_ENABLED true //use non-zero value to "enable" this macro 

#if ASSERTION_ENABLED

	#define DEBUG_BREAK() asm {int 3};

	#define REPORT_ASSERTION_FAILURE(expr, file, line) {}

	#define ASSERT(expr) \
		if(expr) { } \
		else { \
			REPORT_ASSERTION_FAILURE(#expr, __FILE__, __LINE__); \
			DEBUG_BREAK(); \
		} 
#else
#define ASSERT(expr){} //evaluates to nothing
#endif