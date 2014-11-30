#include "FightState.hpp"

/**
 * \fn FightState::FightState(Game* game) : GameState(game)
 * \brief Constructeur d'etat
 *
 * \param Game* game
 * \return nouvelle instance de fightState
 *
 * Crée un état de combat, avec un attribut Game.
 */ 
FightState::FightState(Game* game) : GameState(game)
{}


/**
 * \fn FightState::action(shared_ptr<Monster> monster)
 * \brief Lance un combat
 *
 * \param shared_ptr<Monster> monster
 * \return void
 *
 * Lance un combat conte le monstre en paramètre. Changement d'état à la fin.
 */ 
void FightState::action(shared_ptr<Monster> monster)
{   
	bool endGame = false;
    bool fightEnd = false;
    bool flee = false;
	int choice;
	int defense = _game -> getCharacter() -> def();
	_game -> getScreen() -> updateMonsterInfo(monster);

	while(!fightEnd) {
		_game -> getScreen() -> mvprintTxt(2, 1, "Combat contre: "+monster -> name());
		choice = _game -> getScreen() -> chooseAction();
		switch(choice){
			case 1: //attack
				_game -> getScreen() -> mvprintTxt(2, 2, "Vous attaquez le monstre: "+monster -> name());
				this_thread::sleep_for(chrono::milliseconds(500));
				if (_game -> getCharacter() -> hitFoe(monster)) {
					_game -> getScreen() -> mvprintTxt(2, 3, "L'attaque inflige");
					_game -> getScreen() -> mvprintTxt(22, 3, to_string(_game -> getCharacter() -> attackFoe(monster)));
					_game -> getScreen() -> mvprintTxt(26, 3, "points de dégats à l'adversaire!");					
					if (monster -> life() <= 0) {
						fightEnd = true;
						//loot if enemy's dead
					}
				} else {
					//Miss
					_game -> getScreen() -> mvprintTxt(2, 3, "Mais l'attaque échoue! ");
				}
				break;
			case 2:
				_game -> getScreen() -> mvprintTxt(2, 2, "Vous vous protégez! ");
				_game -> getScreen() -> mvprintTxt(2, 3, "Défense améliorée pendant un tour." );
				_game -> getScreen() -> mvprintTxt(2, 4, "Vous récouvrez un peu de votre vitalité." );
				_game -> getCharacter() -> setDef(1.25 * _game -> getCharacter() -> def() + 0.25 * _game -> getCharacter() -> getEquipementDef());
				_game -> getCharacter() -> heal();
				break;
				
			case 3:
				_game -> getScreen() -> mvprintTxt(2, 2, "Vous essayez de prendre la fuite, lâche ! ");
				if (monster -> isBoss()) {
					_game -> getScreen() -> mvprintTxt(2, 3, "Vous ne pouvez fuir contre un boss ! ");
				} else {
					if (_game -> getCharacter() -> fleeFoe(monster)) {
						_game -> getScreen() -> mvprintTxt(2, 3, "Vous réussissez à vous enfuir ! ");
						_game -> getMonstersList() -> push_back(monster);
						fightEnd = true;
						flee = true;
					} else {
						_game -> getScreen() -> mvprintTxt(2, 3, "L'ennemi vous rattrape!");
					}
				}
				break;
		};
		
		_game -> getScreen() -> updateCharacterInfo(_game -> getCharacter());
		_game -> getScreen() -> updateMonsterInfo(monster);
		this_thread::sleep_for(chrono::milliseconds(500));		
		
		if (!fightEnd and _game -> getCharacter() -> life() >= 0) {
			/* Enemi's turn */
			_game -> getScreen() -> mvprintTxt(2, 5, "Tour de l'ennemi") ;
			_game -> getScreen() -> mvprintTxt(2, 6, "L'ennemi vous attaque! ");
			this_thread::sleep_for(chrono::milliseconds(500));
			if (monster -> hitFoe(_game -> getCharacter())) {
				/* Damages on the Character */
				_game -> getScreen() -> mvprintTxt(2, 7, "Vous perdez "+ to_string(monster -> attackFoe(_game -> getCharacter()))+ " points de vie!" );
				_game -> getScreen() -> updateCharacterInfo(_game -> getCharacter());
				if (_game -> getCharacter() -> life() <= 0) {
					/* Death of the Character */
					fightEnd = true;
					_game->setState(_game->getEndGameState());
					_game -> getScreen() -> clearTxt();
					_game -> getScreen() -> mvprintTxt(27, 2, "Vous êtes mort..." );
					endGame = true;
				}
			} else {
				/* The monster miss its attack */
				_game -> getScreen() -> mvprintTxt(2, 7, "Mais son attaque échoue !" );
			} 
    		this_thread::sleep_for(chrono::milliseconds(500));
		} else if (! flee) {
			/* The fight is over and the player didn't ran away */
			_game -> getScreen() -> mvprintTxt(2, 5, "Victoire !") ;
			_game -> getScreen() -> mvprintTxt(2, 6, "Vous récupérez un peu de santé. ");
			if (monster -> isBoss() and !monster -> isFinalBoss()) {
				/* He defeated a normal boss -> New level */
				_game -> setLevel(_game -> getLevel() + 1);
				_game -> generateMap();
			}
			if (monster -> isFinalBoss()) {
				/* He defeated the final boss -> The game is over */
				_game -> setState(_game -> getEndGameState());
				endGame = true;
			} else {
				/* If its not the final boss : Loot distribution */
				_game -> setState(_game -> getLootState());
			}
		} else {
			/* The fight is over because the player ran away */
		    _game -> setState(_game -> getMoveState());
		}
		_game -> getCharacter() -> setDef(defense); //Defense reinitialisation. Avoid infinite defense after protecting itself
	    _game -> getScreen() -> clearTxt(); //Text Window clearence
	}
	
	if (endGame) {
		_game -> action((_game -> getCharacter() -> life() > 0 )); //The game is over. The condition tell if the player is dead or not
	} else {	
    	_game -> action(monster); //Game continue, on the map or in the loot screen. Depending of player's actions
    }

}
