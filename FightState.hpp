#ifndef __FIGHTSTATE_HPP__
#define __FIGHTSTATE_HPP__

class FightState : public GameState
{
	public:
		FightState(Game * game);
		void action(shared_ptr<Monster> m);
};

#endif
