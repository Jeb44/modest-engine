//Helper.h
#pragma once

#include <string>
#include <stdio.h>

#include "typedef.h"

#define STRING_FLOAT_PRECISION 2

namespace Helper{
	std::string toString(const B8 value);

	std::string toString(const C8* chars);

	std::string toString(const I8 value);
	std::string toString(const I16 value);
	std::string toString(const I32 value);
	std::string toString(const I64 value);
	
	std::string toString(const U8 value);
	std::string toString(const U16 value);
	std::string toString(const U32 value);
	std::string toString(const U64 value);

	std::string toString(const F32 value);
	std::string toString(const F64 value);
}