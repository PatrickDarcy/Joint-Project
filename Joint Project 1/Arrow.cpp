#include "Arrow.h"

Arrow::Arrow()
{
	m_arrowSpeed = 3.5;
	m_arrowLocation = {};

	if (!m_arrowDown.loadFromFile("ASSETS/IMAGES/arrowDown.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_arrowUp.loadFromFile("ASSETS/IMAGES/arrowUp.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_arrowRight.loadFromFile("ASSETS/IMAGES/arrowLeft.png"))
	{
		std::cout << "error" << std::endl;
	}
	if (!m_arrowLeft.loadFromFile("ASSETS/IMAGES/arrowRight.png"))
	{
		std::cout << "error" << std::endl;
	}

	m_arrow.setTexture(m_arrowDown);
	m_arrow.setPosition(m_arrowLocation);
}

void Arrow::arrowShot(MyVector3 t_shooter)
{
	m_arrowLocation.y += m_arrowSpeed;
	m_arrow.setPosition(m_arrowLocation);

	if (m_arrowLocation.y > SCREEN_HEIGHT || m_arrowLocation.y < ARROW_HEIGHT)
	{
		m_arrowLocation = t_shooter + MyVector3{6,0,0};
	}
	if (m_arrowLocation.x > SCREEN_WIDTH || m_arrowLocation.x < ARROW_WIDTH)
	{
		m_arrowLocation = t_shooter;
	}
}

void Arrow::update(MyVector3 t_shooter)
{
	arrowShot(t_shooter);
}

void Arrow::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_arrow);
}

MyVector3 Arrow::getPosition()
{
	return m_arrowLocation;
}
