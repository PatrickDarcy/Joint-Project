// Player class declaration
#pragma once

#include<SFML\Graphics.hpp>
#include"Globals.h"
#include<iostream>

class Player
{
	// private data members
	sf::Sprite m_playerBody;
	sf::Texture m_playerLeft;
	sf::Texture m_playerRight;
	sf::Texture m_playerUp;
	sf::Texture m_playerDown;

	float m_speed;
	float m_playerX;
	float m_playerY;

public:
	Player();


	sf::Sprite getBody();
	void update();
	void draw(sf::RenderWindow &t_window);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void boundaryCheck();
	sf::Vector2f getPosition();
};