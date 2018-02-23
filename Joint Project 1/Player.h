// Player class declaration
#pragma once

#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
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

	sf::Sound m_linkHurt;
	sf::SoundBuffer m_linkhurt;

	sf::Sprite m_playerArrow;
	sf::Texture m_arrowDown;
	sf::Texture m_arrowUp;
	sf::Texture m_arrowRight;
	sf::Texture m_arrowLeft;

	MyVector3 m_playerLocation;
	MyVector3 m_speed;
	MyVector3 m_arrowLocation;
	MyVector3 m_arrowSpeed;

	int m_arrowOnce;
	int m_followerOnce;
	int m_detectorOnce;

	int m_direction;

	int m_lives;
	bool m_isDead;
	int m_score;

public:
	Player();


	sf::Sprite getBody();
	void update(MyVector3 t_followerLocation, MyVector3 t_detectorLocation, bool t_followerHit, bool t_detectorHit);
	void draw(sf::RenderWindow &t_window);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void boundaryCheck();
	void collisionWithEnemies(MyVector3 t_followerLocation, MyVector3 t_detectorLocation);
	void arrowCollisions(MyVector3 t_arrowLocation);
	bool playersDeath();
	void arrowShoot();
	void followerHit(bool t_followerhit);
	void detectorHit(bool t_detectorHit);
	MyVector3 getPosition();
	MyVector3 getArrow();
	int playersScore();
	int getLives();
	int direction();
};