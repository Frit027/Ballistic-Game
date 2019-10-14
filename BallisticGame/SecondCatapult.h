#ifndef SecondCatapultH
#define SecondCatapultH
#include <SFML/Graphics.hpp>

class SecondCatapult
{
	double x, y, width, height;
	int health;
	bool flag_hit, flag_win;
	
	sf::Font font;
	sf::String file;
	sf::Image image;
	sf::Texture texture;
public:
	SecondCatapult(sf::String F, double X, double Y, double W, double H, float cr);

	sf::Text text_angle, text_speed, text_mass, text_health;
	sf::Sprite sprite;

	void set_text(sf::Text &text, float x, float y, sf::Color color, std::string str, sf::Font *font, unsigned int size);
	void set_flag_hit();
	void health_catpult(SecondCatapult &snd_catapult, int m);
	bool get_flag_win();
};

#endif
