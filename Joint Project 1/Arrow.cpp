#include "Arrow.h"

Arrow::Arrow()
{
	m_arrowLocation = { 0,330,0 };

	if (!m_arrowDown.loadFromFile("ASSETS/IMAGES/arrowDown.png"))
	{
		std::cout << "error" << std::endl;
	}

	m_arrow.setTexture(m_arrowDown);
	m_arrow.setPosition(m_arrowLocation);
}

void Arrow::ifShot(MyVector3 t_enemyLocation)
{
	m_arrowLocation.y++;
}

void Arrow::update(MyVector3 t_enemyLocation)
{
	ifShot(t_enemyLocation);
}

void Arrow::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_arrow);
}
