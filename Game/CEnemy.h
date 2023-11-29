#pragma once
#include "CMap.h"
#include "IClassStrategy.h"
#include "IGameElement.h"

class CEnemy : public IGameElement
{
public:
	CEnemy(std::shared_ptr<CMap> map, sf::Vector2i pos, std::unique_ptr<IClassStrategy> classStrategy);

	void Update(sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) const override;
private:
	sf::Sprite m_image;
	std::unique_ptr<sf::Texture> m_texture;
	std::unique_ptr<IClassStrategy> m_class;
	std::shared_ptr<CMap> m_map;

	sf::Vector2i m_pos;
	int health = 20;
	int speed = 5;
};