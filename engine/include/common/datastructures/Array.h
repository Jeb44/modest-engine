//Array.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#define INIT_MAX_SIZE 10

template<class T>
class Array {
public:
	explicit Array();
	explicit Array(U32 initSize);
	explicit Array(U32 initSize, U32 maxSize);
	virtual ~Array();
	
	T& get(U32 index);
	T& first();
	T& last();

	bool isEmpty();
	int getSize();
	int getMaxSize();
	
private:
	T* array;
	U32 size;
	U32 maxSize;
};