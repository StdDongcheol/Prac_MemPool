
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
		m_vecBlocks.push_back(&m_vecPool[i * m_BlockSize]);	// BlockSize��ŭ�� ��ȹ�� �����Ͽ� vecBlock�� ������ ��� �߰�.
}

CMemoryPool::~CMemoryPool()
{
}

void* CMemoryPool::Allocate(size_t Size)
{
	if (m_vecBlocks.empty())
		return nullptr;

	void* Block = m_vecBlocks.back();	// vecBlock���κ��� ������ ��� ��ȯ. 
	m_vecBlocks.pop_back();

	return Block;
}

void CMemoryPool::Deallocate(void* BlockPoint, size_t BlockSize)
{
	// BlockPoint �ּҰ� m_vecPool�� ���� ���� ���, �߸��� BlockPoint.
	if (BlockPoint < m_vecPool.data() ||
		BlockPoint >= (m_vecPool.data() + m_vecPool.size()))
		return;

	// BlockPoint �ּҰ� BlockSize�� �������� ���, �߸��� BlockPoint.
	if (((char*)BlockPoint - m_vecPool.data()) % BlockSize == 0)
		return;


	// BlockPoint�� �ּҸ� ȸ��.
	m_vecBlocks.push_back(BlockPoint);
}
