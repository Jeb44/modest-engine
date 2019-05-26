//StringHelper.h
#pragma once

#include <string>
#include <stdio.h>

#include "typedef.h"

#define STRING_FLOAT_PRECISION 2

class StringHelper {
public:	
	static std::string floatToString(F32 number);
	static std::string floatToString(F64 number);
};