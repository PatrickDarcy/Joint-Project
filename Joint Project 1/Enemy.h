// Enemy Class Declaration
#pragma once

#include <SFML\Graphics.hpp>
#include "Globals.h"
#include <iostream>
#include "MyVector3.h"

class Enemy
{
	sf::Sprite m_enemyBody;
	sf::Texture m_enemyLeft;
	sf::Texture m_enemyRight;
	sf::Texture m_enemyUp;
	sf::Texture m_enemyDown;

	float m_enemySpeed;
	double m_enemyX;
	double m_enemyY;

public:

	Enemy();

	void draw(sf::RenderWindow &t_window);
	void enemyFollow(MyVector3 t_playerLocation);
	void enemyBoundaryCheck();
};
