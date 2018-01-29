// Player class declaration
#pragma once

#include<SFML\Graphics.hpp>

class Player
{
	// private data members
	sf::RectangleShape playerBody;
	float speed;
	float playerX;
	float playerY;

public:
	Player();
	sf::RectangleShape getBody();
	void update();
	void draw(sf::RenderWindow &t_window);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

};