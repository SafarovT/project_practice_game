#pragma once
#include "IClassStrategy.h"

class CRangerStrategy : public IClassStrategy
{
public:
    std::string GetTexturePath() override
    {
        return "images/hero/ranger.png";
    }
};