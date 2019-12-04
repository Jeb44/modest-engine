// Entry.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

struct HandleEntry {
public:
	explicit HandleEntry();
	explicit HandleEntry(U32 nextFreeIndex);
	virtual ~HandleEntry();

	// "Bit" initialization
	U32 m_nextAvailableIndex : 14;
	U32 m_counter : 14;
	U32 m_active : 1;
	U32 m_endOfList : 1;
	
	//Generic-Ptr: can point to any data
	void* m_entry;
};