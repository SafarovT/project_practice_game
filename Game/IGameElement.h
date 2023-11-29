#pragma once
#include "IDrawable.h"

class IGameElement : public IDrawable
{
public:
	virtual ~IGameElement() = default;

	virtual void Update(sf::RenderWindow& window) = 0;
};