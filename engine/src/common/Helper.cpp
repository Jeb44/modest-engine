//Helper.cpp
#include "common/Helper.h"

namespace Helper{
	
	std::string toString(const B8 value){
		return (value) ? "true" : "false";
	}

	
	std::string toString(const C8* chars){
		return std::string(chars);
	}

	std::string toString(const I8 value){
		return std::to_string(value);
	}
	std::string toString(const I16 value){
		return std::to_string(value);
	}
	std::string toString(const I32 value){
		return std::to_string(value);
	}
	std::string toString(const I64 value){
		return std::to_string(value);
	}

	std::string toString(const U8 value){
		return std::to_string(value);
	}
	std::string toString(const U16 value){
		return std::to_string(value);
	}
	std::string toString(const U32 value){
		return std::to_string(value);
	}
	std::string toString(const U64 value){
		return std::to_string(value);
	}

	std::string toString(const F32 value){
		std::string str = std::to_string(value); 
		str.erase(str.find('.') + 1 + STRING_FLOAT_PRECISION, 6); // F32 has max precision of 6
		return str;
	}
	std::string toString(const F64 value){
		std::string str = std::to_string(value);
		str.erase(str.find('.') + 1 + STRING_FLOAT_PRECISION, 15); // F64 has max precision of 15
		return str;
	}
}



