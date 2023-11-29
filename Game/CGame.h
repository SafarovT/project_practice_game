#pragma once
#include "CGameElements.h"

class CGame
{
public:
	void Start();

private:
	const unsigned int WINDOW_WIDTH = 1024;
	const unsigned int WINDOW_HEIGHT = 726;

	CGameElements m_elements = CGameElements();
};