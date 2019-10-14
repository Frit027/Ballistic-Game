#include <SFML/Graphics.hpp>
#include "Stone.h"

Stone::Stone(sf::String F, double W, double H, double X, double Y)
{
	width = W;
	height = H;
	file = F;
	x = X;
	y = Y;

	image.loadFromFile("C:\\Users\\user\\Documents\\CourseWork\\BallisticGame\\Debug\\Pictures\\" + file);
	image.createMaskFromColor(sf::Color(255, 255, 255));
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
	sprite.setScale(1.5f, 1.5f);
	sprite.setTextureRect(sf::IntRect(4, 10, width, height));
}

double Stone::get_x() { return x; }
double Stone::get_y() { return y; }

void Stone::set_x(double cr_x) { x = cr_x; }
void Stone::set_y(double cr_y) { y = cr_y; }