#include <SFML/Graphics.hpp>
#include "Namespace.h"
#include "Menu.h"

Menu::Menu()
{
	setlocale(LC_ALL, "Russian");

	isMenu = true;
	menuNum = 0;

	texture1.loadFromFile(bg::file_images + bg::backgrd_menu1);
	texture2.loadFromFile(bg::file_images + bg::backgrd_menu2);

	sprite1.setTexture(texture1);
	sprite1.setScale(1.2f, 1.2f);
	sprite1.setPosition(0, 0);

	sprite2.setTexture(texture2);
	sprite2.setScale(0.5f, 0.53f);
	sprite2.setPosition(0, 0);

	font1.loadFromFile(bg::file_fonts + bg::file_font_menu1);
	font2.loadFromFile(bg::file_fonts + bg::file_font_menu2);

	set_text(text_menu1, 50, 50, sf::Color(74, 101, 92), sf::Color::Black, 2, "New game", &font1, 60);
	set_text(text_menu2, 50, 150, sf::Color(74, 101, 92), sf::Color::Black, 2, "Rules", &font1, 60);
	set_text(text_menu3, 50, 250, sf::Color(74, 101, 92), sf::Color::Black, 2, "Control", &font1, 60);
	set_text(text_menu4, 50, 350, sf::Color(74, 101, 92), sf::Color::Black, 2, "Exit", &font1, 60);
	set_text(text_rul, 20, 20, sf::Color(225, 204, 79), sf::Color(77, 34, 14), 1.5, bg::RULES, &font2, 36);
	set_text(text_contr, 20, 20, sf::Color(225, 204, 79), sf::Color(77, 34, 14), 1.5, bg::CONTROL, &font2, 36);
}

void Menu::show_menu(sf::RenderWindow &window)
{
	isMenu = true;
	while (isMenu)
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();
			
		window.clear();

		text_menu1.setFillColor(sf::Color(74, 101, 92));
		text_menu2.setFillColor(sf::Color(74, 101, 92));
		text_menu3.setFillColor(sf::Color(74, 101, 92));
		text_menu4.setFillColor(sf::Color(74, 101, 92));
		menuNum = 0;

		if (sf::IntRect(text_menu1.getGlobalBounds()).contains(sf::Mouse::getPosition(window)))
		{
			text_menu1.setFillColor(sf::Color(42, 66, 92));
			menuNum = 1;
		}
		if (sf::IntRect(text_menu2.getGlobalBounds()).contains(sf::Mouse::getPosition(window)))
		{
			text_menu2.setFillColor(sf::Color(42, 66, 92));
			menuNum = 2;
		}
		if (sf::IntRect(text_menu3.getGlobalBounds()).contains(sf::Mouse::getPosition(window)))
		{
			text_menu3.setFillColor(sf::Color(42, 66, 92));
			menuNum = 3;
		}
		if (sf::IntRect(text_menu4.getGlobalBounds()).contains(sf::Mouse::getPosition(window)))
		{
			text_menu4.setFillColor(sf::Color(42, 66, 92));
			menuNum = 4;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1)
				isMenu = false;
			if (menuNum == 2)
			{
				window.draw(sprite2);
				window.draw(text_rul);
				window.display();
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
			}
			if (menuNum == 3)
			{
				window.draw(sprite2);
				window.draw(text_contr);
				window.display();
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
			}
			if (menuNum == 4)
			{
				window.close();
				isMenu = false;
			}
		}

		window.draw(sprite1);
		window.draw(text_menu1);
		window.draw(text_menu2);
		window.draw(text_menu3);
		window.draw(text_menu4);
		window.display();
	}
}

void Menu::set_text(sf::Text &text, float x, float y, sf::Color color, sf::Color color_out, float r, std::string str, sf::Font *font, unsigned int size)
{
	text.setFont(*font);
	text.setCharacterSize(size);
	text.setFillColor(color);
	text.setOutlineThickness(r);
	text.setOutlineColor(color_out);
	text.setString(str);
	text.setPosition(x, y);
}