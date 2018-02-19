// Arrow Class
#pragma once

#include <SFML\Graphics.hpp>
#include "Globals.h"
#include <iostream>
#include "MyVector3.h"

class Arrow
{
	sf::Sprite m_arrow;
	sf::Texture m_arrowDown;

	MyVector3 m_arrowLocation;
	float m_arrowSpeed;
	int m_shootArrow;

public:

	Arrow();
	void arrowShot(MyVector3 t_enemyLocation);
	void update(MyVector3 t_playerLocation, MyVector3 t_enemyLocation);
	void draw(sf::RenderWindow & t_window);
	void collisionWithPlayer(MyVector3 t_playerLocation);
};