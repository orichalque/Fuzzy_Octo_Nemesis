/**
 * \file EndGameState.hpp
 * \class EndGameState
 * \brief State ending the game.
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * State of the State Pattern used when beating the last boss, or diing in a fight
 *
 */

#ifndef __ENDGAMESTATE_HPP__
#define __ENDGAMESTATE_HPP__

class EndGameState : public GameState
{
	public:
		EndGameState(Game * game);
		void action(bool victory);

};

#endif
