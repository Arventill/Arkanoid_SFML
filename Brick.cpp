#include "Brick.h"

Brick::Brick(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_Width, t_Height });
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(t_Width / 2.0f, t_Height / 2.0f);
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

#pragma region positions
float Brick::right()
{
	return this->shape.getPosition().x + shape.getSize().x / 2.0f;
}
float Brick::left()
{
	return this->shape.getPosition().x - shape.getSize().x / 2.0f;
}
float Brick::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.0f;
}
float Brick::bot()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.0f;
}

sf::Vector2f Brick::getPos()
{
	return this->shape.getPosition();
}
sf::Vector2f Brick::getSize()
{
	return this->shape.getSize();
}
#pragma endregion

#pragma region action
bool Brick::isDestroyed()
{
	return this->destroyed;
}
void Brick::destroy()
{
	this->destroyed = true;
}
void Brick::update()
{
	; //nope
}
#pragma endregion