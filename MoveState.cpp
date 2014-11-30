#include "MoveState.hpp"

/**
 * \fn MoveState::MoveState(Game* game) : GameState(game)
 * \brief Instancie l'état de déplacement
 *
 * \param void
 * \return void
 *
 */ 
MoveState::MoveState(Game* game) : GameState(game)
{}

/**
 * \fn void MoveState::action()
 * \brief Déplace le personnage de la classe cliente
 *
 * \param void
 * \return void
 *
 * On récupère les entrées clavier, modifie le personnage en conséquence, et met à jour l'affichage graphique.
 */ 
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

/**
 * \fn void MoveState::action(shared_ptr<Monster> mon)
 * \brief Appelle la méthode Action(void)
 *
 * \param shared_ptr<Monster> mon
 * \return void
 *
 * Si jamais on fuit en combat, on appelle la méthode action(shared_ptr<Monster>), mais on ne veut pas répartir le butin, \n juste retourner a l'écran de déplacements. D'où ce subterfuge
 */ 
void MoveState::action(shared_ptr<Monster> mon) {
    action();
}
