//HandleManager.cpp
#include "core/resource/HandleManager.h"

HandleManager::HandleManager() {
	Reset();
}

HandleManager::~HandleManager() {}

void HandleManager::Reset(){
	m_activeEntriesCount = 0;
	m_firstAvailableEntry = 0;

	// Create all Entries, set last element flag
	// HandleEntry(i + 1) set's up the chain of nextAvailableIndex's 
	for(size_t i = 0, iLen = MaxEntries - 1; i < iLen; ++i){
		m_entries[i] = HandleEntry(i + 1);
	}	
	m_entries[MaxEntries - 1] = HandleEntry();
	m_entries[MaxEntries - 1].m_endOfList = true;
}

Handle HandleManager::Add(void* ptr, U32 type){
	ASSERT(m_activeEntriesCount < MaxEntries - 1);
	ASSERT(type >= 0 && type <= 15);

	const int newIndex = m_firstAvailableEntry;
	ASSERT(newIndex < MaxEntries);
	ASSERT(m_entries[newIndex].m_active == false);
	ASSERT(!m_entries[newIndex].m_endOfList);

	// nextAvailableIndex-"Chain" is created in Reset() [to be precise: in their constructor] 
	m_firstAvailableEntry = m_entries[newIndex].m_nextAvailableIndex;

	m_entries[newIndex].m_nextAvailableIndex = 0; // == is set
	m_entries[newIndex].m_counter = m_entries[newIndex].m_counter + 1; // add ++ operator?
	if(m_entries[newIndex].m_counter == 0){
		m_entries[newIndex].m_counter = 1;
 	}
	m_entries[newIndex].m_active = true;
	m_entries[newIndex].m_entry = ptr;

	++m_activeEntriesCount;

	return Handle(newIndex, m_entries[newIndex].m_counter, type);
}

void HandleManager::Update(Handle handle, void* ptr){
	const auto index = handle.m_index;
	ASSERT(m_entries[index].m_counter = handle.m_counter);
	ASSERT(m_entries[index].m_active == true);

	m_entries[index].m_entry = ptr;
}

void HandleManager::Remove(const Handle handle){
	const auto index = handle.m_index;
	ASSERT(m_entries[index].m_counter == handle.m_counter);
	ASSERT(m_entries[index].m_active == true);

	m_entries[index].m_nextAvailableIndex = m_firstAvailableEntry;
	m_entries[index].m_active = 0;
	m_firstAvailableEntry = index;

	--m_activeEntriesCount;
}

void* HandleManager::Get(Handle handle) const{
	void* ptr = nullptr;
	if(!Get(handle, ptr)){
		return nullptr;
	}
	return ptr;
}

bool HandleManager::Get(const Handle handle, void*& out) const{
	const auto index = handle.m_index;
	if(m_entries[index].m_counter != handle.m_counter ||
	m_entries[index].m_active == false){
		return false;
	}

	out = m_entries[index].m_entry;
	return true;
}

int HandleManager::GetCount() const{
	return m_activeEntriesCount;
}