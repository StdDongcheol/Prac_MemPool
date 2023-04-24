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
    float X;
    float Y;
    float Z;
};
IMPLEMENATION_MEMORYPOOL(CObject);
