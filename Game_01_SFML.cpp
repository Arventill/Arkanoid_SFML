// Game_01_SFML.cpp : This is Arkanoid SFML Game

#include "Ball.h"
#include "Pad.h"
#include "Brick.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <Windows.h>
#include <string>
#include <cwchar>

unsigned int tillTheEnd = 36;
const short windX = 800;	 //window
const short windY = 600;
const short ballPosX = 350;	 //ball
const short ballPosY = 500;
const short padPosX = 400;	 //pad
const short padPosY = 550;
const short columns = 9;	 //bricks
const short rows = 4;
const short brickW = 60;
const short brickH = 20;

#pragma region HelperMethods
template <class T1, class T2> bool isIntersecting(T1& a, T2& b) //uniwersalna funkcja zwracaj¹ca wart. bool dla 2 obiektów dowolnego typu
{
	return a.right() >= b.left() && a.left() <= b.right()
		&& a.top() <= b.bot() && a.bot() >= b.top();
}

bool ColisionTest(Brick& bBrick, Ball& bBall)
{
	if (!isIntersecting(bBrick, bBall))
		return false;
	else
	{
		bBrick.destroy();
		tillTheEnd--;

		float overlapLeft{ bBall.right() - bBrick.left() };
		float overlapRight{ bBrick.left() - bBall.right() };
		float overlapTop{ bBall.bot() - bBrick.top() };
		float overlapBot{ bBrick.bot() - bBall.top() };

		bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
		bool ballFromTop(abs(overlapTop) < abs(overlapBot));

		float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
		float minOverlapY{ ballFromTop ? overlapTop : overlapBot };

		if (abs(minOverlapX) < abs(minOverlapY))
			ballFromLeft ? bBall.moveLeft() : bBall.moveRight();
		else
			ballFromTop ? bBall.moveUp() : bBall.moveDown();
	}
}
#pragma endregion

int main()
{
#pragma region onCreate
	Ball ball(ballPosX, ballPosY);
	Pad pad(padPosX, padPosY);
	unsigned brickX{ columns }, brickY{ rows }, brickWidth{ brickW }, brickHeight{ brickH };

	std::vector<Brick> bricks;
	for (int i = 0; i < brickY; i++)
	{
		for (int j = 0; j < brickX; j++)
		{
			bricks.emplace_back((j + 1)*(brickWidth + 20), (i + 2)*(brickHeight + 10), brickWidth, brickHeight);
			//placing my bricks ( block * (width + freeSpace) , anyways back to this later.
		}
	}

	sf::RenderWindow window{ {windX,windY}, "Arkanoid Game" };
	window.setFramerateLimit(60); //60ps
#pragma endregion

#pragma region MainLoop
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		for (auto& brick : bricks) //  <-- foreach loop
		{
			if (ColisionTest(brick, ball))
				break;
		}
		auto iterator = std::remove_if(begin(bricks), end(bricks), [](Brick& brick)
			{ return brick.isDestroyed(); });
		bricks.erase(iterator, end(bricks));
		for (auto& brick : bricks) //  <-- foreach loop
		{ 
			window.draw(brick); 
		}
		
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed) //closing my game by button
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			pad.right();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			pad.left();

		
		ball.update(pad.currentPos(), pad.param());
		window.draw(ball);
		window.draw(pad);
		window.display();
		
		if (tillTheEnd == 0 || ball.top() >= 550)
		{
			window.clear(sf::Color::Black);
			std::string gameOver = "GAME OVER";
			sf::Font font;
			sf::Text text(gameOver, font, 75);
			if (!font.loadFromFile("arial.ttf"))
				return EXIT_FAILURE;
			/*_CONSOLE_FONT_INFOEX textProps;
			textProps.dwFontSize.Y = 55;*/
			ball.~Ball();
			pad.~Pad();
			/*SetCursorPos( ((window.getSize().x / 2) - (gameOver.length() / 2)), window.getSize().y );
			SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),NULL,&textProps);
			std::cout << gameOver;*/
			text.setFillColor(sf::Color::White);
			text.setStyle(sf::Text::Bold);
			text.setPosition( ((windX / 2) - (gameOver.length()*25 )), windY / 2.5f ); //w tym przypadku wymuszenie wyœrodkowania tekstu
			window.draw(text);
			window.display();

			Sleep(2500);
			window.close();
		}
	}
#pragma endregion
}