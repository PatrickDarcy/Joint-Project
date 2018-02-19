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

public:
	Archer();
	void update(MyVector3  t_playerLocation);
	void draw(sf::RenderWindow & t_window);
	void downRange(MyVector3  t_playerLocation);
	sf::Sprite getBody();
	void setPosition(sf::Vector2f t_newPos);
	float m_downRangeLeft;
	float m_downRangeRight;
	float m_downRangeSwitch;
	MyVector3 m_archerLocation;
};
