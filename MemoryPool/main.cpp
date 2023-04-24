

#include <ctime>
#include <iostream>
#include "CObject.h"
#include "CNonObject.h"

int main()
{
	clock_t Start = clock();
	clock_t End;

	CObject* TestArr1[5000000] = {};
	CNonObject* TestArr2[5000000] = {};


	/// ============================================================
	/// MemoryPool object start
	/// ============================================================
	
	for (int i = 0; i < 5000000; ++i)
	{
		CObject* pObject = new CObject;
		TestArr1[i] = pObject;
	}
	End = clock();
	std::cout << "MemoryPool object allocate Time : " << (double)(End - Start) / CLOCKS_PER_SEC << std::endl;


	Start = clock();
	for (int i = 0; i < 5000000; ++i)
	{
		delete TestArr1[i];
	}
	End = clock();
	std::cout << "MemoryPool object deallocate Time : " << (double)(End - Start) / CLOCKS_PER_SEC << std::endl;

	/// ============================================================
	/// MemoryPool object end
	/// ============================================================



	/// ============================================================
	/// Normal object start
	/// ============================================================
	
	Start = clock();
	for (int i = 0; i < 5000000; ++i)
	{

		CNonObject* pObject = new CNonObject;
		TestArr2[i] = pObject;
	}
	End = clock();
	std::cout << "Normal object allocate Time : " << (double)(End - Start) / CLOCKS_PER_SEC << std::endl;


	Start = clock();
	for (int i = 0; i < 5000000; ++i)
	{
		delete TestArr2[i];
	}
	End = clock();
	std::cout << "Normal object deallocate Time : " << (double)(End - Start) / CLOCKS_PER_SEC << std::endl;

	/// ============================================================
	/// Normal object end
	/// ============================================================
	
	return 0;
}