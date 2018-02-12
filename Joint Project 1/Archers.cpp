#include "Archers.h"

Archer::Archer()
{
	m_noOfArchers = MAX_ARCHERS;
	m_archerLocation = { 25, 40, 0 };

	if (!m_archerDown.loadFromFile("ASSETS/IMAGES/enemy2345.png"))
	{
		std::cout << "error" << std::endl;
	}

	m_archerBody.setTexture(m_archerDown);
	m_archerBody.setPosition(m_archerLocation);

	m_downRangeLeft = LEFT_BOARDER;
	m_downRangeRight = 70;
	m_downRangeSwitch = 40;
}

void Archer::update(MyVector3 t_playerLocation)
{
	downRange(t_playerLocation);
}

void Archer::draw(sf::RenderWindow & t_window)
{
		t_window.draw(m_archerBody);
}

void Archer::downRange(MyVector3 t_playerLocation)
{
	m_downRangeLeft = LEFT_BOARDER;
	m_downRangeRight = 70;

	if (t_playerLocation.x > m_downRangeLeft && t_playerLocation.x < m_downRangeRight)
	{
		std::cout << "It works again" << std::endl;
	}

	m_downRangeLeft += m_downRangeSwitch;
	m_downRangeRight += m_downRangeSwitch;
}

sf::Sprite Archer::getBody()
{
	return(m_archerBody);
}
