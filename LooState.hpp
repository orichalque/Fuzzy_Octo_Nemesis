#ifndef __LOOSTATE_HPP__
#define __LOOSTATE_HPP__

#include "GameState.hpp"

class LootState : public GameState
{
	public:
		LootState(shared_ptr<Game> game);

		void action(bool b);
}

#endif
