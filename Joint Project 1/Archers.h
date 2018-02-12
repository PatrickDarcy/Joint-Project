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
	MyVector3 m_archerLocation;
	float m_downRangeLeft;
	float m_downRangeRight;
	float m_downRangeSwitch;

public:
	Archer();
	void update(MyVector3  t_playerLocation);
	void draw(sf::RenderWindow & t_window);
	void downRange(MyVector3  t_playerLocation);
	sf::Sprite getBody();


};
