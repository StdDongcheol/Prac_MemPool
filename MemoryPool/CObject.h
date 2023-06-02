#pragma once

#include "MemoryPoolMgr.h"
#include "CMemoryPool.h"


class CObject
{
    DECLARE_MEMORYPOOL;

public:
    CObject() {};
    ~CObject() {};

public:
    double X;
    double Y;
    double Z;
};
IMPLEMENATION_MEMORYPOOL(CObject);
