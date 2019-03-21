#pragma once
#include <SFML/Graphics.hpp>

class Brick : public sf::Drawable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	sf::RectangleShape shape;
	bool destroyed{ false };

public:
	Brick(float, float, float, float);
	~Brick() = default;

	void update();
	void destroy();
	bool isDestroyed();
	sf::Vector2f getPos();
	sf::Vector2f getSize();

	float right();
	float left();
	float top();
	float bot();
};

