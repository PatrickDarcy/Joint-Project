#include "Archers.h"

Archer::Archer()// archers default constructor
{
	m_noOfArchers = MAX_ARCHERS;

	if (!m_archerDown.loadFromFile("ASSETS/IMAGES/enemy2345.png"))
	{
		std::cout << "error" << std::endl;
	}

	m_archerBody.setTexture(m_archerDown);

	m_direction = SOUTH;

}

void Archer::update(MyVector3 t_playerLocation)
{
}

void Archer::draw(sf::RenderWindow & t_window)// draws the archer
{
	t_window.draw(m_archerBody);
}


sf::Sprite Archer::getBody()
{
	return(m_archerBody);
}

void Archer::setPosition(sf::Vector2f t_newPos)// used to set the archer positions
{
	m_archerBody.setPosition(t_newPos);
}

int Archer::direction()// returns the archers position
{
	return m_direction;
}

