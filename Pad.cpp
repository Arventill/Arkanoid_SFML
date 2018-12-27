#include "Pad.h"

Pad::Pad(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setFillColor(sf::Color::Yellow);
	shape.setOrigin(w/2, h/2);
	shape.setSize(testVex);
}

void Pad::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

void Pad::right()
{
	if (shape.getPosition().x + w/2 <= 800 - 10)
		shape.move(this->velocity);
}
void Pad::left()
{
	if (shape.getPosition().x - w/2 >= 0 + 10)
		shape.move(this->rVelocity);
}
sf::Vector2f Pad::currentPos()
{
	return {shape.getPosition().x, shape.getPosition().y};
}
sf::Vector2f Pad::param()
{
	return { w, h };
}