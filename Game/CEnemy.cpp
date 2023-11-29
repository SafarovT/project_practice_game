#include "CEnemy.h"

using namespace std;

CEnemy::CEnemy(std::shared_ptr<CMap> map, sf::Vector2i pos, unique_ptr<IClassStrategy> classStrategy)
	: m_map(map)
	, m_pos(pos)
	, m_class(move(classStrategy))
	, m_texture(make_unique<sf::Texture>())
{
	const sf::Vector2f initPosition(m_map->GetCellCoord(m_pos));

	if (!m_texture->loadFromFile(m_class->GetTexturePath()))
	{
		throw new std::exception("Can`t find enemy texture file");
	}
	m_image.setTexture(*m_texture);
	m_image.setOrigin(CMap::TILE_SIZE / 2, CMap::TILE_SIZE / 2);
	m_image.setPosition(initPosition);
	m_map->TakeCell(m_pos);
}

void CEnemy::Draw(sf::RenderWindow& window) const
{
	window.draw(m_image);
}

void CEnemy::Update(sf::RenderWindow& window)
{
	
}
