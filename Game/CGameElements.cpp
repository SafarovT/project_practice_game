#include "CGameElements.h"
#include "CMap.h"
#include "CUser.h"
#include "CEnemyTeam.h"

#include "CWarriorStrategy.h"
#include "CElfStrategy.h"
#include "CRangerStrategy.h"

using namespace std;

CGameElements::CGameElements()
{
	shared_ptr<CMap> mapPtr = make_shared<CMap>();
	m_elements.emplace_back(mapPtr);
	unique_ptr<IClassStrategy> str = make_unique<CElfStrategy>();
	shared_ptr<CUser> userPtr = make_shared<CUser>(CUser(mapPtr, std::move(str)));
	m_elements.emplace_back(userPtr);

	CEnemyTeam enemyTeam = CEnemyTeam(
		mapPtr,
		{
			{
				"bruiser",
				{ 10, 4 },
			},
			{
				"rogue",
				{ 9, 2 },
			},
			{
				"archer",
				{ 11, 2 },
			},
			{
				"cleric",
				{ 10, 0 },
			},
		}
	);
	shared_ptr<CEnemyTeam> enemyTeamPtr = make_shared<CEnemyTeam>(enemyTeam);
	m_elements.emplace_back(enemyTeamPtr);
	userPtr->RegisterObserver(*enemyTeamPtr);
}

void CGameElements::UpdateAndDraw(sf::RenderWindow& window)
{
	for (auto& element : m_elements)
	{
		element->Update(window);
		element->Draw(window);
	}
}

void CGameElements::Update(sf::RenderWindow& window)
{
	for (auto& element : m_elements)
	{
		element->Update(window);
	}
}

void CGameElements::Draw(sf::RenderWindow& window) const
{
	for (auto& element : m_elements)
	{
		element->Draw(window);
	}
}