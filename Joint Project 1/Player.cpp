// author: Patrick Darcy

#include "Player.h"   // include Player header file

// Player function definitions here
Player::Player()// default constructor
{
	m_speed = 2.5f;

	m_playerX = 200;
	m_playerY = 160;

	if (!m_playerDown.loadFromFile("ASSETS/IMAGES/down.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_playerBody.setTexture(m_playerDown);
	m_playerBody.setPosition(sf::Vector2f{ m_playerX,m_playerY });
}

sf::Sprite Player::getBody()// return the player sprite
{
	return sf::Sprite(m_playerBody);
}

void Player::update()
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

}

void Player::draw(sf::RenderWindow & t_window)// draws the player
{
	t_window.draw(m_playerBody);
}

void Player::moveLeft()// moves the player left and changes the sprite direction
{
	m_playerX -= m_speed;
	if (!m_playerLeft.loadFromFile("ASSETS/IMAGES/left.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_playerBody.setTexture(m_playerLeft);
	m_playerBody.setPosition(sf::Vector2f{ m_playerX,m_playerY });
}

void Player::moveRight()// moves the player right and changes the sprite direction
{
	m_playerX += m_speed;
	if (!m_playerRight.loadFromFile("ASSETS/IMAGES/right.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_playerBody.setTexture(m_playerRight);
	m_playerBody.setPosition(sf::Vector2f{ m_playerX,m_playerY });
}

void Player::moveUp()// moves the player up and shows the back of the player
{
	m_playerY -= m_speed;
	if (!m_playerUp.loadFromFile("ASSETS/IMAGES/up.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_playerBody.setTexture(m_playerUp);
	m_playerBody.setPosition(sf::Vector2f{ m_playerX,m_playerY });
}

void Player::moveDown()// moves the player down and shows the front of the player
{
	m_playerY += m_speed;
	if (!m_playerDown.loadFromFile("ASSETS/IMAGES/down.png"))
	{
		std::cout << "error" << std::endl;
	}
	m_playerBody.setTexture(m_playerDown);
	m_playerBody.setPosition(sf::Vector2f{ m_playerX,m_playerY });
}

void Player::boundaryCheck()// makes sure the player is in the boundary and not off the screen
{
	if (m_playerBody.getPosition().x <= LEFT_BOARDER)
	{
		m_playerX = LEFT_BOARDER;
	}
	if (m_playerBody.getPosition().x > RIGHT_BOARDER)
	{
		m_playerX = RIGHT_BOARDER;
	}
	if (m_playerBody.getPosition().y > BOTTOM_BOARDER)
	{
		m_playerY = BOTTOM_BOARDER;
	}
	if (m_playerBody.getPosition().y <= TOP_BOARDER)
	{
		m_playerY = TOP_BOARDER;
	}
}

sf::Vector2f Player::getPosition()
{
	return sf::Vector2f(m_playerX,m_playerY);
}
