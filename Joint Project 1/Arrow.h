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
	sf::Texture m_arrowUp;
	sf::Texture m_arrowRight;
	sf::Texture m_arrowLeft;

	MyVector3 m_arrowLocation;
	float m_arrowSpeed;

public:

	Arrow();
	void arrowShot(MyVector3 t_enemyLocation);
	void update(MyVector3 t_playerLocation, MyVector3 t_enemyLocation);
	void draw(sf::RenderWindow & t_window);
	MyVector3 getPosition();
};