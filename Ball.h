#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable
{
private:
	const float ballRadius = 8.0f;  //const float ballRadius { 10.0f };
	const float ballVelocity = 5.0f;

	sf::CircleShape shape;
	sf::Vector2f velovity { ballVelocity, ballVelocity };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:
	Ball(float t_X, float t_Y);
	~Ball() = default;

	void update(sf::Vector2f, sf::Vector2f);
	float left();
	float right();
	float top();
	float bot();
};

