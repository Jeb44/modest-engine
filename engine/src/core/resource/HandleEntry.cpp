//Entry.cpp
#include "core/resource/HandleEntry.h"

HandleEntry::HandleEntry()
: m_nextAvailableIndex(0), m_counter(0), m_active(0), m_endOfList(0), m_entry(nullptr) {}

HandleEntry::HandleEntry(U32 nextFreeIndex)
: m_nextAvailableIndex(0), m_counter(0), m_active(0), m_endOfList(0), m_entry(nullptr) {}

HandleEntry::~HandleEntry() {}

