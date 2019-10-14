#include <SFML/Graphics.hpp>
#include <sstream>
#include "Namespace.h"
#include "FirstCatapult.h"

FirstCatapult::FirstCatapult(sf::String F, double X, double Y, double W, double H)
{
	width = W;
	height = H;
	file = F;
	x = X;
	y = Y;
	health = bg::HP;
	flag_win = true;

	font1.loadFromFile(bg::file_fonts + bg::file_font_word);
	font2.loadFromFile(bg::file_fonts + bg::file_font_vict);

	set_text(text_angle, 20, 55, sf::Color::Blue, bg::STR_ANGLE, &font1, 40);
	set_text(text_speed, 20, 100, sf::Color::Blue, bg::STR_SPEED, &font1, 40);
	set_text(text_mass, 20, 145, sf::Color::Blue, bg::STR_MASS, &font1, 40);
	set_text(text_health, 20, 10, sf::Color::Magenta, bg::STR_HEALTH, &font1, 40);
	set_text(text_win, 250, 200, sf::Color::Black, bg::STR_VICT, &font2, 200);

	image.loadFromFile(bg::file_images + file);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(65 + abs(width - 126), 560 - (height - 93));
	sprite.setScale(1.5f, 1.5f);
	sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void FirstCatapult::set_text(sf::Text &text, float x, float y, sf::Color color, std::string str, sf::Font *font, unsigned int size)
{
	text.setFont(*font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setString(str);
	text.setPosition(x, y);
}

bool FirstCatapult::get_flag_win() { return flag_win; }
void FirstCatapult::set_flag_hit() { flag_hit = true; }

void FirstCatapult::health_catpult(FirstCatapult &fst_catapult, int m)
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
	fst_catapult.text_health.setString("Health: " + health_str.str());
}
