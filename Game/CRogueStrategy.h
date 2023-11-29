#pragma once
#include "IClassStrategy.h"

class CRogueStrategy : public IClassStrategy
{
public:
    std::string GetTexturePath() override
    {
        return "images/enemy/rogue.png";
    }
};