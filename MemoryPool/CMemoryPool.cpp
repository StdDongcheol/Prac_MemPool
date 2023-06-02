
#include "CMemoryPool.h"
#include <vector>


CMemoryPool::CMemoryPool() :
	m_BlockSize(0),
	m_BlockCount(0)
{
}

CMemoryPool::CMemoryPool(size_t BlockSize, size_t BlockCount /* = 100000 */) :
	m_BlockSize(BlockSize),
	m_BlockCount(BlockCount)
{
	m_vecPool.resize(m_BlockSize * m_BlockCount);

	for (int i = 0; i < m_BlockCount; ++i)
		m_vecBlocks.push_back(&m_vecPool[i * m_BlockSize]);	// BlockSize만큼의 구획을 설정하여 vecBlock에 데이터 블록 추가.
}

CMemoryPool::~CMemoryPool()
{
}

void* CMemoryPool::Allocate(size_t Size)
{
	if (m_vecBlocks.empty())
		return nullptr;

	void* Block = m_vecBlocks.back();	// vecBlock으로부터 데이터 블록 반환. 
	m_vecBlocks.pop_back();

	return Block;
}

void CMemoryPool::Deallocate(void* BlockPoint, size_t BlockSize)
{
	// BlockPoint 주소가 m_vecPool의 범위 밖인 경우, 잘못된 BlockPoint.
	if (BlockPoint < m_vecPool.data() ||
		BlockPoint >= (m_vecPool.data() + m_vecPool.size()))
		return;

	// BlockPoint 주소가 BlockSize와 맞지않을 경우, 잘못된 BlockPoint.
	if (((char*)BlockPoint - m_vecPool.data()) % BlockSize == 0)
		return;


	// BlockPoint의 주소를 회수.
	m_vecBlocks.push_back(BlockPoint);
}
