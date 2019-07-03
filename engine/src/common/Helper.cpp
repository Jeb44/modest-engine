//Helper.cpp
#include "common/Helper.h"

namespace Helper{
	
	std::string toString(const B8 value){
		return (value)? "true" : "false";
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

	#pragma region Arrays
	std::string toString(const Array<B8>& array){
		size_t size = array.getSize();
		std::string str = "Array<B8>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const B8* start, size_t size){
		std::string str = "B8["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<C8*>& array){
		size_t size = array.getSize();
		std::string str = "Array<C8*>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const C8** start, size_t size){
		std::string str = "C8*["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<I8>& array){
		size_t size = array.getSize();
		std::string str = "Array<I8>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const I8* start, size_t size){
		std::string str = "I8["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<I16>& array){
		size_t size = array.getSize();
		std::string str = "Array<I16>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const I16* start, size_t size){
		std::string str = "I16["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<I32>& array){
		size_t size = array.getSize();
		std::string str = "Array<I32>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const I32* start, size_t size){
		std::string str = "I32["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<I64>& array){
		size_t size = array.getSize();
		std::string str = "Array<I64>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const I64* start, size_t size){
		std::string str = "I64["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<U8>& array){
		size_t size = array.getSize();
		std::string str = "Array<I8>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U8* start, size_t size){
		std::string str = "I8["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<U16>& array){
		size_t size = array.getSize();
		std::string str = "Array<I16>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U16* start, size_t size){
		std::string str = "I16["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<U32>& array){
		size_t size = array.getSize();
		std::string str = "Array<I32>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U32* start, size_t size){
		std::string str = "I32["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<U64>& array){
		size_t size = array.getSize();
		std::string str = "Array<I64>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U64* start, size_t size){
		std::string str = "I64["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<F32>& array){
		size_t size = array.getSize();
		std::string str = "Array<I64>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const F32* start, size_t size){
		std::string str = "I64["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const Array<F64>& array){
		size_t size = array.getSize();
		std::string str = "Array<I64>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(array[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const F64* start, size_t size){
		std::string str = "I64["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}
	#pragma endregion
}



