#include "Detector.h"

Detector::Detector()
{
	m_enemy1Speed = MyVector3{ 1.5f,1.5f,0 };
	m_enemy1Position = MyVector3 (180.0f , 80.0f, 0.0f);

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

	m_enemy1Body.setTexture(m_enemy1Down);
	m_enemy1Body.setPosition( m_enemy1Position);

	m_detectionRadius = 50;
	m_detectionZone.setPosition(m_enemy1Position);
	m_detectionZone.setRadius(m_detectionRadius);
	m_detectionZone.setFillColor(sf::Color{ 0,0,0,100 });

	m_followPlayer = false;
}

void Detector::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_enemy1Body);
}

void Detector::enemyDetection(MyVector3 t_playerLocation)
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

void Detector::enemyFollow(MyVector3 t_playerLocation)
{
	float enemySpeedX = 1.5;
	float enemySpeedY = 1.5;

	if (m_enemy1Position.x < t_playerLocation.x)
	{
		m_enemy1Position.x += enemySpeedX;
		m_direction = EAST;
	}
	if (m_enemy1Position.x > t_playerLocation.x)
	{
		m_enemy1Position.x -= enemySpeedX;
		m_direction = WEST;
	}
	if (m_enemy1Position.y < t_playerLocation.y)
	{
		m_enemy1Position.y += enemySpeedY;
		m_direction = SOUTH;
	}
	if (m_enemy1Position.y > t_playerLocation.y)
	{
		m_enemy1Position.y -= enemySpeedY;
		m_direction = NORTH;
	}
	m_enemy1Body.setPosition(m_enemy1Position);
}


void Detector::enemyBoundaryCheck()
{
	if (m_enemy1Body.getPosition().x <= LEFT_BOARDER)
	{
		m_enemy1Position.x = LEFT_BOARDER;
	}
	if (m_enemy1Body.getPosition().x > RIGHT_BOARDER)
	{
		m_enemy1Position.x = RIGHT_BOARDER;
	}
	if (m_enemy1Body.getPosition().y > BOTTOM_BOARDER)
	{
		m_enemy1Position.y = BOTTOM_BOARDER;
	}
	if (m_enemy1Body.getPosition().y <= TOP_BOARDER)
	{
		m_enemy1Position.y = TOP_BOARDER;
	}

}

void Detector::move()
{
	if (m_enemy1Position.x >= LEFT_BOARDER && m_enemy1Position.x <= RIGHT_BOARDER)
	{
		m_enemy1Position.x += m_enemy1Speed.x;
	}
	if (m_enemy1Position.x >= RIGHT_BOARDER)
	{
		m_enemy1Speed.x = -(m_enemy1Speed.x);
		m_enemy1Body.setPosition(m_enemy1Position);
		m_direction = WEST;
	}
	if (m_enemy1Position.x <= LEFT_BOARDER)
	{
		m_enemy1Speed.x = -(m_enemy1Speed.x);
		m_enemy1Body.setPosition(m_enemy1Position);
		m_direction = EAST;
	}
	m_enemy1Body.setPosition(m_enemy1Position);
	m_detectionZone.setPosition(m_enemy1Position);
}

void Detector::update(MyVector3 t_playerLocation)
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
}

void Detector::spriteFacing()
{
	if (m_direction == EAST)
	{
		m_enemy1Body.setTexture(m_enemy1Right,true);
		m_enemy1Body.setPosition(m_enemy1Position);
	}
	if (m_direction == WEST)
	{
		m_enemy1Body.setTexture(m_enemy1Left,true);
		m_enemy1Body.setPosition(m_enemy1Position);
	}
	if (m_direction == NORTH)
	{
		m_enemy1Body.setTexture(m_enemy1Up,true);
		m_enemy1Body.setPosition(m_enemy1Position);
	}
	if (m_direction == SOUTH)
	{
		m_enemy1Body.setTexture(m_enemy1Down,true);
		m_enemy1Body.setPosition(m_enemy1Position);
	}
}

MyVector3 Detector::getPosition()
{
	return m_enemy1Position;
}

