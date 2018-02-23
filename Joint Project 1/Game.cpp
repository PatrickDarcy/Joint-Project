// Name: Patrick Darcy
// Login: C00226157
// Date: 29/01/18
// Time taken: 
//---------------------------------------------------------------------------
// Project description: Zelda remake
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
, m_thePlayer{}
// Default constructor
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/bg.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_endingScreen.loadFromFile("ASSETS/IMAGES/bgGameover.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_hearts.loadFromFile("ASSETS/IMAGES/lives.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error" << std::endl;
	}

	m_message.setFont(m_font);
	m_message.setCharacterSize(14);
	m_message.setPosition(25, 25);
	m_message.setFillColor(sf::Color::Black);

	m_heartX = 273;
	m_heartY = 20;

	for (int index = 0; index < MAX_HEALTH; index++)
	{
		m_health[index].setTexture(m_hearts);
		m_health[index].setPosition(sf::Vector2f{ m_heartX,m_heartY });
		m_heartX += 10;
	}

	m_gameOver.setTexture(m_endingScreen);
	m_gameOver.setPosition(0, 0);
	m_background.setTexture(m_texture);
	m_background.setPosition( 0,0 );

	m_archerX = 25;
	m_archerY = 40;

	for (int index = 0; index < MAX_ARCHERS; index++)
	{
		m_archers[index].setPosition(sf::Vector2f{ m_archerX, m_archerY });
		m_archerX += 110;
	}
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
	if (m_thePlayer.playersDeath() == false)
	{
		m_thePlayer.update(m_follower.getPosition(), m_detector.getPosition(), m_follower.ifDead(), m_detector.isDead());
		m_detector.update(m_thePlayer.getBody().getPosition());
		m_follower.update(m_thePlayer.getBody().getPosition(),m_thePlayer.getArrow());
		for (int index = 0; index < MAX_ARCHERS; index++)
		{
			m_archers[index].update(m_thePlayer.getPosition());
			m_archerArrow[index].update(m_archers[index].getBody().getPosition());
			m_thePlayer.arrowCollisions(m_archerArrow[index].getPosition());
		}
		m_message.setString("SCORE: " + std::to_string(m_thePlayer.playersScore()));
	}

}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	m_window.clear();
	m_window.draw(m_background);
	m_thePlayer.draw(m_window);
	m_follower.draw(m_window);
	m_detector.draw(m_window);
	for (int index = 0; index < MAX_ARCHERS; index++)
	{
		m_archers[index].draw(m_window);
		m_archerArrow[index].draw(m_window);
	}	
	if (m_thePlayer.playersDeath() == true)
	{
		m_window.draw(m_gameOver);
	}
	for (int index = 0; index < m_thePlayer.getLives(); index++)
	{
		m_window.draw(m_health[index]);
	}
	m_window.draw(m_message);
	m_window.display();
}