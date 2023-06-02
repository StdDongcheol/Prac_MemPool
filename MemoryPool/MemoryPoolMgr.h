
#include "CMemoryPool.h"

#define IMPLEMENATION_MEMORYPOOL( ClassName ) \
CMemoryPool *ClassName::m_MemoryPool = 0; \

#define DECLARE_MEMORYPOOL \
	public:	\
		void* operator new(size_t BlockSize) \
		{ \
			if (!m_MemoryPool) \
				{ \
					m_MemoryPool = new CMemoryPool(BlockSize); \
				} \
			return m_MemoryPool->Allocate(BlockSize); \
		} \
		void operator delete(void* pBlockDelete, size_t BlockSize) \
		{ \
			m_MemoryPool->Deallocate(pBlockDelete, BlockSize); \
		} \
	protected: \
		static CMemoryPool* m_MemoryPool; \
