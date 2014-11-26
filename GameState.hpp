/**
 * \file GameState.hpp
 * \brief Mother-class of the States
 * \author Thibault BLF. Corentin M.
 * \version 1.00
 * \date 27/11/2014
 *
 * Define the main methods of the states used for the State Pattern
 *
 */

#ifndef __GAMESTATE_HPP__
#define __GAMESTATE_HPP__



class GameState 
{
    public:
        GameState(Game *game);

        /*virtual void moveOnMob();
        virtual void winFight(bool boss);
        virtual void looseFight();
        virtual void lootChoosed(bool boss);
        virtual void nextLevel();
        virtual void dead();*/
        
        virtual void action();
        virtual void action(bool b);
        virtual void action(shared_ptr<Monster> mons);

    protected:
        Game* _game;
};

#endif
