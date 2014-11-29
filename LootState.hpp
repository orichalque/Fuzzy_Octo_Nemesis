/**
 * \file LootState.hpp
 * \brief State for looting the dead monsters
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * State of the State Pattern used for getting loot after the fight. Called after FightState
 *
 */

#ifndef __LOOTSTATE_HPP__
#define __LOOTSTATE_HPP__

class LootState : public GameState
{
	public:
		LootState(Game * game);
		void action(shared_ptr<Monster> mon);
};

#endif
