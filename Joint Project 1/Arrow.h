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

public:

	Arrow();
	void ifShot(MyVector3 t_enemyLocation);
	void update(MyVector3 t_enemyLocation);
	void draw(sf::RenderWindow & t_window);
};