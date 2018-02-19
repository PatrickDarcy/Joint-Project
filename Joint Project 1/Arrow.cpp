#include "Arrow.h"

Arrow::Arrow()
{
	m_arrowSpeed = 3.5;
	m_arrowLocation = { 31,40,0 };
	m_shootArrow = 0;

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
	if (m_arrowLocation.y > SCREEN_HEIGHT)
	{
		m_arrowLocation = t_shooter + MyVector3{6,0,0};
		m_shootArrow = 0;
	}
}

void Arrow::update(MyVector3 t_target, MyVector3 t_shooter)
{	
	m_shootArrow++;
	arrowShot(t_shooter);
	collisionWithPlayer(t_target);
}

void Arrow::draw(sf::RenderWindow & t_window)
{
	t_window.draw(m_arrow);
}

void Arrow::collisionWithPlayer(MyVector3 t_target)
{
	if (m_arrowLocation.x >= t_target.x && m_arrowLocation.y >= t_target.y && 
		m_arrowLocation.x <= t_target.x + PLAYER_WIDTH && m_arrowLocation.y <= t_target.y + PLAYER_HEIGHT)
	{
		std::cout << "Ouch" << std::endl;
	}
}
