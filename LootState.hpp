#ifndef __LOOSTATE_HPP__
#define __LOOSTATE_HPP__

class LootState : public GameState
{
	public:
		LootState(Game * game);
		void action(shared_ptr<Monster> mon);
};

#endif
