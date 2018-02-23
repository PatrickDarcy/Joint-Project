//enemy class declarartion
#pragma once

#include <SFML\Graphics.hpp>
#include "Globals.h"
#include<iostream>

class detectingEnemy
{
	sf::Sprite m_enemy2Body;
	sf::Texture m_enemy2Left;
	sf::Texture m_enemy2Right;
	sf::Texture m_enemy2Up;
	sf::Texture m_enemy2Down;

	float m_enemySpeed;
	float m_enemyX;
	float m_enemyY;

public:

	detectingEnemy();

	void draw(sf::RenderWindow &t_window);
	void enemyBoundaryCheck();
};
