#ifndef FirstCatapultH
#define FirstCatapultH
#include <SFML/Graphics.hpp>
#include "Stone.h"
#include "SecondCatapult.h"

class FirstCatapult
{
	int health;
	double x, y, width, height;
	bool flag_hit, flag_win;

	sf::Font font1, font2;
	sf::String file;
	sf::Image image;
	sf::Texture texture;
public:
	FirstCatapult(sf::String F, double X, double Y, double W, double H);

	sf::Text text_angle, text_speed, text_mass, text_health, text_win;
	sf::Sprite sprite;
	
	void set_text(sf::Text &text, float x, float y, sf::Color color, std::string str, sf::Font *font, unsigned int size);
	void set_flag_hit();
	void health_catpult(FirstCatapult &fst_catapult, int m);
	bool get_flag_win();
};

#endif