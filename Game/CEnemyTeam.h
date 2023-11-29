#pragma once
#include <string>
#include "Observer.h"
#include "CEnemy.h"
#include "IGameElement.h"

class CEnemyTeam : public IGameElement, public IObserver<sf::Vector2i>
{
public:
	struct MemberData
	{
		std::string name;
		sf::Vector2i pos;
	};

	CEnemyTeam(std::shared_ptr<CMap> map, std::vector<MemberData> members);

	void Update(sf::RenderWindow& window) override;
	void Draw(sf::RenderWindow& window) const override;

	void Update(sf::Vector2i const& data) override;

private:
	void AddMember(MemberData& data);

	const std::string BRUISER = "bruiser";
	const std::string ARCHER = "archer";
	const std::string ROGUE = "rogue";
	const std::string CLERIC = "cleric";

	std::shared_ptr<CMap> m_map;

	std::vector<std::shared_ptr<CEnemy>> m_members;
	std::shared_ptr<CEnemy> m_leader;
};