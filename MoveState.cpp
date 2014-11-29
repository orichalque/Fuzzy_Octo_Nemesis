#include "MoveState.hpp"

MoveState::MoveState(Game* game) : GameState(game)
{}

void MoveState::action()
{
    int ch = getch();
    char cell;
    if ((ch == KEY_UP) or (ch == KEY_DOWN) or (ch == KEY_RIGHT) or (ch == KEY_LEFT)) {
        /* Update the model */
        _game -> getCharacter() -> updatePosition(ch, _game -> getGenerator() -> getSize(), _game -> getGenerator() -> getMap());        
        
        /* Warn the view */ 
        cell = _game -> getGenerator() -> updateCharPosition(_game -> getCharacter());
        shared_ptr<Monster> m;
        if (cell != ' ' and cell != '#' and cell != '@') {
            shared_ptr<Monster> mons = NULL;
            for (int i = 0; i < _game -> getMonstersList() -> size(); ++i) {
                m = _game -> getMonstersList() -> at(i);
                if (m -> getSymbol() == cell and mons == NULL) {
                    mons = m;
                    _game -> getMonstersList() -> erase(_game -> getMonstersList()-> begin() + i);
                }
            }
            _game -> setState(_game -> getFightState());
            _game -> action(mons);
        }
    }
}

void MoveState::action(shared_ptr<Monster> mon) {
    action();
}
