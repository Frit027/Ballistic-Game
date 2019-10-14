#ifndef GameFstH
#define GameFstH
#include "Game.h"

class GameFst : public Game
{
	bool flag_fstCat, flag_fly;
public:
	GameFst();

	void func_trajectory(Stone &stone, bool flag, SecondCatapult &snd_catapult);
	void update(FirstCatapult &fst_catapult, FirstCatapult &fst_catapult_back);
	void restartFst();

	bool get_flag_fstCat();
	bool get_flag_fly();
};

#endif
