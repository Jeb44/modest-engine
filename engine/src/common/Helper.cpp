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
	std::string toString(const std::vector<B8>& container){
		size_t size = container.size();
		std::string str = "Vector<B8>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
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

	std::string toString(const std::vector<C8*>& container){
		size_t size = container.size();
		std::string str = "Vector<C8*>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
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

	std::string toString(const std::vector<I8>& container){
		size_t size = container.size();
		std::string str = "Vector<I8>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
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

	std::string toString(const std::vector<I16>& container){
		size_t size = container.size();
		std::string str = "Vector<I16>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
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

	std::string toString(const std::vector<I32>& container){
		size_t size = container.size();
		std::string str = "Vector<I32>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
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

	std::string toString(const std::vector<I64>& container){
		size_t size = container.size();
		std::string str = "Vector<I64>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
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

	std::string toString(const std::vector<U8>& container){
		size_t size = container.size();
		std::string str = "Vector<U8>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U8* start, size_t size){
		std::string str = "U8["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const std::vector<U16>& container){
		size_t size = container.size();
		std::string str = "Vector<U16>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U16* start, size_t size){
		std::string str = "U16["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const std::vector<U32>& container){
		size_t size = container.size();
		std::string str = "Vector<U32>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U32* start, size_t size){
		std::string str = "U32["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const std::vector<U64>& container){
		size_t size = container.size();
		std::string str = "Vector<U64>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const U64* start, size_t size){
		std::string str = "U64["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const std::vector<F32>& container){
		size_t size = container.size();
		std::string str = "Vector<F32>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const F32* start, size_t size){
		std::string str = "F32["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const std::vector<F64>& container){
		size_t size = container.size();
		std::string str = "Vector<F64>["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(container[i]) + "\n";
		}
		str += "}";
		return str;
	}

	std::string toString(const F64* start, size_t size){
		std::string str = "F64["+ toString(size) + "] {\n";
		for(size_t i = 0; i < size; i++){
			str += "\t[" + toString(i) + "] " + toString(start[i]) + "\n";
		}
		str += "}";
		return str;
	}
	#pragma endregion
}



