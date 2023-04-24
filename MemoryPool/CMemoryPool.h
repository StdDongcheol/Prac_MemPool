#pragma once

#include <iostream>

#define CMEMORY_MAX_BLOCK_COUNT 1024

class CMemoryPool
{
public:
	CMemoryPool();
	~CMemoryPool();

public:
	int		m_MemoryCountLeft;
	int		m_BlockIdToAllocate;
	char*	m_pPage;

public:
	void Init();
	void* Allocate(size_t Size);
	void Deallocate(void* BlockPoint, size_t BlockSize);

};
