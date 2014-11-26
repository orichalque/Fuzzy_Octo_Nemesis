#include "LootState.hpp"

LootState::LootState(Game* game) : GameState(game)
{}

void LootState::action(shared_ptr<Monster> monster)
{
	_game -> getScreen() -> clearTxt();
	vector< shared_ptr<Equipement> > loots;
    shared_ptr<Equipement> equipement;
    int ch; int x(18);
	for (int i : monster -> getLootList()) {
		if (monster -> getLootPb() >= rand()%100) {
			loots.push_back(_game -> getEquipementFactory() -> create(i));
		}
	}	
	
	while (not loots.empty()) {
   	    _game -> getScreen() -> clearTxt();
	    equipement = loots.back();
	    _game -> getScreen() -> mvprintTxt(2, 2, "Vous ramassez l'équipement: "+ equipement -> getName()+" !") ;
        _game -> getScreen() -> getNewEquipement(equipement);
        if (equipement -> isWeapon()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getWeapon());
            if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setWeapon(equipement);
            }
        } else 
        if (equipement -> isHelmet()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getHelmet());
             if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setHelmet(equipement);
            }
        } else 
        if (equipement -> isArmor()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getArmor());
             if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setArmor(equipement);
            }
        } else 
        if (equipement -> isShield()) {
            _game -> getScreen() -> getMyEquipement(_game -> getCharacter() -> getShield());
             if (_game -> getScreen() -> equip()) {
                _game -> getCharacter() -> setShield(equipement);
            }
        }
        
		_game -> getScreen() -> updateCharacterInfo(_game -> getCharacter());
    	this_thread::sleep_for(chrono::milliseconds(300));		
	    loots.pop_back();
	}
	
	_game -> getScreen() -> mvprintTxt(45, 9, "Appuyez sur entrée") ;
	while ((ch=getch())!=10) {
	    
	}
	_game -> getScreen() -> clearTxt();
	_game -> setState(_game -> getMoveState());
	
}
