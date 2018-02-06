// Enemy Class Declaration
#pragma once

#include <SFML\Graphics.hpp>
#include"Player.h"
#include <iostream>
#include "MyVector3.h"

class Enemy1
{
	sf::Sprite m_enemy1Body;
	sf::Texture m_enemy1Left;
	sf::Texture m_enemy1Right;
	sf::Texture m_enemy1Up;
	sf::Texture m_enemy1Down;

	sf::CircleShape m_detectionZone;

	MyVector3 m_enemy1Speed;
	MyVector3 m_enemy1Position;
	float m_enemy1X;
	float m_enemy1Y;
	float m_detectionRadius;
	bool m_followEnemy;

public:

	Enemy1();

	void draw(sf::RenderWindow &t_window);
	void enemyDetection(MyVector3 t_playerLocation);
	void enemyFollow(MyVector3 t_playerLocation);
	void enemyBoundaryCheck();
	void move();
};