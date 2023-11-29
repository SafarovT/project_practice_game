#pragma once
#include <string>

enum class Side : int
{
	Left = -1,
	Right = 1,
};

class IClassStrategy
{
public:
	~IClassStrategy() = default;

	virtual std::string GetTexturePath() = 0;
};