// author: Patrick Darcy

#include "Player.h"   // include Player header file

// Player function definitions here
Player::Player()
{
	speed = 5.0f;

	playerX = 400;
	playerY = 300;

	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
	playerBody.setFillColor(sf::Color::Blue);
	playerBody.setSize(sf::Vector2f{ 20,20 });
}

sf::RectangleShape Player::getBody()
{
	return sf::RectangleShape(playerBody);
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
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveRight()
{
	playerX += speed;
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveUp()
{
	playerY -= speed;
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}

void Player::moveDown()
{
	playerY += speed;
	playerBody.setPosition(sf::Vector2f{ playerX,playerY });
}
