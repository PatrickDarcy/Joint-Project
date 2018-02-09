#include "Archers.h"

Archer::Archer()
{
	m_noOfArchers = MAX_ARCHERS;
	m_archerX = 25;
	dow

	if (!m_archerDown.loadFromFile("ASSETS/IMAGES/enemy2345.png"))
	{
		std::cout << "error" << std::endl;
	}

	for (int index = 0; index < m_noOfArchers; index++)
	{
		m_archerBody[index].setTexture(m_archerDown);
		m_archerBody[index].setPosition(m_archerX, 40);
		m_archerX += 110;
	}
}

void Archer::update(MyVector3 t_playerLocation)
{
	downRange(t_playerLocation);
}

void Archer::draw(sf::RenderWindow & t_window)
{
	for (int index = 0; index < m_noOfArchers; index++)
	{
		t_window.draw(m_archerBody[index]);
	}
	
}

void Archer::downRange(MyVector3 t_playerLocation)
{
	if (t_playerLocation.x > LEFT_BOARDER && t_playerLocation.x < 75)
	{
		std::cout << "It works again" << std::endl;
	}
}
