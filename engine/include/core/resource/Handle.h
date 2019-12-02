// Handle.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

struct Handle {
public:
	explicit Handle();
	explicit Handle(U32 index, U32 counter, U32 type);
	virtual ~Handle();
	
	inline operator U32() const;

	// "Bit" initialization
	U32 m_index : 14;
	U32 m_counter : 14;
	U32 m_type : 4;
};