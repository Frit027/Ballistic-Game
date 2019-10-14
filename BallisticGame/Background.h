#ifndef BackgroundH
#define BackgroundH
#include <SFML/Graphics.hpp>

class Background
{
	double x, y;
	sf::String file;
	sf::Image image;
	sf::Texture texture;
public:
	Background(sf::String F, double X, double Y);
	sf::Sprite sprite;
};

#endif