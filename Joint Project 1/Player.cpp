// author: Patrick Darcy

#include "Player.h"   // include Player header file

// Player function definitions here
Player::Player()// default constructor
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

sf::Sprite Player::getBody()// return the player sprite
{
	return sf::Sprite(playerBody);
}

void Player::update()
{
}

void Player::draw(sf::RenderWindow & t_window)// draws the player
{
	t_window.draw(playerBody);
}

void Player::moveLeft()// moves the player left and changes the sprite direction
{
	playerX -= speed;
	if (!playerLeft.loadFromFile("ASSETS/IMAGES/left.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerLeft);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveRight()// moves the player right and changes the sprite direction
{
	playerX += speed;
	if (!playerRight.loadFromFile("ASSETS/IMAGES/right.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerRight);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveUp()// moves the player up and shows the back of the player
{
	playerY -= speed;
	if (!playerUp.loadFromFile("ASSETS/IMAGES/up.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerUp);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveDown()// moves the player down and shows the front of the player
{
	playerY += speed;
	if (!playerDown.loadFromFile("ASSETS/IMAGES/down.png"))
	{
		std::cout << "error" << std::endl;
	}
	playerBody.setTexture(playerDown);
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::boundaryCheck()// makes sure the player is in the boundary and not off the screen
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