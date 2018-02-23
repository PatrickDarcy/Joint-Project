// Game class declaration
#pragma once

#include "Player.h"   // include Player header file
#include "Follower.h"	// include Enemy header file
#include "Detector.h"
#include "Archers.h"
#include "Arrow.h"
#include "MyVector3.h"

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.

	sf::RenderWindow m_window;
	Player m_thePlayer;
	Follower m_follower;
	Detector m_detector;
	Archer m_archers[MAX_ARCHERS];
	Arrow m_archerArrow[MAX_ARCHERS]; 

	sf::Text m_message;
	sf::Font m_font;

	sf::Sprite m_background;
	sf::Texture m_texture;

	sf::Sprite m_gameOver;
	sf::Texture m_endingScreen;

	sf::Sprite m_health[MAX_HEALTH];
	sf::Texture m_hearts;

	float m_archerX;
	float m_archerY;

	float m_heartX;
	float m_heartY;

public:


public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
};
