#include <sstream>
#include <cmath>
#include "Game.h"
#include "Background.h"
#include "Namespace.h"

Game::Game()
{
	CurrentFrame = CurrentFrameBack = 0.0;
	temp = 0.0;
	k5 = 3;
	k8 = 1;
	mass = bg::MASS1;
	speed = alpha = 0.0;
	flag = flag_game = false;
	flag_speed = flag_alpha = flag_open = true;
}

bool Game::get_flag_game() { return flag_game; }

void Game::Angle(sf::Text &text)
{
	time_alpha = static_cast<float>(clock.getElapsedTime().asMicroseconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && flag_alpha)
	{
		time_alpha /= 800;
		alpha += 0.00005 * (time_alpha - temp);

		if (!flag)
		{
			temp = time_alpha - 300;
			flag = true;
		}

		if ((int)alpha > 90)
			alpha = 90;

		std::ostringstream alpha_str;
		alpha_str << (int)alpha;
		text.setString("Angle: " + alpha_str.str());
	}
	else
		flag = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		time_alpha /= 800;
		alpha += -0.00005 * (time_alpha - temp);

		if (!flag)
		{
			temp = time_alpha - 300;
			flag = true;
		}

		if ((int)alpha < 0)
			alpha = 0;

		std::ostringstream alpha_str;
		alpha_str << (int)alpha;
		text.setString("Angle: " + alpha_str.str());
	}
	else
		flag = false;
}

void Game::Speed(sf::Text &text)
{
	time_speed = static_cast<float>(clock.getElapsedTime().asMicroseconds());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && flag_speed)
	{
		time_speed /= 800;
		speed += 0.00005 * (time_speed - temp);

		if (!flag)
		{
			temp = time_speed - 300;
			flag = true;
		}

		if ((int)speed > 60)
			speed = 60;

		std::ostringstream speed_str;
		speed_str << (int)speed;
		text.setString("Speed: " + speed_str.str());
	}
	else
		flag = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		time_speed /= 800;
		speed += -0.00005 * (time_speed - temp);

		if (!flag)
		{
			temp = time_speed - 300;
			flag = true;
		}

		if ((int)speed < 0)
			speed = 0;

		std::ostringstream speed_str;
		speed_str << (int)speed;
		text.setString("Speed: " + speed_str.str());
	}
	else
		flag = false;
}

void Game::Mass(sf::Text &text)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		mass = bg::MASS1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && k5)
		mass = bg::MASS2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && k8)
		mass = bg::MASS3;
		
	std::ostringstream mass_str;
	mass_str << mass;
	text.setString("Stone mass: " + mass_str.str());
}

void Game::count_stones()
{
	if (flag_open)
	{
		if (mass == bg::MASS2)
			k5--;
		if (mass == bg::MASS3)
			k8 = 0;
		flag_open = false;
	}
}

void Game::restart(FirstCatapult &fst_catapult, SecondCatapult &snd_catapult, sf::Text &text1, sf::Text &text2, sf::Text &text3)
{
		fst_catapult.sprite.setTextureRect(sf::IntRect(bg::X_F_CT, bg::Y_F_CT, bg::W_CT, bg::H_CT));
		snd_catapult.sprite.setTextureRect(sf::IntRect(bg::X_S_CT, bg::Y_S_CT, bg::W_CT, bg::H_CT));
		text1.setString(bg::STR_ANGLE);
		text2.setString(bg::STR_SPEED);
		text3.setString(bg::STR_MASS);
		clock.restart();
		clock_fly.restart();
		CurrentFrame = CurrentFrameBack = 0.0;
		temp = 0.0;
		mass = bg::MASS1;
		speed = alpha = 0.0;
		flag = flag_game = false;
		flag_speed = flag_alpha = flag_open = true;
		snd_catapult.set_flag_hit();
		fst_catapult.set_flag_hit();
}