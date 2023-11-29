#pragma once
#include "IClassStrategy.h"

class CBruiserStrategy : public IClassStrategy
{
public:
    std::string GetTexturePath() override
    {
        return "images/enemy/bruiser.png";
    }
};