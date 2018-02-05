// Enemy Class Declaration
#pragma once

#include <SFML\Graphics.hpp>
#include"Player.h"
#include <iostream>

class Enemy1
{
	sf::Sprite m_enemy1Body;
	sf::Texture m_enemy1Left;
	sf::Texture m_enemy1Right;
	sf::Texture m_enemy1Up;
	sf::Texture m_enemy1Down;

	sf::CircleShape m_detectionZone;

	float m_enemy1Speed;
	float m_enemy1X;
	float m_enemy1Y;

public:

	Enemy1();

	void draw(sf::RenderWindow &t_window);
	void enemyFollow(sf::Vector2f t_playerLocation);
	void enemyBoundaryCheck();
};