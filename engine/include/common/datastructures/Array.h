//Array.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#define INIT_MAX_SIZE 10

template<class T>
class Array {
private:
	T* array;
	U32 size;
	U32 maxSize;

public:
	#pragma region Constructor / Deconstructor
	explicit Array() {
		maxSize = INIT_MAX_SIZE;
		size = 0;
		array = new T[maxSize];
	}
	explicit Array(U32 initSize) {
		maxSize = (initSize > INIT_MAX_SIZE)? initSize : INIT_MAX_SIZE;
		size = initSize;
		array = new T[maxSize];
	}
	explicit Array(U32 initSize, U32 maxSize) {
		ASSERT(initSize <= maxSize);
		this->maxSize = maxSize;
		size = initSize;
		array = new T[size];
	}
	virtual ~Array() {
		// for(size_t i = size - 1, iLen = 0; i >= iLen; i--){
		// 	if(array[i] == nullptr){
		// 		delete array[i];
		// 	}
		// }
		delete array;
	}
	#pragma endregion
	
	#pragma region Operators
	T& operator [](U32 index) {
		ASSERT(index < size || index < 0);
		return array[index];
	}

	T operator [](U32 index) const {
		ASSERT(index < size || index < 0);
		return array[index];
	}

	#pragma endregion

	#pragma region Access
	T* get() {
		return array;
	}
	T& at(U32 index) {
		ASSERT(index < size || index < 0);
		return array[index];
	}
	T& first() {
		ASSERT(size > 0);
		return array[0];
	}
	T& last() {
		ASSERT(size > 0);
		return array[size - 1];
	}
	#pragma endregion

	#pragma region Capacity
	const B8 isEmpty() const {
		return (size == 0)? true : false;
	}
	const U32 getSize() const {
		return size;
	}
	const U32 getMaxSize() const {
		return maxSize;
	}
	#pragma endregion
};