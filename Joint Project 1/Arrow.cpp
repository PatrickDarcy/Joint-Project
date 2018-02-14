#include "Arrow.h"

Arrow::Arrow()
{
	m_arrowSpeed = 3.5;
	m_arrowLocation = { 31,40,0 };
	m_shootArrow = 0;

	if (!m_arrowDown.loadFromFile("ASSETS/IMAGES/arrowDown.png"))
	{
		std::cout << "error" << std::endl;
	}

	m_arrow.setTexture(m_arrowDown);
	m_arrow.setPosition(m_arrowLocation);
}

void Arrow::arrowShot(MyVector3 t_enemyLocation)
{
	m_arrowLocation.y += m_arrowSpeed;
	m_arrow.setPosition(m_arrowLocation);
	if (m_arrowLocation.y > SCREEN_HEIGHT)
	{
		m_arrowLocation = t_enemyLocation + MyVector3{6,0,0};
		m_shootArrow = 0;
	}
}

void Arrow::update(MyVector3 t_playerLocation, MyVector3 t_enemyLocation, float t_downRangeLeft, float t_downRangeRight)
{	
	if (t_playerLocation.x >= t_downRangeLeft && t_playerLocation.x < t_downRangeRight || m_shootArrow > 0)
	{
		m_shootArrow++;
		arrowShot(t_enemyLocation);
	}
	collisionWithPlayer(t_playerLocation);
}

void Arrow::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_arrow);
}

void Arrow::collisionWithPlayer(MyVector3 t_playerLocation)
{
	if (m_arrowLocation.x >= t_playerLocation.x && m_arrowLocation.y >= t_playerLocation.y && 
		m_arrowLocation.x <= t_playerLocation.x + PLAYER_WIDTH && m_arrowLocation.y <= t_playerLocation.y + PLAYER_HEIGHT)
	{
		std::cout << "Ouch" << std::endl;
	}
}
