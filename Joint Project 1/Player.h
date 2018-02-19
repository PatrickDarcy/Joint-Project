// Player class declaration
#pragma once

#include<SFML\Graphics.hpp>
#include"Globals.h"
#include<iostream>
#include "MyVector3.h"

class Player
{
	// private data members
	sf::Sprite m_playerBody;
	sf::Texture m_playerLeft;
	sf::Texture m_playerRight;
	sf::Texture m_playerUp;
	sf::Texture m_playerDown;

	MyVector3 m_playerLocation;
	MyVector3 m_speed;

public:
	Player();


	sf::Sprite getBody();
	void update(MyVector3 t_followerLocation);
	void draw(sf::RenderWindow &t_window);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void boundaryCheck();
	void collisionWithFollower(MyVector3 t_followerLocation);
	MyVector3 getPosition();
};