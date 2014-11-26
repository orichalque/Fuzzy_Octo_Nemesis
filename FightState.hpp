/**
 * \file FightState.hpp
 * \brief State class for fightning
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * State of the State Pattern used for the fights in FuzzyOctoNemesis
 *
 */


#ifndef __FIGHTSTATE_HPP__
#define __FIGHTSTATE_HPP__

class FightState : public GameState
{
	public:
		FightState(Game * game);
		void action(shared_ptr<Monster> m);
};

#endif
