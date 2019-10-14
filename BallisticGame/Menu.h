#ifndef MenuH
#define MenuH

class Menu
{
	bool isMenu;
	short int menuNum;

	sf::Font font1, font2;
	sf::Text text_menu1, text_menu2, text_menu3, text_menu4, text_rul, text_contr;
	sf::Texture texture1, texture2;
	sf::Sprite sprite1, sprite2;

	void set_text(sf::Text &text, float x, float y, sf::Color color, sf::Color color_out, float r, std::string str, sf::Font *font, unsigned int size);
public:
	Menu();
	void show_menu(sf::RenderWindow &window);
};

#endif
