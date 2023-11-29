#pragma once
#include <memory>
#include <stdexcept>
#include "IGameElement.h"
#include "IClassStrategy.h"
#include "CMap.h"
#include "Observer.h"

class CUser : public IGameElement, public CObservable<sf::Vector2i>
{
public:
	CUser(std::shared_ptr<CMap> map, std::unique_ptr<IClassStrategy> classStrategy);

	void Update(sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) const override;

private:
	void PollEvents(sf::RenderWindow& window);
	void Move(sf::Vector2i delta);
	void SetPosion(sf::Vector2f newPos);

	sf::Vector2i GetChangedData() const;

	sf::Sprite m_image;
	std::unique_ptr<sf::Texture> m_texture;
	std::unique_ptr<IClassStrategy> m_class;

	sf::Vector2i m_pos;

	sf::View m_view;
	std::shared_ptr<CMap> m_map;
};

