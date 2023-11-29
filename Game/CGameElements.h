#pragma once
#include <memory>
#include <vector>
#include "IGameElement.h"

class CGameElements : public IGameElement
{
public:
	CGameElements();

	void UpdateAndDraw(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) const override;

private:
	std::vector<std::shared_ptr<IGameElement>> m_elements;
};

