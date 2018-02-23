#include "Detector.h"

Detector::Detector()// the detectors default position
{
	m_enemy1Speed = MyVector3{ 1.5f,1.5f,0 };
	m_enemy1Location = MyVector3 (180.0f , 80.0f, 0.0f);

	if (!m_enemy1Down.loadFromFile("ASSETS/IMAGES/enemyDown.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_enemy1Up.loadFromFile("ASSETS/IMAGES/enemyUp.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_enemy1Left.loadFromFile("ASSETS/IMAGES/enemyLeft.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_enemy1Right.loadFromFile("ASSETS/IMAGES/enemyRight.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_arrowHit.loadFromFile("ASSETS/SOUNDS/arrowHit.wav"))
	{
		std::cout << "error" << std::endl;
	}

	m_arrowhit.setBuffer(m_arrowHit);
	m_arrowhit.setVolume(100000);

	m_enemy1Body.setTexture(m_enemy1Down);
	m_enemy1Body.setPosition( m_enemy1Location);

	m_detectionRadius = 50;
	m_detectionZone.setPosition(m_enemy1Location);
	m_detectionZone.setRadius(m_detectionRadius);
	m_detectionZone.setFillColor(sf::Color{ 0,0,0,100 });

	m_followPlayer = false;
	m_respawn = false;
}

void Detector::draw(sf::RenderWindow & t_window)// draws the detector enemy
{
	t_window.draw(m_enemy1Body);
}

void Detector::enemyDetection(MyVector3 t_playerLocation)// this checks if the player has been detected by the enemy
{
	if ((t_playerLocation - m_detectionZone.getPosition()).length() <= m_detectionRadius)
	{
		m_followPlayer = true;
		std::cout << "Detected" << std::endl;
	}
	else
	{
		m_followPlayer = false;
	}

}

void Detector::enemyFollow(MyVector3 t_playerLocation)// this makes the enemy follow the player
{
	float enemySpeedX = 1.5;
	float enemySpeedY = 1.5;

	if (m_enemy1Location.x < t_playerLocation.x)
	{
		m_enemy1Location.x += enemySpeedX;
		m_direction = EAST;
	}
	if (m_enemy1Location.x > t_playerLocation.x)
	{
		m_enemy1Location.x -= enemySpeedX;
		m_direction = WEST;
	}
	if (m_enemy1Location.y < t_playerLocation.y)
	{
		m_enemy1Location.y += enemySpeedY;
		m_direction = SOUTH;
	}
	if (m_enemy1Location.y > t_playerLocation.y)
	{
		m_enemy1Location.y -= enemySpeedY;
		m_direction = NORTH;
	}
	m_enemy1Body.setPosition(m_enemy1Location);
}


void Detector::enemyBoundaryCheck()// makes sure the enemy is in the boundary
{
	if (m_enemy1Body.getPosition().x <= LEFT_BOARDER)
	{
		m_enemy1Location.x = LEFT_BOARDER;
	}
	if (m_enemy1Body.getPosition().x > RIGHT_BOARDER)
	{
		m_enemy1Location.x = RIGHT_BOARDER;
	}
	if (m_enemy1Body.getPosition().y > BOTTOM_BOARDER)
	{
		m_enemy1Location.y = BOTTOM_BOARDER;
	}
	if (m_enemy1Body.getPosition().y <= TOP_BOARDER)
	{
		m_enemy1Location.y = TOP_BOARDER;
	}

}

void Detector::move()// this moves the enemy whilst the player has not been detected
{

	if (m_enemy1Location.x >= RIGHT_BOARDER)
	{
		m_enemy1Speed.x = -(m_enemy1Speed.x);
		m_direction = WEST;
	}
	if (m_enemy1Location.x <= LEFT_BOARDER)
	{
		m_enemy1Speed.x = -(m_enemy1Speed.x);
		m_direction = EAST;
	}

	m_enemy1Location.x += m_enemy1Speed.x;
	m_enemy1Body.setPosition(m_enemy1Location);
	m_detectionZone.setPosition(m_enemy1Location);
}

void Detector::update(MyVector3 t_playerLocation, MyVector3 t_arrowLocation)// the detectors update
{
	spriteFacing();
	if (m_followPlayer == true)
	{
		enemyFollow(t_playerLocation);
	}
	else
	{
		move();
	}

	enemyDetection(t_playerLocation);
	enemyBoundaryCheck();
	shotByPlayer(t_arrowLocation);
}

void Detector::spriteFacing()// changes the spite to face the right direction
{
	if (m_direction == EAST)
	{
		m_enemy1Body.setTexture(m_enemy1Right,true);
		m_enemy1Body.setPosition(m_enemy1Location);
	}
	if (m_direction == WEST)
	{
		m_enemy1Body.setTexture(m_enemy1Left,true);
		m_enemy1Body.setPosition(m_enemy1Location);
	}
	if (m_direction == NORTH)
	{
		m_enemy1Body.setTexture(m_enemy1Up,true);
		m_enemy1Body.setPosition(m_enemy1Location);
	}
	if (m_direction == SOUTH)
	{
		m_enemy1Body.setTexture(m_enemy1Down,true);
		m_enemy1Body.setPosition(m_enemy1Location);
	}
}

void Detector::shotByPlayer(MyVector3 t_playersArrow)// this respawns the enemy and increases his detection radius when it is shot by the player
{
	if (t_playersArrow.x >= m_enemy1Location.x && t_playersArrow.y >= m_enemy1Location.y &&
		t_playersArrow.x <= m_enemy1Location.x + SPRITE_WIDTH && t_playersArrow.y <= m_enemy1Location.y + SPRITE_HEIGHT)
	{
		m_respawn = true;
		m_enemy1Location = RESPAWN;
		m_enemy1Body.setPosition(m_enemy1Location);
		m_detectionRadius++;
		if (m_enemy1Speed.x <= MAX_ENEMY_SPEED.x && m_enemy1Speed.y <= MAX_ENEMY_SPEED.y)
		{
			m_enemy1Speed += {0.1, 0.1, 0};
		}
		m_arrowhit.play();
	}
	else
	{
		m_respawn = false;
	}
}

bool Detector::isDead()
{
	return m_respawn;
}

int Detector::direction()
{
	return m_direction;
}


MyVector3 Detector::getPosition()
{
	return m_enemy1Location;
}

