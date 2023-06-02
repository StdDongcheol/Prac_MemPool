

#include <ctime>
#include <iostream>
#include "CObject.h"
#include "CNonObject.h"

int main()
{
	clock_t Start = clock();
	clock_t End;

	/// ============================================================
	/// MemoryPool object new & delete start
	/// ============================================================
	Start = clock();
	
	for (int i = 0; i < 10000000; ++i)
	{
		CObject* pObject = new CObject;
		delete pObject;
	}

	End = clock();
	std::cout << "MemoryPooled object new & delete time : " << (double)(End - Start) / CLOCKS_PER_SEC << std::endl;
	/// ============================================================
	/// MemoryPool object end
	/// ============================================================



	/// ============================================================
	/// Normal object new & delete start
	/// ============================================================
	Start = clock();

	for (int i = 0; i < 10000000; ++i)
	{
		CNonObject* pObject = new CNonObject;
		delete pObject;
	}
	End = clock();
	std::cout << "Normal object new & delete time : " << (double)(End - Start) / CLOCKS_PER_SEC << std::endl;

	/// ============================================================
	/// Normal object end
	/// ============================================================

	return 0;
}
