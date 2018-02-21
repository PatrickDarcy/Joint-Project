// author: Patrick Darcy

#include "Player.h"   // include Player header file

// Player function definitions here
Player::Player()// default constructor
{
	m_speed = { 2.5,2.5,0 };
	m_playerLocation = { 200,160,0 };

	if (!m_playerDown.loadFromFile("ASSETS/IMAGES/down.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_playerLeft.loadFromFile("ASSETS/IMAGES/left.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_playerRight.loadFromFile("ASSETS/IMAGES/right.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_playerUp.loadFromFile("ASSETS/IMAGES/up.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_playerDown.loadFromFile("ASSETS/IMAGES/down.png"))
	{
		std::cout << "error" << std::endl;
	}

	m_playerBody.setTexture(m_playerDown);
	m_playerBody.setPosition( m_playerLocation );
	m_arrowOnce = 0;
	m_detectorOnce = 0;
	m_followerOnce = 0;
	m_lives = 4;
	m_isDead = false;
}

sf::Sprite Player::getBody()// return the player sprite
{
	return sf::Sprite(m_playerBody);
}

void Player::update(MyVector3 t_followerLocation, MyVector3 t_detectorLocation)
{
	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveDown();
	}

	boundaryCheck();
	collisionWithEnemies(t_followerLocation, t_detectorLocation);
}


void Player::draw(sf::RenderWindow & t_window)// draws the player
{
	t_window.draw(m_playerBody);
}

void Player::moveLeft()// moves the player left and changes the sprite direction
{
	m_playerLocation.x -= m_speed.x;

	m_playerBody.setTexture(m_playerLeft);
	m_playerBody.setPosition( m_playerLocation );
	m_direction = WEST;
}

void Player::moveRight()// moves the player right and changes the sprite direction
{
	m_playerLocation.x += m_speed.x;

	m_playerBody.setTexture(m_playerRight);
	m_playerBody.setPosition( m_playerLocation);

	m_direction = EAST;
}

void Player::moveUp()// moves the player up and shows the back of the player
{
	m_playerLocation.y -= m_speed.y;

	m_playerBody.setTexture(m_playerUp);
	m_playerBody.setPosition( m_playerLocation );

	m_direction = NORTH;
}

void Player::moveDown()// moves the player down and shows the front of the player
{
	m_playerLocation.y += m_speed.y;

	m_playerBody.setTexture(m_playerDown);
	m_playerBody.setPosition( m_playerLocation);

	m_direction = SOUTH;
}

void Player::boundaryCheck()// makes sure the player is in the boundary and not off the screen
{
	if (m_playerBody.getPosition().x <= LEFT_BOARDER)
	{
		m_playerLocation.x = LEFT_BOARDER;
	}
	if (m_playerBody.getPosition().x > RIGHT_BOARDER)
	{
		m_playerLocation.x = RIGHT_BOARDER;
	}
	if (m_playerBody.getPosition().y > BOTTOM_BOARDER)
	{
		m_playerLocation.y = BOTTOM_BOARDER;
	}
	if (m_playerBody.getPosition().y <= TOP_BOARDER)
	{
		m_playerLocation.y = TOP_BOARDER;
	}
}

void Player::collisionWithEnemies(MyVector3 t_followerLocation, MyVector3 t_detectorLocation)
{
	double playerX = rand() % 400 + 1;
	double playerY = rand() % 300 + 1;

	if (m_playerLocation.x >= t_followerLocation.x && m_playerLocation.y >= t_followerLocation.y &&
		m_playerLocation.x <= t_followerLocation.x + PLAYER_WIDTH && m_playerLocation.y <= t_followerLocation.y + PLAYER_HEIGHT 
		&& m_followerOnce == 0)
	{
		std::cout << "Thats a sore boi" << std::endl;
		m_playerLocation = { playerX, playerY, 0 };
		m_lives--;
		m_followerOnce++;
	}
	else
	{
		m_followerOnce = 0;
	}

	if (m_playerLocation.x >= t_detectorLocation.x && m_playerLocation.y >= t_detectorLocation.y &&
		m_playerLocation.x <= t_detectorLocation.x + PLAYER_WIDTH && m_playerLocation.y <= t_detectorLocation.y + PLAYER_HEIGHT
		&& m_detectorOnce == 0)
	{
		std::cout << "That hurt" << std::endl;
		m_playerLocation = { playerX, playerY, 0 };
		m_lives--;
		m_detectorOnce++;
	}
	else
	{
		m_detectorOnce = 0;
	}
}

void Player::arrowCollisions(MyVector3 t_arrowLocation)
{
	double playerX = rand() % 400 + 1;
	double playerY = rand() % 300 + 1;
	if (t_arrowLocation.x >= m_playerLocation.x && t_arrowLocation.y >= m_playerLocation.y &&
		t_arrowLocation.x <= m_playerLocation.x + PLAYER_WIDTH && t_arrowLocation.y <= m_playerLocation.y + PLAYER_HEIGHT
		&& m_arrowOnce == 0)
	{
		std::cout << "Ouch" << std::endl;
		m_arrowOnce++;
		m_playerLocation = { playerX, playerY, 0 };
		m_lives--;
	}
	else
	{
		m_arrowOnce = 0;
	}
}

bool Player::playersDeath()
{
	if (m_lives < 0)
	{
		m_isDead = true;
	}
	return m_isDead;
}

MyVector3 Player::getPosition()
{
	return m_playerLocation;
}

int Player::direction()
{
	return m_direction;
}

