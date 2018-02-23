#include "Follower.h"

Follower::Follower()// the followers default costructor
{
	m_enemyLocation = RESPAWN;
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
	if (!m_arrowHit.loadFromFile("ASSETS/SOUNDS/arrowHit.wav"))
	{
		std::cout << "error" << std::endl;
	}

	m_arrowhit.setBuffer(m_arrowHit);
	m_arrowhit.setVolume(100000);

	m_enemyBody.setTexture(m_enemyDown);
	m_enemyBody.setPosition( m_enemyLocation);

	m_respawn = false;
}

void Follower::draw(sf::RenderWindow & t_window)// this draws the follower
{
	t_window.draw(m_enemyBody);
}

void Follower::enemyFollow(MyVector3 t_playerLocation)// the follower constantly follows the player
{
	if (m_enemyLocation.x < t_playerLocation.x)
	{
		m_enemyLocation.x += m_speed.x;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyRight);
		m_enemyBody.setPosition( m_enemyLocation );

		m_direction = EAST;
	}
	if (m_enemyLocation.x > t_playerLocation.x)
	{
		m_enemyLocation.x -= m_speed.x;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyLeft);
		m_enemyBody.setPosition( m_enemyLocation);

		m_direction = WEST;
	}
	if (m_enemyLocation.y < t_playerLocation.y)
	{
		m_enemyLocation.y += m_speed.y;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyDown);
		m_enemyBody.setPosition( m_enemyLocation );

		m_direction = SOUTH;
	}
	if (m_enemyLocation.y > t_playerLocation.y)
	{
		m_enemyLocation.y -= m_speed.y;
		m_enemyBody.setPosition(m_enemyLocation);

		m_enemyBody.setTexture(m_enemyUp);
		m_enemyBody.setPosition( m_enemyLocation);

		m_direction = NORTH;
	}

	
}

void Follower::enemyBoundaryCheck()// this keeps the follower in the map
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

void Follower::update(MyVector3 t_playerLocation, MyVector3 t_playersArrow)
{
	enemyBoundaryCheck();
	enemyFollow(t_playerLocation);
	shotByPlayer(t_playersArrow);
}

void Follower::shotByPlayer(MyVector3 t_playersArrow)// this relocates the enemy and increases his speed once shot by the player
{
	if (t_playersArrow.x >= m_enemyLocation.x && t_playersArrow.y >= m_enemyLocation.y &&
		t_playersArrow.x <= m_enemyLocation.x + SPRITE_WIDTH && t_playersArrow.y <= m_enemyLocation.y + SPRITE_HEIGHT)
	{
		m_respawn = true;
		m_enemyLocation = RESPAWN;
		m_enemyBody.setPosition(m_enemyLocation);
		if (m_speed.x <= MAX_ENEMY_SPEED.x && m_speed.y <= MAX_ENEMY_SPEED.y)
		{
			m_speed += {0.1, 0.1, 0};
		}
		m_arrowhit.play();
	}
	else
	{
		m_respawn = false;
	}
}

int Follower::direction()
{
	return m_direction;
}

bool Follower::ifDead()
{
	return m_respawn;
}


MyVector3 Follower::getPosition()
{
	return m_enemyLocation;
}
