#include "Ball.h"

Ball::Ball(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballRadius);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}
void Ball::update(sf::Vector2f pos, sf::Vector2f param)
{
	shape.move(this->velovity);

	if (this->left() <= 0)
		velovity.x = ballVelocity;
	else if (this->right() >= 800)
		velovity.x = -ballVelocity;

	if (this->top() <= 0)
		velovity.y = ballVelocity;
	else if (this->bot() >= 600)
		velovity.y = -ballVelocity;

	if (this->bot() >= pos.y - param.y / 2 && this->right() >= pos.x - param.x / 2 && this->left() <= pos.x + param.x/2)
	{
		velovity.y = -ballVelocity;
	}

}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}
float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}
float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}
float Ball::bot()
{
	return this->shape.getPosition().y + shape.getRadius();
}

void Ball::moveLeft()
{
	this->velovity.x = -ballVelocity;
}
void Ball::moveRight()
{
	this->velovity.x = ballVelocity;
}
void Ball::moveUp()
{
	this->velovity.y = -ballVelocity;
}
void Ball::moveDown()
{
	this->velovity.y = ballVelocity;
}