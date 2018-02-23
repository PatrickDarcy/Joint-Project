// Enemy Class Declaration
#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Globals.h"
#include <iostream>
#include "MyVector3.h"

class Detector
{
	sf::Sprite m_enemy1Body;
	sf::Texture m_enemy1Left;
	sf::Texture m_enemy1Right;
	sf::Texture m_enemy1Up;
	sf::Texture m_enemy1Down;

	sf::SoundBuffer m_arrowHit;
	sf::Sound m_arrowhit;

	sf::CircleShape m_detectionZone;

	MyVector3 m_enemy1Speed;
	MyVector3 m_enemy1Location;
	float m_detectionRadius;
	int m_direction;
	bool m_followPlayer;
	bool m_respawn;

public:

	Detector();

	void draw(sf::RenderWindow &t_window);
	void enemyDetection(MyVector3 t_playerLocation);
	void enemyFollow(MyVector3 t_playerLocation);
	void enemyBoundaryCheck();
	void move();
	void update(MyVector3 t_playerLocation, MyVector3 t_arrowLocation);
	void spriteFacing();
	void shotByPlayer(MyVector3 t_playerArrow);
	bool isDead();
	int direction();
	MyVector3 getPosition();
};