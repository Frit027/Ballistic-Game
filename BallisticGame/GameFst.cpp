#include "GameFst.h"
#include "Namespace.h"

GameFst::GameFst()
{
	flag_fly = flag_fstCat = false;
}

bool GameFst::get_flag_fstCat() { return flag_fstCat; }
bool GameFst::get_flag_fly() { return flag_fly; }

void GameFst::update(FirstCatapult &fst_catapult, FirstCatapult &fst_catapult_back)
{
	time_catapult = static_cast<float>(clock.getElapsedTime().asMicroseconds());
	clock.restart();
	time_catapult /= 800;
	if (!flag_fly && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		CurrentFrame += 0.005 * time_catapult;

		switch ((int)CurrentFrame)
		{
		case 0:
			fst_catapult.sprite.setTextureRect(sf::IntRect(259, 12, 130, 93));
			break;
		case 1:
			fst_catapult.sprite.setTextureRect(sf::IntRect(389, 12, 130, 93));
			break;
		case 2:
			fst_catapult.sprite.setTextureRect(sf::IntRect(519, 12, 126, 93));
			break;
		case 3:
			fst_catapult.sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
			break;
		}

		if (CurrentFrame > 3)
		{
			CurrentFrame = 3.0;
			if (!flag_fly)
			{
				t = clock_fly.getElapsedTime().asMilliseconds();
				flag_fly = true;
				time_fly = t;
				flag_fstCat = true;
			}
		}
	}
	if (flag_fstCat)
	{
		CurrentFrameBack += 0.005 * time_catapult;
		fst_catapult_back.sprite.setTextureRect(sf::IntRect(130 * (int)CurrentFrameBack + 133, 118, 119, 106));

		if (CurrentFrameBack > 4)
		{
			CurrentFrameBack = 4.0;
			fst_catapult.sprite.setTextureRect(sf::IntRect(bg::X_F_CT, bg::Y_F_CT, bg::W_CT, bg::H_CT));
			flag_fstCat = false;
		}
	}
}

void GameFst::func_trajectory(Stone &stone, bool flag, SecondCatapult &snd_catapult)
{
	if (flag)
	{
		t = clock_fly.getElapsedTime().asMilliseconds();
		t = 0.005 * (t - time_fly);

		stone.set_x(4 * speed * t * cos(alpha * bg::PI / 180) + bg::X_ST1);
		stone.set_y(-4 * speed * t * sin(alpha * bg::PI / 180) + 2 * bg::G * t * t + bg::Y_ST);

		if (stone.get_y() < 670.0)
			stone.sprite.setPosition(static_cast<float>(stone.get_x()), static_cast<float>(stone.get_y()));
		else if (!flag_fstCat)
		{
			flag_game = true;
			count_stones();
		}

		if (snd_catapult.sprite.getGlobalBounds().intersects(stone.sprite.getGlobalBounds()))
			snd_catapult.health_catpult(snd_catapult, mass);

		flag_speed = flag_alpha = false;
	}
}

void GameFst::restartFst()
{
	flag_fly = flag_fstCat = false;
}