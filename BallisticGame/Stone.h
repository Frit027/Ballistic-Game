#ifndef StoneH
#define StoneH
#include <SFML/Graphics.hpp>

class Stone
{
	double width, height, x, y;
	sf::String file;
	sf::Image image;
	sf::Texture texture;
public:
	Stone(sf::String F, double W, double H, double X, double Y);
	sf::Sprite sprite;

	double get_x();
	double get_y();

	void set_x(double cr_x);
	void set_y(double cr_y);
};

#endif