#include <SFML/Graphics.hpp>
#include "FirstCatapult.h"
#include "SecondCatapult.h"
#include "Background.h"
#include "Stone.h"
#include "GameFst.h"
#include "GameSnd.h"
#include "Menu.h"
#include "Namespace.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(bg::W, bg::H), bg::GAME_NAME);

	Menu menu;
	menu.show_menu(window);

	FirstCatapult fst_catapult(bg::file_catapult, bg::X_F_CT, bg::Y_F_CT, bg::W_CT, bg::H_CT);
	FirstCatapult fst_catapult_back(bg::file_catapult, bg::X_F_BCT, bg::Y_F_BCT, bg::W_BCT, bg::H_BCT);

	SecondCatapult snd_catapult(bg::file_catapult, bg::X_S_CT, bg::Y_S_CT, bg::W_CT, bg::H_CT, bg::S_CT_CR);
	SecondCatapult snd_catapult_back(bg::file_catapult, bg::X_S_BCT, bg::Y_S_BCT, bg::W_BCT, bg::H_BCT, bg::SB_CT_CR);

	Background background(bg::file_backgrd, bg::X_BACKGRD, bg::Y_BACKGRD);
	Stone stone(bg::file_stone, bg::XF_ST, bg::YF_ST, bg::X_ST1, bg::Y_ST);
	Stone stone_snd(bg::file_stone, bg::XF_ST, bg::YF_ST, bg::X_ST2, bg::Y_ST);
	GameFst game1; GameSnd game2;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.clear();

		if (game1.get_flag_game() && game2.get_flag_game() && !game2.get_flag_sndCat() && fst_catapult.get_flag_win() && snd_catapult.get_flag_win())
		{
			game1.restart(fst_catapult, snd_catapult, fst_catapult.text_angle, fst_catapult.text_speed, fst_catapult.text_mass);
			game1.restartFst();
			game2.restart(fst_catapult, snd_catapult, snd_catapult.text_angle, snd_catapult.text_speed, snd_catapult.text_mass);
			game2.restartSnd();
		}
		if (!game1.get_flag_game() && fst_catapult.get_flag_win())
		{
			game1.Angle(fst_catapult.text_angle);
			game1.Speed(fst_catapult.text_speed);
			game1.Mass(fst_catapult.text_mass);
			game1.update(fst_catapult, fst_catapult_back);
			game1.func_trajectory(stone, game1.get_flag_fly(), snd_catapult);
		}
		if (game1.get_flag_game() && snd_catapult.get_flag_win() && (!game2.get_flag_fall() || !game2.get_flag_down()))
		{
			game2.Angle(snd_catapult.text_angle);
			game2.Speed(snd_catapult.text_speed);
			game2.Mass(snd_catapult.text_mass);
			game2.update(snd_catapult, snd_catapult_back);
			game2.func_trajectory(stone_snd, game2.get_flag_fly(), fst_catapult);
		}

		window.draw(background.sprite);
		window.draw(fst_catapult.text_angle);
		window.draw(snd_catapult.text_angle);
		window.draw(fst_catapult.text_speed);
		window.draw(snd_catapult.text_speed);
		window.draw(fst_catapult.text_mass);
		window.draw(snd_catapult.text_mass);
		window.draw(fst_catapult.text_health);
		window.draw(snd_catapult.text_health);
		window.draw(fst_catapult.sprite);
		window.draw(snd_catapult.sprite);
		
		if (game1.get_flag_fstCat())
			window.draw(fst_catapult_back.sprite);
		if (game2.get_flag_sndCat())
			window.draw(snd_catapult_back.sprite);
		
		if (game1.get_flag_fly())
			window.draw(stone.sprite);
		if (game2.get_flag_fly())
			window.draw(stone_snd.sprite);

		if (!fst_catapult.get_flag_win() || !snd_catapult.get_flag_win())
			window.draw(fst_catapult.text_win);
				
		window.display();
	}

	return 0;
}