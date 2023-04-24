
#include "CMemoryPool.h"

CMemoryPool::CMemoryPool()
{
	Init();
}

CMemoryPool::~CMemoryPool()
{
	delete m_pPage;
}

void CMemoryPool::Init()
{
	m_pPage = nullptr;
	m_BlockIdToAllocate = 0;
}

// BlockSize = 128
void* CMemoryPool::Allocate(size_t BlockSize)
{
	if (m_pPage == nullptr)
	{
		m_pPage = (char*)malloc(BlockSize * CMEMORY_MAX_BLOCK_COUNT);
		
		m_MemoryCountLeft = CMEMORY_MAX_BLOCK_COUNT;

		char* pPage = m_pPage;

		for (int i = 1; i <= CMEMORY_MAX_BLOCK_COUNT; ++i)
		{
			*pPage = i;
			pPage += BlockSize;
		}
	}

	if (m_MemoryCountLeft <= 0)
		return nullptr;

	char* pAllocatedBlock = m_pPage + (m_BlockIdToAllocate * BlockSize);

	m_BlockIdToAllocate = *pAllocatedBlock;
	--m_MemoryCountLeft;

	return (void*)pAllocatedBlock;
}

void CMemoryPool::Deallocate(void* BlockPoint, size_t BlockSize)
{
	if (m_MemoryCountLeft >= CMEMORY_MAX_BLOCK_COUNT)
		return;

	*((int*)BlockPoint) = m_BlockIdToAllocate;

	int Offset = (int)((char*)BlockPoint - m_pPage);
	Offset /= (int)BlockSize;

	m_BlockIdToAllocate = Offset;
	++m_MemoryCountLeft;
}
