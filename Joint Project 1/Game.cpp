// Name: Patrick Darcy
// Login: C00226157
// Date: 29/01/18
// Time taken: 
//---------------------------------------------------------------------------
// Project description: TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 



#include "Game.h"   // include Game header file


int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : m_window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
, thePlayer{}
// Default constructor
{
}

void Game::loadContent()
// load the font file & setup the message
{
}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (m_window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{

			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		thePlayer.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		thePlayer.moveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		thePlayer.moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		thePlayer.moveDown();
	}

	// update any game variables here ...

}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	m_window.clear();
	thePlayer.draw(m_window);
	m_window.display();
}