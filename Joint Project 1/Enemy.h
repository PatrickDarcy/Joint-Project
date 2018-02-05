// Enemy Class Declaration
#pragma once

#include <SFML\Graphics.hpp>
#include"Player.h"
#include <iostream>

class Enemy
{
	sf::Sprite m_enemyBody;
	sf::Texture m_enemyLeft;
	sf::Texture m_enemyRight;
	sf::Texture m_enemyUp;
	sf::Texture m_enemyDown;

	float m_enemySpeed;
	float m_enemyX;
	float m_enemyY;

public:

	Enemy();

	void draw(sf::RenderWindow &t_window);
	void enemyFollow(sf::Vector2f t_playerLocation);
	void enemyBoundaryCheck();
};
