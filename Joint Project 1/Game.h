// Game class declaration
#pragma once

#include "Player.h"   // include Player header file
#include "Enemy.h"	// include Enemy header file

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
	Enemy m_enemy1;
	sf::Sprite m_background;
	sf::Texture m_texture;

public:


public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
};
