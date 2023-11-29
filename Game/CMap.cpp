#include "CMap.h"
#include <iostream>

using namespace std;

CMap::CMap()
{
	m_tileMap.load("images/background/tileset.png", sf::Vector2u(TILE_SIZE, TILE_SIZE), m_map, CELLS_COUNT, CELLS_COUNT, TILES_VARIANTS_COUNT);
}

void CMap::Draw(sf::RenderWindow& window) const
{
	window.draw(m_tileMap);
}

bool CMap::CheckAccessibility(sf::Vector2i coord) const
{
	bool isInMapRange = coord.x < CELLS_COUNT && coord.y < CELLS_COUNT;
	return isInMapRange && !IsCellTaken(coord) && ACCESSABLE_SURFACES.contains(m_map[coord.y][coord.x]);
}

sf::Vector2f CMap::GetCellCoord(sf::Vector2i coord) const
{
	return sf::Vector2f(coord.x * TILE_SIZE + TILE_SIZE / 2, coord.y * TILE_SIZE + TILE_SIZE / 2);
}

bool CMap::IsCellTaken(sf::Vector2i coord) const
{
	for (auto it = m_takenCells.begin(); it != m_takenCells.end();)
	{
		if (*it == coord)
			return true;
		else
			++it;
	}
	return false;
}

void CMap::TakeCell(sf::Vector2i coord)
{
	m_takenCells.push_back(coord);
}

void CMap::FreeCell(sf::Vector2i coord)
{
	for (auto it = m_takenCells.begin(); it != m_takenCells.end();)
	{
		if (*it == coord)
		{
			m_takenCells.erase(it);
			return;
		}
		else
			++it;
	}
}

void CMap::Update(sf::RenderWindow& window) {}
