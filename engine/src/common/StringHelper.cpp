//StringHelper.cpp
#include "common/StringHelper.h"

std::string StringHelper::floatToString(F32 number){
	std::string str = std::to_string(number); 
	str.erase(str.find('.') + 1 + STRING_FLOAT_PRECISION, 6); //float has max precision of 6
	return str;
}
std::string StringHelper::floatToString(F64 number){
	std::string str = std::to_string(number);
	str.erase(str.find('.') + 1 + STRING_FLOAT_PRECISION, 15); //float has max precision of 15
	return str;
}

