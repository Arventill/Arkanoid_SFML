#pragma once
#include <SFML/Graphics.hpp>

class Pad : public sf::Drawable
{
private:
	const float h{ 20.0f };
	const float w{ 110.0f };
	const float padVelocity{ 5.8f };
	sf::Vector2f testVex{ w,h };

	sf::RectangleShape shape;
	sf::Vector2f velocity{ padVelocity, 0.0f };
	sf::Vector2f rVelocity{ -padVelocity, 0.0f };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:
	Pad(float t_X, float t_Y);
	~Pad() = default;

	void left();
	void right();
	sf::Vector2f currentPos();
	sf::Vector2f param();
};

