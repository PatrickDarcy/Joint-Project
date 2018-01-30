// Player class declaration
#pragma once

#include<SFML\Graphics.hpp>
#include<iostream>

class Player
{
	// private data members
	sf::Sprite playerBody;
	sf::Texture playerLeft;
	sf::Texture playerRight;
	sf::Texture playerUp;
	sf::Texture playerDown;

	float speed;
	float playerX;
	float playerY;

public:
	Player();
	const float LEFT_BOARDER = 20;
	const float RIGHT_BOARDER = 360;
	const float BOTTOM_BOARDER = 280;
	const float TOP_BOARDER = 80;

	sf::Sprite getBody();
	void update();
	void draw(sf::RenderWindow &t_window);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void boundaryCheck();
};