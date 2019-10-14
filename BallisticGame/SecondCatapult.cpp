#include <SFML/Graphics.hpp>
#include <sstream>
#include "Namespace.h"
#include "SecondCatapult.h"

SecondCatapult::SecondCatapult(sf::String F, double X, double Y, double W, double H, float cr)
{
	width = W;
	height = H;
	file = F;
	x = X;
	y = Y;
	health = bg::HP;
	flag_win = true;

	font.loadFromFile(bg::file_fonts + bg::file_font_word);

	set_text(text_angle, 970, 55, sf::Color::Red, bg::STR_ANGLE, &font, 40);
	set_text(text_speed, 970, 100, sf::Color::Red, bg::STR_SPEED, &font, 40);
	set_text(text_mass, 970, 145, sf::Color::Red, bg::STR_MASS, &font, 40);
	set_text(text_health, 970, 10, sf::Color::Magenta, bg::STR_HEALTH, &font, 40);

	image.loadFromFile(bg::file_images + file);
	image.flipHorizontally();
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(950.0, cr);
	sprite.setScale(1.5f, 1.5f);
	sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

bool SecondCatapult::get_flag_win() { return flag_win; }
void SecondCatapult::set_flag_hit() { flag_hit = true; }

void SecondCatapult::set_text(sf::Text &text, float x, float y, sf::Color color, std::string str, sf::Font *font, unsigned int size)
{
	text.setFont(*font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(str);
	text.setPosition(x, y);
}

void SecondCatapult::health_catpult(SecondCatapult &snd_catapult, int m)
{
	std::ostringstream health_str;
	if (m == bg::MASS1 && flag_hit)
	{
		health -= bg::MASS1;
		flag_hit = false;
	}
	if (m == bg::MASS2 && flag_hit)
	{
		health -= bg::MASS2;
		flag_hit = false;
	}
	if (m == bg::MASS3 && flag_hit)
	{
		health -= bg::MASS3;
		flag_hit = false;
	}

	if (health <= 0)
	{
		health = 0;
		flag_win = false;
	}

	health_str << health;
	snd_catapult.text_health.setString("Health: " + health_str.str());
}