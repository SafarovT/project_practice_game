#pragma once
#include "IClassStrategy.h"

class CWarriorStrategy : public IClassStrategy
{
public:
	std::string GetTexturePath() override
	{
		return "images/hero/warrior.png";
	}
};