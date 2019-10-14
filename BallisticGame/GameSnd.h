#ifndef GameSndH
#define GameSndH
#include "Game.h"

class GameSnd : public Game
{
	bool flag_sndCat, flag_fly, flag_fall, flag_down;
public:
	GameSnd();

	void func_trajectory(Stone &stone, bool flag, FirstCatapult &fst_catapult);
	void update(SecondCatapult &snd_catapult, SecondCatapult &snd_catapult_back);
	void restartSnd();

	bool get_flag_sndCat();
	bool get_flag_fly();
	bool get_flag_fall();
	bool get_flag_down();
};

#endif