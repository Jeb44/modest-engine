//Helper.h
#pragma once

#include <string>
#include <vector>
#include <stdio.h>

#include "typedef.h"
#include "datastructures/Array.h"


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

	#pragma region Arrays
	std::string toString(const std::vector<B8>& container);
	std::string toString(const B8* start, size_t size);

	std::string toString(const std::vector<C8*>& container);
	std::string toString(const C8** start, size_t size);

	std::string toString(const std::vector<I8>& container);
	std::string toString(const I8* start, size_t size);
	std::string toString(const std::vector<I16>& container);
	std::string toString(const I16* start, size_t size);
	std::string toString(const std::vector<I32>& container);
	std::string toString(const I32* start, size_t size);
	std::string toString(const std::vector<I64>& container);
	std::string toString(const I64* start, size_t size);

	std::string toString(const std::vector<U8>& container);
	std::string toString(const U8* start, size_t size);
	std::string toString(const std::vector<U16>& container);
	std::string toString(const U16* start, size_t size);
	std::string toString(const std::vector<U32>& container);
	std::string toString(const U32* start, size_t size);
	std::string toString(const std::vector<U64>& container);
	std::string toString(const U64* start, size_t size);
	
	std::string toString(const std::vector<F32>& container);
	std::string toString(const F32* start, size_t size);
	std::string toString(const std::vector<F64>& container);
	std::string toString(const F64* start, size_t size);
	#pragma endregion
}