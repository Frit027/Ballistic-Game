#include "Background.h"
#include "Namespace.h"

Background::Background(sf::String F, double X, double Y)
{
	x = X;
	y = Y;
	file = F;

	image.loadFromFile(bg::file_images + file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, x, y));
	sprite.setScale(1.5f, 1.3f);
}