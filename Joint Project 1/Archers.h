//Enemy Archer
#pragma once

#include <SFML\Graphics.hpp>
#include "Globals.h"
#include <iostream>
#include "MyVector3.h"

class Archer
{
	sf::Sprite m_archerBody;
	sf::Texture m_archerDown;

	int m_noOfArchers;
	int m_direction;

public:
	Archer();
	void update(MyVector3  t_playerLocation);
	void draw(sf::RenderWindow & t_window);
	sf::Sprite getBody();
	void setPosition(sf::Vector2f t_newPos);
	int direction();
	MyVector3 m_archerLocation;
};
