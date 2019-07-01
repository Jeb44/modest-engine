//Array.cpp
#include "common/datastructures/Array.h"

template<class T>
Array<T>::Array() {
	maxSize = INIT_MAX_SIZE;
	size = 0;
	array = new T[maxSize];
}

template<class T>
Array<T>::Array(U32 initSize) {
	maxSize = (initSize > INIT_MAX_SIZE)? initSize : INIT_MAX_SIZE;	
	size = initSize;
	array = new T[maxSize];
}

template<class T>
Array<T>::Array(U32 initSize, U32 maxSize) {
	ASSERT(initSize < maxSize);
	this->maxSize = maxSize;	
	size = initSize;
	array = new T[size];
}

template<class T>
T& Array<T>::get(U32 index) {
	ASSERT(index > size || index < 0);
	
}


template<class T>
Array<T>::~Array() {
	for(size_t i = size - 1, iLen = 0; i >= iLen; i--){
		delete array[i];
	}
	delete array;
}

