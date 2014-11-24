#include "FightState.hpp"

FightState::FightState(Game* game) : GameState(game)
{}

void FightState::action(shared_ptr<Monster> monster)
{   
    bool fightEnd = false;
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
						/* loot */
					}
				} else {
					_game -> getScreen() -> mvprintTxt(2, 3, "Mais l'attaque échoue! ");
				}
				break;
			case 2:
				_game -> getScreen() -> mvprintTxt(2, 2, "Vous vous protégez! ");
				_game -> getScreen() -> mvprintTxt(2, 3, "Défense améliorée pendant un tour." );
				_game -> getScreen() -> mvprintTxt(2, 4, "Vous récouvrez un peu de votre vitalité." );
				_game -> getCharacter() -> setDef(_game -> getCharacter() -> defendFromFoe());
				_game -> getCharacter() -> heal();
				break;
				
			case 3:
				_game -> getScreen() -> mvprintTxt(2, 2, "Vous essayez de prendre la fuite, lâche ! ");
				
				if (_game -> getCharacter() -> fleeFoe(monster)) {
					_game -> getScreen() -> mvprintTxt(2, 3, "Vous réussissez à vous enfuir ! ");
					fightEnd = true;
				} else {
					_game -> getScreen() -> mvprintTxt(2, 3, "L'ennemi vous rattrape!");
				}
				break;
		};
		
		_game -> getScreen() -> updateCharacterInfo(_game -> getCharacter());
		_game -> getScreen() -> updateMonsterInfo(monster);
		this_thread::sleep_for(chrono::milliseconds(500));		
		if (!fightEnd and _game -> getCharacter() -> life() >= 0) {
			_game -> getScreen() -> mvprintTxt(2, 5, "Tour de l'ennemi") ;
			_game -> getScreen() -> mvprintTxt(2, 6, "L'ennemi vous attaque! ");
			if (monster -> hitFoe(_game -> getCharacter())) {
				_game -> getScreen() -> mvprintTxt(2, 7, "Vous perdez "+ to_string(monster -> attackFoe(_game -> getCharacter()))+ " points de vie!" );
				_game -> getScreen() -> updateCharacterInfo(_game -> getCharacter());
				if (_game -> getCharacter() -> life() <= 0) {
					fightEnd = true;
					/* SWITCH TO DEATH STATE */
					_game -> getScreen() -> clearTxt();
					_game -> getScreen() -> mvprintTxt(27, 2, "Vous êtes mort..." );
					getch();
				}
			} else {
				_game -> getScreen() -> mvprintTxt(2, 7, "Mais son attaque échoue !" );
			} 
		} else {
			_game -> getScreen() -> mvprintTxt(2, 5, "Victoire !") ;
			_game -> getScreen() -> mvprintTxt(2, 6, "Vous récupérez un peu de santé. ");

			_game -> setState(_game -> getMoveState());
			
			/* AJOUTER LOOT STATE ICI */
			/* AJOUTER LOOT STATE ICI */
			/* AJOUTER LOOT STATE ICI */
			/* AJOUTER LOOT STATE ICI */
		}
		_game -> getCharacter() -> setDef(defense);
		getch();
		_game -> getScreen() -> clearTxt();
	}

//	game->setState(game->getLootState);
//	game->setState(game->getDeadState);
}
