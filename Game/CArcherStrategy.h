#pragma once
#include "IClassStrategy.h"

class CArcherStrategy : public IClassStrategy
{
public:
    std::string GetTexturePath() override
    {
        return "images/enemy/archer.png";
    }
};