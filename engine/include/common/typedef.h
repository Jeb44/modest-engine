#pragma once
#include <cstdint>
#include <cstdbool>
#include <cstdlib>

/* These standard typedefs use the std libaries types and should be used for following reasons:
 * - by using _least for every type we can assure that all types are usable by every OS
 * - the first character describe what data it uses (B -> boolean, I -> Integer, U -> Unsigner Integer, F -> Floating-Point, ...)
 * - capizalizing the first letter also helps with distinction of the hungarian notation
 * - the following number shows the bit-size, this is useful for the object layout in Memory (lit[0])
 * 
 * Note: 
 * - For default use take B8, I32, U32, F32
 * - Keep in mind that I8 & U8 are converted into char when displaying on the console 
 * 
 * lit[0] -> Game Engineering Architecture by Jason Gregory, Section 3.2.5
 */

// Standard Data types

typedef _Bool B8;				//1Byte [0 (false), 1 (true)]

typedef char C8;				//1Byte 

typedef std::int_least8_t I8;	//1Byte	[-128,												  +127] (INT_LEAST8_MIN, INT_LEAST8_MAX)
typedef std::int_least16_t I16; //2Byte	[-32.768,										   +32.767] (INT_LEAST16_MIN, INT_LEAST16_MAX)
typedef std::int_least32_t I32;	//4Byte	[-2.147.483.648,							+2.147.483.647] (INT_LEAST32_MIN, INT_LEAST32_MAX)
typedef std::int_least64_t I64;	//8Byte	[-9.223.372.036.854.775.808,	+9.223.372.036.854.775.807] (INT_LEAST64_MIN, INT_LEAST64_MAX)

typedef std::uint_least8_t U8;		//1Byte	[0, 						   255] (UINT_LEAST8_MAX)
typedef std::uint_least16_t U16;	//2Byte	[0, 						65.535] (UINT_LEAST16_MAX)
typedef std::uint_least32_t U32;	//4Byte	[0, 				 4.294.967.295] (UINT_LEAST32_MAX)
typedef std::uint_least64_t U64;	//8Byte	[0,		18.446.744.073.709.551.615] (UINT_LEAST64_MAX)

typedef float F32;				//4Byte		| Precision: 6 [-3,4E+38,		  +3,4E+38]
typedef double F64;				//8Byte		| Precision: 15 [-1,7E+308,		 +1,7E+308]

// Different Data types
// ...