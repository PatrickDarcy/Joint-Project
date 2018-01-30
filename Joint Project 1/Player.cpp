// author: Patrick Darcy

#include "Player.h"   // include Player header file

// Player function definitions here
Player::Player()
{
	speed = 2.5f;

	playerX = 200;
	playerY = 160;

	if (!playerDown.loadFromFile("ASSETS/IMAGES/down.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerDown);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

sf::Sprite Player::getBody()
{
	return sf::Sprite(playerBody);
}

void Player::update()
{
}

void Player::draw(sf::RenderWindow & t_window)
{
	t_window.draw(playerBody);
}

void Player::moveLeft()
{
	playerX -= speed;
	if (!playerLeft.loadFromFile("ASSETS/IMAGES/left.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerLeft);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveRight()
{
	playerX += speed;
	if (!playerRight.loadFromFile("ASSETS/IMAGES/right.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerRight);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveUp()
{
	playerY -= speed;
	if (!playerUp.loadFromFile("ASSETS/IMAGES/up.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerUp);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveDown()
{
	playerY += speed;
	if (!playerDown.loadFromFile("ASSETS/IMAGES/down.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerDown);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::boundaryCheck()
{
	if (playerBody.getPosition().x <= LEFT_BOARDER)
	{
		playerX = LEFT_BOARDER;
	}
	if (playerBody.getPosition().x > RIGHT_BOARDER)
	{
		playerX = RIGHT_BOARDER;
	}
	if (playerBody.getPosition().y > BOTTOM_BOARDER)
	{
		playerY = BOTTOM_BOARDER;
	}
	if (playerBody.getPosition().y <= TOP_BOARDER)
	{
		playerY = TOP_BOARDER;
	}
}