#include "Enemy1.h"

Enemy1::Enemy1()
{
	m_enemy1Speed = MyVector3{ 1.5f,1.5f,0 };
	m_enemy1X = 180.0f;
	m_enemy1Y = 80.0f;
	m_enemy1Position = MyVector3 (m_enemy1X, m_enemy1Y, 0.0f);

	if (!m_enemy1Down.loadFromFile("ASSETS/IMAGES/enemyDown.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_enemy1Body.setTexture(m_enemy1Down);
	m_enemy1Body.setPosition( m_enemy1X ,m_enemy1Y);

	m_detectionRadius = 75;
	m_detectionZone.setPosition(m_enemy1X - CENTER_OF_CIRCLE, m_enemy1Y - CENTER_OF_CIRCLE);
	m_detectionZone.setRadius(m_detectionRadius);
	m_detectionZone.setFillColor(sf::Color{ 0,0,0,100 });

	m_followEnemy = false;
}

void Enemy1::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemy1Body);
	t_window.draw(m_detectionZone);
}

void Enemy1::enemyDetection(MyVector3 t_playerLocation)
{
	if ((t_playerLocation - m_detectionZone.getPosition()).length() <= m_detectionRadius)
	{
		m_followEnemy = true;
		std::cout << "It Works" << std::endl;
	}
	else
	{
		m_followEnemy = false;
	}
}

void Enemy1::enemyFollow(MyVector3 t_playerLocation)
{
	if (m_followEnemy == true)
	{
		if (m_enemy1X < t_playerLocation.x)
		{
			m_enemy1X += m_enemy1Speed.x;
			m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
		}
		if (m_enemy1X > t_playerLocation.x)
		{
			m_enemy1X -= m_enemy1Speed.x;
			m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
		}
		if (m_enemy1Y < t_playerLocation.y)
		{
			m_enemy1Y += m_enemy1Speed.y;
			m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
		}
		if (m_enemy1Y > t_playerLocation.y)
		{
			m_enemy1Y -= m_enemy1Speed.y;
			m_enemy1Body.setPosition(m_enemy1X, m_enemy1Y);
		}

		m_detectionZone.setPosition(m_enemy1X - CENTER_OF_CIRCLE, m_enemy1Y - CENTER_OF_CIRCLE);
	}
	else
	{
		move();
		enemyBoundaryCheck();
		m_followEnemy = false;
	}
}


void Enemy1::enemyBoundaryCheck()
{
	if (m_enemy1Body.getPosition().x <= LEFT_BOARDER)
	{
		m_enemy1Speed.x = -(m_enemy1Speed.x);
	}
	if (m_enemy1Body.getPosition().x > RIGHT_BOARDER)
	{
		m_enemy1Speed.x = -(m_enemy1Speed.x);
	}
	if (m_enemy1Body.getPosition().y > BOTTOM_BOARDER)
	{
		m_enemy1Speed.y = -(m_enemy1Speed.y);
	}
	if (m_enemy1Body.getPosition().y <= TOP_BOARDER)
	{
		m_enemy1Speed.y = -(m_enemy1Speed.y);
	}
}

void Enemy1::move()
{
	m_enemy1Position += m_enemy1Speed;
	m_enemy1Body.setPosition(m_enemy1Position);
	m_detectionZone.setPosition(m_enemy1Position);
}

