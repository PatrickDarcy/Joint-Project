#include "Follower.h"

Follower::Follower()
{
	m_enemyLocation = { 200,80,0 };
	m_speed = { 1,1,0 };

	if (!m_enemyDown.loadFromFile("ASSETS/IMAGES/enemy1Down.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_enemyRight.loadFromFile("ASSETS/IMAGES/enemy1Right.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_enemyLeft.loadFromFile("ASSETS/IMAGES/enemy1Left.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_enemyDown.loadFromFile("ASSETS/IMAGES/enemy1Down.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_enemyUp.loadFromFile("ASSETS/IMAGES/enemy1Up.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_enemyBody.setTexture(m_enemyDown);
	m_enemyBody.setPosition( m_enemyLocation);
}

void Follower::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemyBody);
}

void Follower::enemyFollow(MyVector3 t_playerLocation)
{
	if (m_enemyLocation.x < t_playerLocation.x)
	{
		m_enemyLocation.x += m_speed.x;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyRight);
		m_enemyBody.setPosition( m_enemyLocation );
	}
	if (m_enemyLocation.x > t_playerLocation.x)
	{
		m_enemyLocation.x -= m_speed.x;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyLeft);
		m_enemyBody.setPosition( m_enemyLocation);
	}
	if (m_enemyLocation.y < t_playerLocation.y)
	{
		m_enemyLocation.y += m_speed.y;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyDown);
		m_enemyBody.setPosition( m_enemyLocation );
	}
	if (m_enemyLocation.y > t_playerLocation.y)
	{
		m_enemyLocation.y -= m_speed.y;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyUp);
		m_enemyBody.setPosition( m_enemyLocation);
	}

	
}

void Follower::enemyBoundaryCheck()
{
	if (m_enemyLocation.x <= LEFT_BOARDER)
	{
		m_enemyLocation.x = LEFT_BOARDER;
	}
	if (m_enemyBody.getPosition().x > RIGHT_BOARDER)
	{
		m_enemyLocation.x = RIGHT_BOARDER;
	}
	if (m_enemyBody.getPosition().y > BOTTOM_BOARDER)
	{
		m_enemyLocation.y = BOTTOM_BOARDER;
	}
	if (m_enemyBody.getPosition().y <= TOP_BOARDER)
	{
		m_enemyLocation.y = TOP_BOARDER;
	}
}

void Follower::update(MyVector3 t_playerLocation)
{
	enemyBoundaryCheck();
	enemyFollow(t_playerLocation);
}

MyVector3 Follower::getPosition()
{
	return m_enemyLocation;
}
