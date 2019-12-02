//Handle.cpp
#include "core/resource/Handle.h"

Handle::Handle() 
: m_index(0), m_counter(0), m_type(0){}

Handle::Handle(U32 index, U32 counter, U32 type) 
: m_index(index), m_counter(counter), m_type(type){}

Handle::~Handle(){}

Handle::operator U32() const{
	return m_type << 28 | m_counter << 14 | m_index;
}


// blue medusa