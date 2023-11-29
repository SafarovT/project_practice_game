#pragma once
#include "IClassStrategy.h"

class CElfStrategy : public IClassStrategy
{
public:
    std::string GetTexturePath() override
    {
        return "images/hero/elf.png";
    }
};