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
        
        if (cell != ' ' and cell != '#' and cell != '@') {
            shared_ptr<Monster> mons = NULL;
            for (shared_ptr<Monster> m : * _game -> getMonstersList()) {
                if (m -> getSymbol() == cell and mons == NULL) {
                    mons = m;
                }
            }
            _game -> setState(_game -> getFightState());
            _game -> action(mons);
        }
    }
}
