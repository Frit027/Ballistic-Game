#include "GameSnd.h"
#include "Namespace.h"

GameSnd::GameSnd()
{
	flag_fall = flag_down = flag_fly = flag_sndCat = false;
}

bool GameSnd::get_flag_sndCat() { return flag_sndCat; }
bool GameSnd::get_flag_fly() { return flag_fly; }
bool GameSnd::get_flag_fall() { return flag_fall; }
bool GameSnd::get_flag_down() { return flag_down; }

void GameSnd::update(SecondCatapult &snd_catapult, SecondCatapult &snd_catapult_back)
{
	time_catapult = static_cast<float>(clock.getElapsedTime().asMicroseconds());
	clock.restart();
	time_catapult /= 800;

	if (!flag_fly && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		CurrentFrame += 0.005 * time_catapult;
		snd_catapult.sprite.setTextureRect(sf::IntRect(130 * (int)CurrentFrame + 264, 12, 126, 93));

		if (CurrentFrame > 3)
		{
			CurrentFrame = 3.0;
			if (!flag_fly)
			{
				t = clock_fly.getElapsedTime().asMilliseconds();
				flag_fly = true;
				flag_sndCat = true;
				time_fly = t;
			}
		}
	}
	if (flag_sndCat)
	{
		CurrentFrameBack += 0.005 * time_catapult;
		snd_catapult_back.sprite.setTextureRect(sf::IntRect(abs(130 * (int)CurrentFrameBack - 404), 118, 106, 106));

		if (CurrentFrameBack > 4)
		{
			CurrentFrameBack = 4.0;
			flag_sndCat = false;
			flag_down = true;
			snd_catapult.sprite.setTextureRect(sf::IntRect(bg::X_S_CT, bg::Y_S_CT, bg::W_CT, bg::H_CT));
		}
	}
}

void GameSnd::func_trajectory(Stone &stone, bool flag, FirstCatapult &fst_catapult)
{
	if (flag)
	{
		t = clock_fly.getElapsedTime().asMilliseconds();
		t = 0.005 * (t - time_fly);

		stone.set_x(-4 * speed * t * cos(alpha * bg::PI / 180) + bg::X_ST2);
		stone.set_y(-4 * speed * t * sin(alpha * bg::PI / 180) + 2 * bg::G * t * t + bg::Y_ST);

		if (stone.get_y() < 670.0)
			stone.sprite.setPosition(static_cast<float>(stone.get_x()), static_cast<float>(stone.get_y()));
		else
		{
			flag_game = flag_fall = true;
			count_stones();
		}

		if (fst_catapult.sprite.getGlobalBounds().intersects(stone.sprite.getGlobalBounds()))
			fst_catapult.health_catpult(fst_catapult, mass);

		flag_speed = flag_alpha = false;
	}
}

void GameSnd::restartSnd()
{
	flag_fall = flag_down = flag_fly = flag_sndCat = false;
}