#ifndef GameH
#define GameH
#include <SFML/Graphics.hpp>
#include "FirstCatapult.h"
#include "SecondCatapult.h"
#include "Stone.h"

class Game
{
protected:
	int mass, k5, k8;
	float time_catapult, time_alpha, time_speed, temp;
	double CurrentFrame, CurrentFrameBack, speed, alpha, time_fly, t;
	bool flag, flag_game, flag_open, flag_alpha, flag_speed;
	
	sf::Clock clock, clock_fly;
	
	void count_stones();
public:
	Game();

	void Angle(sf::Text &text);
	void Speed(sf::Text &text);
	void Mass(sf::Text &text);
	void restart(FirstCatapult &fst_catapult, SecondCatapult &snd_catapult, sf::Text &text1, sf::Text &text2, sf::Text &text3);

	bool get_flag_game();
};

#endif