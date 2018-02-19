#include "Archers.h"

Archer::Archer()
{
	m_noOfArchers = MAX_ARCHERS;

	if (!m_archerDown.loadFromFile("ASSETS/IMAGES/enemy2345.png"))
	{
		std::cout << "error" << std::endl;
	}

	m_archerBody.setTexture(m_archerDown);

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
	}

	m_downRangeLeft += m_downRangeSwitch;
	m_downRangeRight += m_downRangeSwitch;
}

sf::Sprite Archer::getBody()
{
	return(m_archerBody);
}

void Archer::setPosition(sf::Vector2f t_newPos)
{
	m_archerBody.setPosition(t_newPos);
}
