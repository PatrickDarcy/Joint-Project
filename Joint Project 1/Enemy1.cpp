#include "Enemy1.h"

Enemy1::Enemy1()
{
	m_enemy1Speed = 1.0f;
	m_enemy1X = 360.0f;
	m_enemy1Y = 80.0f;

	if (!m_enemy1Down.loadFromFile("ASSETS/IMAGES/enemyDown.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_enemy1Body.setTexture(m_enemy1Down);
	m_enemy1Body.setPosition(sf::Vector2f{ m_enemy1X,m_enemy1Y });

	m_detectionZone.setPosition(m_enemy1X, m_enemy1Y);
	m_detectionZone.setRadius(50);
	m_detectionZone.setFillColor(sf::Color{ 0,0,0,100 });
}

void Enemy1::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemy1Body);
	t_window.draw(m_detectionZone);
}

void Enemy1::enemyFollow(sf::Vector2f t_playerLocation)
{
	if (m_enemy1X < t_playerLocation.x)
	{
		m_enemy1X += m_enemy1Speed;
		m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
	}
	if (m_enemy1X > t_playerLocation.x)
	{
		m_enemy1X -= m_enemy1Speed;
		m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
	}
	if (m_enemy1Y < t_playerLocation.y)
	{
		m_enemy1Y += m_enemy1Speed;
		m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
	}
	if (m_enemy1Y > t_playerLocation.y)
	{
		m_enemy1Y -= m_enemy1Speed;
		m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
	}
}

void Enemy1::enemyBoundaryCheck()
{
	if (m_enemy1Body.getPosition().x <= LEFT_BOARDER)
	{
		m_enemy1X = LEFT_BOARDER;
	}
	if (m_enemy1Body.getPosition().x > RIGHT_BOARDER)
	{
		m_enemy1X = RIGHT_BOARDER;
	}
	if (m_enemy1Body.getPosition().y > BOTTOM_BOARDER)
	{
		m_enemy1Y = BOTTOM_BOARDER;
	}
	if (m_enemy1Body.getPosition().y <= TOP_BOARDER)
	{
		m_enemy1Y = TOP_BOARDER;
	}
}
