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
