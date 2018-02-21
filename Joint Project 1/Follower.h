// Enemy Class Declaration
#pragma once

#include <SFML\Graphics.hpp>
#include "Globals.h"
#include <iostream>
#include "MyVector3.h"

class Follower
{
	sf::Sprite m_enemyBody;
	sf::Texture m_enemyLeft;
	sf::Texture m_enemyRight;
	sf::Texture m_enemyUp;
	sf::Texture m_enemyDown;

	MyVector3 m_speed;
	MyVector3 m_enemyLocation;

	int m_direction;

public:

	Follower();

	void draw(sf::RenderWindow &t_window);
	void enemyFollow(MyVector3 t_playerLocation);
	void enemyBoundaryCheck();
	void update(MyVector3 t_playerLocation);
	int direction();
	MyVector3 getPosition();
};
