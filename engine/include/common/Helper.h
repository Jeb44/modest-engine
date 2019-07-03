//Helper.h
#pragma once

#include <string>
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
	std::string toString(const Array<B8>& array);
	std::string toString(const B8* start, size_t size);

	std::string toString(const Array<C8*>& array);
	std::string toString(const C8** start, size_t size);

	std::string toString(const Array<I8>& array);
	std::string toString(const I8* start, size_t size);
	std::string toString(const Array<I16>& array);
	std::string toString(const I16* start, size_t size);
	std::string toString(const Array<I32>& array);
	std::string toString(const I32* start, size_t size);
	std::string toString(const Array<I64>& array);
	std::string toString(const I64* start, size_t size);

	std::string toString(const Array<U8>& array);
	std::string toString(const U8* start, size_t size);
	std::string toString(const Array<U16>& array);
	std::string toString(const U16* start, size_t size);
	std::string toString(const Array<U32>& array);
	std::string toString(const U32* start, size_t size);
	std::string toString(const Array<U64>& array);
	std::string toString(const U64* start, size_t size);
	
	std::string toString(const Array<F32>& array);
	std::string toString(const F32* start, size_t size);
	std::string toString(const Array<F64>& array);
	std::string toString(const F64* start, size_t size);
	#pragma endregion
}