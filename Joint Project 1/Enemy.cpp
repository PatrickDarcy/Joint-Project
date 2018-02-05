#include "Enemy.h"

Enemy::Enemy()
{
	m_enemySpeed = 1.0f;

	m_enemyX = 200.0f;
	m_enemyY = 80.0f;

	if (!m_enemyDown.loadFromFile("ASSETS/IMAGES/enemy1Down.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_enemyBody.setTexture(m_enemyDown);
	m_enemyBody.setPosition(sf::Vector2f{ m_enemyX,m_enemyY });
}

void Enemy::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemyBody);
}

void Enemy::enemyFollow(sf::Vector2f t_playerLocation)
{
	if (m_enemyX < t_playerLocation.x)
	{
		m_enemyX += m_enemySpeed;
		m_enemyBody.setPosition(m_enemyX, m_enemyY);
	}
	if (m_enemyX > t_playerLocation.x)
	{
		m_enemyX -= m_enemySpeed;
		m_enemyBody.setPosition(m_enemyX, m_enemyY);
	}
	if (m_enemyY < t_playerLocation.y)
	{
		m_enemyY += m_enemySpeed;
		m_enemyBody.setPosition(m_enemyX, m_enemyY);
	}
	if (m_enemyY > t_playerLocation.y)
	{
		m_enemyY -= m_enemySpeed;
		m_enemyBody.setPosition(m_enemyX, m_enemyY);
	}

	
}

void Enemy::enemyBoundaryCheck()
{
	if (m_enemyBody.getPosition().x <= LEFT_BOARDER)
	{
		m_enemyX = LEFT_BOARDER;
	}
	if (m_enemyBody.getPosition().x > RIGHT_BOARDER)
	{
		m_enemyX = RIGHT_BOARDER;
	}
	if (m_enemyBody.getPosition().y > BOTTOM_BOARDER)
	{
		m_enemyY = BOTTOM_BOARDER;
	}
	if (m_enemyBody.getPosition().y <= TOP_BOARDER)
	{
		m_enemyY = TOP_BOARDER;
	}
}
