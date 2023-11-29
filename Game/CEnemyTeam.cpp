#include <iostream>
#include "CEnemyTeam.h"
#include "CArcherStrategy.h"
#include "CBruiserStrategy.h"
#include "CRogueStrategy.h"
#include "CClericStrategy.h"

using namespace std;

CEnemyTeam::CEnemyTeam(shared_ptr<CMap> map, vector<MemberData> members)
	: m_map(map)
{
	for (auto& memberData : members)
	{
		AddMember(memberData);
	}
	if (m_members.size() > 0)
	{
		m_leader = m_members[0];
	}
}

void CEnemyTeam::Update(sf::RenderWindow& window)
{
	for (auto& member : m_members)
	{
		member->Update(window);
	}
}

void CEnemyTeam::Draw(sf::RenderWindow& window) const
{
	for (auto& member : m_members)
	{
		member->Draw(window);
	}
}

void CEnemyTeam::AddMember(MemberData& data)
{
	if (data.name == ARCHER)
	{
		m_members.emplace_back(make_shared<CEnemy>(CEnemy(m_map, data.pos, make_unique<CArcherStrategy>())));
	}
	else if (data.name == BRUISER)
	{
		m_members.emplace_back(make_shared<CEnemy>(CEnemy(m_map, data.pos, make_unique<CBruiserStrategy>())));
	}
	else if (data.name == ROGUE)
	{
		m_members.emplace_back(make_shared<CEnemy>(CEnemy(m_map, data.pos, make_unique<CRogueStrategy>())));
	}
	else if (data.name == CLERIC)
	{
		m_members.emplace_back(make_shared<CEnemy>(CEnemy(m_map, data.pos, make_unique<CClericStrategy>())));
	}
}

void CEnemyTeam::Update(sf::Vector2i const& data)
{
	cout << "(" << data.x << ", " << data.y << ")" << endl;
}
