#include "CUser.h"
#include <iostream>

using namespace std;

CUser::CUser(shared_ptr<CMap> map, std::unique_ptr<IClassStrategy> classStrategy)
	: m_map(map)
    , m_texture(make_unique<sf::Texture>(sf::Texture()))
    , m_class(std::move(classStrategy))
    , m_pos({ 6, CMap::CELLS_COUNT -1 })
{
	const sf::Vector2f initPosition(m_map->GetCellCoord(m_pos));
	m_view.setCenter(initPosition);
    m_view.setSize({ CMap::TILE_SIZE * 16, CMap::TILE_SIZE * 16 * 0.5625 });
	m_view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

    if (!m_texture->loadFromFile(m_class->GetTexturePath()))
    {
        throw new std::exception("Can`t find hero texture file");
    }
    m_image.setTexture(*m_texture);
    m_image.setOrigin(CMap::TILE_SIZE / 2, CMap::TILE_SIZE / 2);
    m_image.setPosition(initPosition);
}

void CUser::Update(sf::RenderWindow& window)
{
	PollEvents(window);
}

void CUser::Draw(sf::RenderWindow& window) const
{
	window.setView(m_view);
    window.draw(m_image);
}

void CUser::PollEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                Move({ 0, -1 });
                break;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                Move({ 0, 1 });
                break;
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                Move({ -1, 0 });
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                Move({ 1, 0 });
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void CUser::Move(sf::Vector2i delta)
{
    sf::Vector2i test = m_pos + delta;
    if (m_map->CheckAccessibility(m_pos + delta))
    {
        m_map->FreeCell(m_pos);
        if (delta.x == 1) {
            m_image.setScale(1, 1);
        }
        else if (delta.x == -1) {
            m_image.setScale(-1, 1);
        }
        m_pos += delta;
        SetPosion(m_map->GetCellCoord(m_pos));
        m_map->TakeCell(m_pos);
        NotifyObservers();
    }
}

void CUser::SetPosion(sf::Vector2f newPos)
{
    m_view.setCenter(newPos);
    m_image.setPosition(newPos);
}

sf::Vector2i CUser::GetChangedData() const
{
    return m_pos;
}
