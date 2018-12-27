// Game_01_SFML.cpp : This is Arkanoid

#include "Ball.h"
#include "Pad.h"
#include "Brick.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

template <class T1, class T2> bool isIntersecting(T1& a, T2& b) //uniwersalna funkcja zwracaj¹ca wart. bool dla dowolnych 2 typów obiektów
{
	return a.right() >= b.left() && a.left() <= b.right()
		&& a.top() <= b.bot() && a.bot() >= b.top();
}

bool ColisionTest(Brick& bBrick, Ball& bBall)
{
	if (!isIntersecting(bBrick, bBall)) return false;

	bBrick.destroy();

	float overlapLeft{ bBall.right() - bBrick.left() };
	float overlapRight{ bBrick.left() - bBall.right() };
	float overlapTop{ bBall.bot() - bBrick.top() };
	float overlapBot{ bBrick.bot() - bBall.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBot));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBot };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		ballFromLeft ? bBall.moveLeft() : bBall.moveRight();
	}
	else
	{
		ballFromTop ? bBall.moveUp() : bBall.moveDown();
	}
}

int main()
{
	Ball ball(400, 300);
	Pad pad(400, 550);
	unsigned brickX{ 9 }, brickY{ 4 }, brickWidth{ 60 }, brickHeight{ 20 };

	std::vector<Brick> bricks;
	for (int i = 0; i < brickY; i++)
	{
		for (int j = 0; j < brickX; j++)
		{
			bricks.emplace_back((j + 1)*(brickWidth + 20), (i + 2)*(brickHeight + 10), brickWidth, brickHeight);
			//
		}
	}


	sf::RenderWindow window{ {800,600}, "Arkanoid Game" };
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
#pragma region WindowEvent



		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
#pragma endregion

		ball.update(pad.currentPos(), pad.param());
		for (auto& brick : bricks)
			if (ColisionTest(brick,ball))
				break;

		auto iterator = std::remove_if(begin(bricks), end(bricks), [](Brick& brick) {return brick.isDestroyed(); });
		bricks.erase(iterator, end(bricks));

		for (auto& brick : bricks) //  <-- foreach
			window.draw(brick);

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