#pragma once

#include <iostream>
#include <vector>

#define CMEMORY_MAX_BLOCK_COUNT 10000000

class CMemoryPool
{
public:
	CMemoryPool();
	CMemoryPool(size_t BlockSize, size_t BlockCount = CMEMORY_MAX_BLOCK_COUNT);
	~CMemoryPool();

private:
	size_t m_BlockSize; 
	size_t m_BlockCount;
	std::vector<char> m_vecPool;
	std::vector<void*> m_vecBlocks;

public:
	void* Allocate(size_t Size);
	void Deallocate(void* BlockPoint, size_t BlockSize);

};
