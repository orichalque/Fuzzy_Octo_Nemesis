/**
 * \file MoveState.hpp
 * \brief State class for moving 
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * State of the State Pattern used for moving in the hallways of FuzzyOctoNemesis. Can switch to Fight State when meeting a monster
 *
 */
#ifndef __MOVESTATE_HPP__
#define __MOVESTATE_HPP__

class MoveState : public GameState
{
    public:
        MoveState(Game* game);
        void action();
        void action(shared_ptr<Monster> mon);
};

#endif
