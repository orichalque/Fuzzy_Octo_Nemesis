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
