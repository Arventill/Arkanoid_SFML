// Game_01_SFML.cpp : This is Arkanoid

#include "Ball.h"
#include "Pad.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
	Ball ball(400,300);
	Pad pad(400,550);
	sf::RenderWindow window{ {800,600}, "Arkanoid Game" };
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		// End of Window Event
		
		ball.update(pad.currentPos(), pad.param());
		window.draw(ball);
		window.draw(pad);
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pad.right();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pad.left();
		}
	}
}