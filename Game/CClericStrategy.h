#pragma once
#include "IClassStrategy.h"

class CClericStrategy : public IClassStrategy
{
public:
    std::string GetTexturePath() override
    {
        return "images/enemy/cleric.png";
    }
};